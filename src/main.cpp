#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <queue>
#include <sys/stat.h>
#include <MessageBase.hpp>
#include <Status.hpp>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

/**
 * @param argc 引数の数
 * @param argv 引数の文字列
 */
int main(int argc, const char *argv[])
{
    Status status = *(new Status());
    // NOTE: argv[0] は自身のコマンド名が入っている
    const int arg_start_index = 1;

    /*
     * バリデーション処理（引数）
     */
    if (argc <= arg_start_index)
    {
        std::cout << "Invalid argument." << std::endl;
        return -1;
    }

    for (int i = arg_start_index; i < argc; i++)
    {
        // ハイフンが1~2個戦闘についていたらオプション指定の処理（予定）

        struct stat st;
        std::string path = argv[i];

        /*
         * バリデーション処理（パス）
         */

        bool notFound = stat(argv[i], &st) != 0;
        if (notFound)
        {
            std::cout << "The file does not exist. " << path << std::endl;
            continue;
        }
        bool isDirectory = (st.st_mode & S_IFMT) == S_IFDIR;
        if (isDirectory)
        {
            std::cout << "Directory path cannot be specified. " << path << std::endl;
        }

        std::ifstream file(path);

        if (file.fail())
        {
            std::cout << "Failed to open file. " << path << std::endl;
            continue;
        }

        /*
         * メイン処理
         */

        // バッファーサイズ
        int buf_size = 1024;
        char str[buf_size];

        int lineCount = 0;
        std::queue<MessageBase> queue;
        while (!file.eof())
        {
            lineCount++;
            file.getline(str, buf_size);
            std::cmatch cmatch;
            
            if (std::regex_search(str, cmatch, std::regex("^[<]{7}")))
            {
                status.conflict.detection();
                MessageBase *mb = new MessageBase(lineCount);
                queue.push(*mb);
                std::cout << GRN << str << NC << std::endl;
                continue;
            }
            if (std::regex_search(str, cmatch, std::regex("^[=]{7}")))
            {
                status.conflict.detection();
                MessageBase *mb = new MessageBase(lineCount);
                queue.push(*mb);
                std::cout << RED << str << NC << std::endl;
                continue;
            }
            if (std::regex_search(str, cmatch, std::regex("^[>]{7}")))
            {
                status.conflict.detection();
                MessageBase *mb = new MessageBase(lineCount);
                queue.push(*mb);
                std::cout << CYN << str << NC << std::endl;
                continue;
            }
            // std::cout << str << std::endl;
        }

        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            std::cout << queue.front().getMessage() << std::endl;
            queue.pop();
        }
    }

    /**
     * conflictマーカー
     * 見つからない = 0（成功）
     * 見つかった　 = 1（失敗）
     * それ以外　　= -1
     */
    return status.conflict.status() ? 1 : 0;
}




