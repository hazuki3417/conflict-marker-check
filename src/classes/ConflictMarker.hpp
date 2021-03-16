#pragma once
#include <string>

class ConflictMarker
{

private:
    int type;
    int line;

public:
    static const int HEAD;
    static const int BOUNDARY;
    static const int TAIL;

    ConflictMarker(int type, int line);
    int get_type();
    int get_line();
};
