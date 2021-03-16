#include <File.hpp>
#include <string>
#include <queue>
#include <ConflictMarker.hpp>

File::File(std::string fileName)
{
    fileName = fileName;
}

void File::addConflictHead(int line)
{
    conflictMarkers.push(*(new ConflictMarker(ConflictMarker::HEAD, line)));
}

void File::addConflictBoundary(int line)
{
    conflictMarkers.push(*(new ConflictMarker(ConflictMarker::HEAD, line)));
}

void File::addConflictTail(int line)
{
    conflictMarkers.push(*(new ConflictMarker(ConflictMarker::HEAD, line)));
}
