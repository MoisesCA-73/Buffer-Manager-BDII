#include "FrameClock.h"

FrameClock::FrameClock(int frame_id, Frame * frame)
{
    this->frame = frame;
    this->frame_id = frame_id;
    this->pin_counter = 1;
    this->dirty_flag = 0;
    this->flag = false;
}