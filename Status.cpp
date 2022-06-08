#include "Status.h"

Status::Status(bool _correct, std::string message)
{
    this->correct = _correct;
    this->message = message;
}