#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <queue>
#include <sys/stat.h>
#include <Status.hpp>
#include <File.hpp>

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

    std::queue<std::string> paths;

    /*
     * バリデーション処理（パス）
     */
    for (int i = arg_start_index; i < argc; i++)
    {
        // ハイフンが1~2個戦闘についていたらオプション指定の処理（予定）

        struct stat st;
        std::string path = argv[i];

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

        paths.push(path);
    }

    /*
     * メイン処理
     */
    std::queue<File> files;

    // バッファーサイズ
    int buf_size = 1024;
    char str[buf_size];

    while(!paths.empty())
    {
        std::string path = paths.front();
        std::ifstream file(path);
        int lineCount = 0;

        File *file_info = new File(path);

        // find conflict markers
        while (!file.eof())
        {
            lineCount++;
            file.getline(str, buf_size);
            std::cmatch cmatch;

            if (std::regex_search(str, cmatch, std::regex("^[<]{7}")))
            {
                status.conflict.detection();
                file_info->add_conflict_head(lineCount);
                // std::cout << GRN << str << NC << std::endl;
                continue;
            }
            if (std::regex_search(str, cmatch, std::regex("^[=]{7}")))
            {
                status.conflict.detection();
                file_info->add_conflict_boundary(lineCount);
                // std::cout << RED << str << NC << std::endl;
                continue;
            }
            if (std::regex_search(str, cmatch, std::regex("^[>]{7}")))
            {
                status.conflict.detection();
                file_info->add_conflict_tail(lineCount);
                // std::cout << CYN << str << NC << std::endl;
                continue;
            }
        }

        if (status.conflict.status())
        {
            status.conflicts.detection();
            files.push(*file_info);
        }
        status.conflict.clear();

        delete(file_info);

        paths.pop();
    }

    /*
     * 出力処理
     */
    while (!files.empty())
    {
        File file = files.front();
        std::cout << "conflict marker detection: " << file.get_file_path() << std::endl;

        while (!file.markers.empty())
        {
            ConflictMarker marker = file.markers.front();
            file.markers.pop();

            if (marker.get_type() == ConflictMarker::HEAD_ID){
                std::cout << "line: " << marker.get_line() << " marker type: " << ConflictMarker::HEAD_NAME << std::endl;
                continue;
            }

            if (marker.get_type() == ConflictMarker::BOUNDARY_ID){
                std::cout << "line: " << marker.get_line() << " marker type: " << ConflictMarker::BOUNDARY_NAME << std::endl;
                continue;
            }

            if (marker.get_type() == ConflictMarker::TAIL_ID){
                std::cout << "line: " << marker.get_line() << " marker type: " << ConflictMarker::TAIL_NAME << std::endl;
                continue;
            }
        }
        files.pop();
    }
    /**
     * conflictマーカー
     * 見つからない = 0（成功）
     * 見つかった　 = 1（失敗）
     * それ以外　　= -1
     */
    return status.conflicts.status() ? 1 : 0;
}




