#include <ConflictMarker.hpp>

const int ConflictMarker::HEAD     = 0;
const int ConflictMarker::BOUNDARY = 1;
const int ConflictMarker::TAIL     = 2;

ConflictMarker::ConflictMarker(int type, int line)
{
    type = type;
    line = line;
}

int ConflictMarker::get_type(){
    return type;
}

int ConflictMarker::get_line(){
    return line;
}
