#include <File.hpp>
#include <string>
#include <queue>
#include <iostream>
#include <ConflictMarker.hpp>

File::File(std::string file_path)
{
    this->file_path = file_path;
}

std::string File::get_file_path()
{
    return this->file_path;
}

void File::add_conflict_head(int line)
{
    this->markers.push(*new ConflictMarker(ConflictMarker::HEAD_ID, line));
}

void File::add_conflict_boundary(int line)
{
    this->markers.push(*new ConflictMarker(ConflictMarker::BOUNDARY_ID, line));
}

void File::add_conflict_tail(int line)
{
    this->markers.push(*new ConflictMarker(ConflictMarker::TAIL_ID, line));
}
