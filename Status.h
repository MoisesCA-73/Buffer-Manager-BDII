#ifndef _STATUS_H_
#define _STATUS_H_

#include <string>

class Status
{
private:
    bool correct;
    std::string message;
public:
    Status(bool,std::string);
};

#endif