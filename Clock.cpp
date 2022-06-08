#include "Clock.h"
std::list<Frame>::iterator circular_next(std::list<Frame> &l, std::list<Frame>::iterator &it)
{
    return std::next(it) == l.end() ? l.begin() : std::next(it);
}

Frame * Clock::new_page_frame()
{
    std::list<Frame>::iterator it1 = frames.begin();
    if ((*it1).page == new_page)
    for (; it1 != frames.begin(); it1 = circular_next(frames,it1))
    {
        if (*it1)
    }

    std::list<Frame>::iterator it = frames.begin();

    for (; (*it).dirty_flag == false; it = circular_next(frames,it))
    {
        (*it).dirty_flag = true;
    }
    
    
}
