#ifndef _FRAME_H_
#define _FRAME_H_

#include "Page.h"
class Frame
{
public:
    Page * page;
    int pin_counter;
    bool dirty_flag;

};


#endif
