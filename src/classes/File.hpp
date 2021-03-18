#pragma once
#include <queue>
#include <string>
#include <ConflictMarker.hpp>

class File
{
private:
    std::string file_path;

public:
    std::queue<ConflictMarker> markers;
    File(std::string file_path);
    std::string get_file_path();
    void add_conflict_head(int line);
    void add_conflict_boundary(int line);
    void add_conflict_tail(int line);
};
