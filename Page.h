#ifndef _PAGE_H_
#define _PAGE_H_

#include <vector>
#include "Record.h"

class Page
{
public: 
    char page_id_in_disk;
    std::vector<Record *> records_in_page;
public:
    Page(char page_id_in_disk);
    char get_page_id_in_disk();
    
};



#endif