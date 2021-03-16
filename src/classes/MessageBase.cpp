#include <MessageBase.hpp>

MessageBase::MessageBase(int lineNumber)
{
    message = "conflict marker detection: line " + std::to_string(lineNumber);
}

// conflict marker detection: head
// conflict marker detection: boundary
// conflict marker detection: tail

std::string MessageBase::getMessage()
{
    return message;
}
