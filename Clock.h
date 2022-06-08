#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "Frame.h"
#include <vector>
#include <list>
class Clock
{
private:
    Frame * clock_handle;
    std::vector<bool> flag;
    std::list<Frame> frames;
public:
    Frame * new_page_frame();
     

};

#endif