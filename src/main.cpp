#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <queue>
#include <sys/stat.h>
#include <Status.hpp>
#include <File.hpp>

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

    // 1行の文字列を保持する変数。文字数は可変するのでstd::stringで取得
    std::string line_str;

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
            // 1行の文字列を取得
            getline(file, line_str);

            std::cmatch cmatch;

            // メモリ確保（regex_searchはstd::stringを扱えないのでcharに変換）
            int buf_size = line_str.size() + 1;
            char *line_chars = new char[buf_size];

            // std::stringを*chareに変換（複数回参照するため、std::string.s_strは使わない）
            std::char_traits<char>::copy(
                line_chars, line_str.c_str(), buf_size);

            if (std::regex_search(line_chars, cmatch, std::regex("^[<]{7}")))
            {
                status.conflict.detection();
                file_info->add_conflict_head(lineCount);
            } else 
            if (std::regex_search(line_chars, cmatch, std::regex("^[=]{7}")))
            {
                status.conflict.detection();
                file_info->add_conflict_boundary(lineCount);
            } else 
            if (std::regex_search(line_chars, cmatch, std::regex("^[>]{7}")))
            {
                status.conflict.detection();
                file_info->add_conflict_tail(lineCount);
            }
            // メモリ解放
            delete[] line_chars;
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

    return status.conflicts.status() ? EXIT_FAILURE : EXIT_SUCCESS;
}




