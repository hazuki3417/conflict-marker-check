#include <ConflictMarker.hpp>
#include <string>

const int ConflictMarker::HEAD_ID     = 0;
const int ConflictMarker::BOUNDARY_ID = 1;
const int ConflictMarker::TAIL_ID     = 2;

const std::string ConflictMarker::HEAD_NAME     = "head";
const std::string ConflictMarker::BOUNDARY_NAME = "boundary";
const std::string ConflictMarker::TAIL_NAME     = "tail";

ConflictMarker::ConflictMarker(int type, int line)
{
    this->type = type;
    this->line = line;
}

int ConflictMarker::get_type(){
    return this->type;
}

int ConflictMarker::get_line(){
    return this->line;
}
