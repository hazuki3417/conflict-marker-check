#pragma once
#include <string>
#include <queue>
#include <ConflictMarker.hpp>

class File
{
private:
    std::string fileName;
    std::queue<ConflictMarker> conflictMarkers;

public:
    File(std::string fileName);
    void addConflictHead(int line);
    void addConflictBoundary(int line);
    void addConflictTail(int line);
};
