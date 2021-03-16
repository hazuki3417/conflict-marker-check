#include <Status.hpp>

Status::Status()
{
    conflict = *(new Conflict());
}
