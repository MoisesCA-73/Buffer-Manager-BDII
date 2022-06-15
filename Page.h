#ifndef _PAGE_H_
#define _PAGE_H_
class Page
{
private: 
    char page_id_in_disk;
public:
    Page(char page_id_in_disk);
    char get_page_id_in_disk();
    
};



#endif