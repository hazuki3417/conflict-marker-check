#pragma once

class Conflict
{
private:
    bool state;

public:
    Conflict();
    bool status();
    void detection();
    void clear();
};
