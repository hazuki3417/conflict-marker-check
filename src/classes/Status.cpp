#include <Status.hpp>

Status::Status()
{
    this->conflict = *(new Conflict());
    this->conflicts = *(new Conflict());
}
