#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "Frame.h"
#include "FrameClock.h"
#include <vector>
#include <list>
class Clock
{
private:
    std::list<FrameClock>::iterator clock_handle;
    std::list<FrameClock> frame_clock_list;
    int misses;
    int hits;
public:
    Clock(int buf_size);
    Frame * new_page_frame();
    void move_handle();
    void use_ref(FrameClock *);
    void evict_page();
    void replace_page(Page * page_to_memory);
    void add_page(Page * page_to_memory);
    void page_request(Page * page_to_memory);


    void print_buf_pages();

    int get_misses();
    int get_hits();

};

#endif