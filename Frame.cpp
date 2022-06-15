#include "Frame.h"

Frame::Frame()
{
    this->page = nullptr;
    // this->pin_counter = 0;
    // this->dirty_flag = false;
}
Frame::Frame(Page * page)
{
    this->page = page;
    // this->pin_counter = 1;
    // this->dirty_flag = false;
}