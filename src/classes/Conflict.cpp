#include <Conflict.hpp>

bool state;

Conflict::Conflict() {
    state = false;
}

bool Conflict::status()
{
    return state;
}

void Conflict::detection()
{
    state = true;
}

void Conflict::clear()
{
    state = false;
}

