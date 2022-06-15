#ifndef _FRAME_CLOCK_H_
#define _FRAME_CLOCK_H_

#include "Frame.h"

class FrameClock
{
public:
    Frame * frame;
    bool flag; // ref_bit
    int pin_counter;
    bool dirty_flag;
    int frame_id;
public:
    FrameClock(int frame_id, Frame *);
    FrameClock();
};

#endif // _FRAME_CLOCK_H_