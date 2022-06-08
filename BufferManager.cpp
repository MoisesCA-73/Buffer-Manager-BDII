#include "BufferManager.h"

BufferManager::BufferManager(int bufsize, Replacer * replacer = 0)
{
    this->bufsize = bufsize;

}
unsigned int BufferManager::get_num_buffers() const
{
    return this->bufsize;

}
unsigned int BufferManager::get_num_unpinned_buffers()
{
    unsigned int counter {0};
    for (int i = 0; i < bufsize; i++)
    {
        if (buffer_pool[i].pin_counter == 0) counter++;
    }
    return counter;
}

Status BufferManager::pin_page(int page_id_in_a_db, Page *& page, int empty_page = 0)
{
    for (int i = 0; i < bufsize; i++)
    {
        if (buffer_pool[i].page != nullptr)
        {
            if (buffer_pool[i].page == page)
            {
                buffer_pool[i].pin_counter++;
                Status stat(true,"Pin counter has been increased.\n");
                return stat;
            }
        }
    }
    return Status(false,"Error: PageID can't be pinned because it doesn't exist in memory.\n");

}
Status BufferManager::unpin_page(int global_page_id_in_a_db, Page *& page, int empty_page = 0)
{
    for (int i = 0; i < bufsize; i++)
    {
        if (buffer_pool[i].page != nullptr)
        {
            if (buffer_pool[i].page == page)
            {
                buffer_pool[i].pin_counter--;
                if (buffer_pool[i].pin_counter == 0)
                    replacement_candidates.push_back(i); 
                Status stat(true,"Pin counter has been decreased.\n");
                return stat;
            }
        }
    }
    return Status(false,"Error: PageID can't be pinned because it doesn't exist in memory.\n");

}
Status BufferManager::new_page(int & first_page_id, Page *& first_page, int how_many = 1)
{
    for (int i = 0; i < bufsize; i++)
    {
        if (buffer_pool[i].page == nullptr)
        {
            buffer_pool[i].page = first_page;
            pin_page(1, first_page);
            return Status(true,"New Page added succesfully to memory");
        }
    }
    if (get_num_unpinned_buffers() > 0)
    {
        for (int i = 0; i < bufsize; i++)
        {
            if (buffer_pool[i].pin_counter == 0)
            {
                free_page(i);
                buffer_pool[i].page = first_page;
                pin_page(1, first_page);
                return Status(true,"New Page added succesfully to memory, but had to deallocate another one.\n");
            }
        }
    }
    int fewer_pin_count {INT32_MAX};
    int fewer_pin_index {0};
    for (int i = 0; i < bufsize; i++)
    {
        if (buffer_pool[i].pin_counter < fewer_pin_count)
        {
            fewer_pin_count = buffer_pool[i].pin_counter;
            fewer_pin_index = i;
        }
    }
    free_page(fewer_pin_index);
    buffer_pool[fewer_pin_index].page = first_page;
    pin_page(1, first_page);
    return Status(true,"New Page added succesfully to memory, but had to deallocate another one.\n");
    
}
Status BufferManager::free_page(int global_page_id)
{
    for (int i = 0; i < bufsize; i++)
    {
        if (buffer_pool[i].page != nullptr)
        {
            if (buffer_pool[i].page->get_page_id_in_disk() == global_page_id)
            {
                buffer_pool[i].page == nullptr;
                Status stat(true,"Memory has been freed.\n");
                return stat;
            }
        }
    }
    return Status(false,"Error: PageID can't be freed beacause it doesn't exist in memory.\n");
}
Status BufferManager::flush_page(int page_id)
{

}