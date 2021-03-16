#include <string>

class MessageBase
{
private:
    std::string message;

public:
    MessageBase(int lineNumber);
    std::string getMessage();
};
