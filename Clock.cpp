#include "Clock.h"
#include <iostream>
Clock::Clock(int buf_size)
{
    for (int i = 0; i < buf_size; i++)
    {
        this->frame_clock_list.push_back(FrameClock(i,new Frame()));
    }
    this->clock_handle = frame_clock_list.begin();
    this->misses = 0;
    this->hits = 0;

}
std::list<Frame>::iterator circular_next(std::list<Frame> &l, std::list<Frame>::iterator &it)
{
    return std::next(it) == l.end() ? l.begin() : std::next(it);
}

void Clock::move_handle()
{
    if (std::next(this->clock_handle) == this->frame_clock_list.end())
    {
        this->clock_handle = frame_clock_list.begin();
    }
    else  this->clock_handle = std::next(this->clock_handle);
}

Frame * Clock::new_page_frame()
{/*
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
    */
    
}

void Clock::use_ref(FrameClock * frame_to_set)
{
    if(frame_to_set->flag == 0) frame_to_set->flag = 1;
}
void Clock::page_request(Page * page_to_memory)
{
    std::cout << "Se solicita " << page_to_memory->get_page_id_in_disk() << ":\n";
     for (std::list<FrameClock>::iterator it = frame_clock_list.begin(); it != frame_clock_list.end(); ++it)
     {
        if ((*it).frame->page == page_to_memory)
        {
            use_ref(&(*it));
            std::cout << "Ya se encuentra en memoria\n";
            this->hits++;
            print_buf_pages();
            return;
        }
     }
     add_page(page_to_memory);
    
}

void Clock::add_page(Page * page_to_memory)
{
    std::cout << "Se anadira a memoria\n";
    if ((*this->clock_handle).flag == 0)
    {
        if ((*this->clock_handle).frame->page != nullptr) evict_page();
        (*this->clock_handle).frame = new Frame(page_to_memory);
        (*this->clock_handle).flag = 1;
        this->move_handle();
        std::cout << "Anadida a memoria con exito\n";
        this->misses++;
        this->print_buf_pages();
    }
    else
    {
        (*this->clock_handle).flag = 0;
        this->move_handle();
        // Repeat unitl finding a frame with flag 0
        add_page(page_to_memory);
    }
}

void Clock::evict_page()
{
    std::cout << "Se elimino la pagina " << (*this->clock_handle).frame->page->get_page_id_in_disk() << " de memoria\n";
    (*this->clock_handle).frame->page = nullptr;
}


void Clock::print_buf_pages()
{
    for (std::list<FrameClock>::iterator it = frame_clock_list.begin(); it != frame_clock_list.end(); ++it)
    {
        if (!(*it).frame->page) std::cout << "null\n";
        else std::cout << (*it).frame->page->get_page_id_in_disk() << '\n';
    }
}

int Clock::get_hits()
{
    return this->hits;
}

int Clock::get_misses()
{
    return this->misses;
}