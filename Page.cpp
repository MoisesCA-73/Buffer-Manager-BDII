#include "Page.h"

Page::Page(char page_id_in_disk)
{
    this->page_id_in_disk = page_id_in_disk;
}
char Page::get_page_id_in_disk()
{
    return page_id_in_disk;
}