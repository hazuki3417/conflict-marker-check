#pragma once
#include <string>

class ConflictMarker
{

private:
    int type;
    int line;

public:
    static const int HEAD_ID;
    static const int BOUNDARY_ID;
    static const int TAIL_ID;

    static const std::string HEAD_NAME;
    static const std::string BOUNDARY_NAME;
    static const std::string TAIL_NAME;

    ConflictMarker(int type, int line);
    int get_type();
    int get_line();
};
