#ifndef _BUFFER_MANAGER_H_
#define _BUFFER_MANAGER_H_

#include <list>
#include <vector>
#include "Replacer.h"
#include "Status.h"
#include "Page.h"
#include "Frame.h"
class BufferManager
{
private:
    int bufsize; 
    std::list<int> replacement_candidates;
    std::vector<Frame> buffer_pool; 
public:
    BufferManager(int bufsize, Replacer * replacer = 0);
    unsigned int get_num_buffers() const;
    unsigned int get_num_unpinned_buffers();

    Status pin_page(int page_id_in_a_db, Page *& page, int empty_page = 0);
    Status unpin_page(int global_page_id_in_a_db, Page *& page, int empty_page = 0);
    Status new_page(int & first_page_id, Page *& first_page, int how_many = 1);
    Status free_page(int global_page_id);
    Status flush_page(int page_id);

};

#endif //_BUFFER_MANAGER_H_