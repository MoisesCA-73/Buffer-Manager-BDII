#ifndef _FRAME_H_
#define _FRAME_H_

#include "Page.h"
class Frame
{
public:
    Page * page;
public:
    Frame();
    Frame(Page * page);
};


#endif
