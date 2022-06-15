#include <iostream>
#include "Clock.h"
int main()
{

    std::string page_sequence {};
    std::vector<Page *> pages_vector {};
    std::cin >> page_sequence;
    bool flag = false;
    for (int i = 0; i < page_sequence.size(); i++)
    {
        for (auto &x : pages_vector)
        {
            if (x->get_page_id_in_disk() == page_sequence[i]) 
            {
                flag = true;
                break;
            }
        }
        if (!flag) 
        {
            pages_vector.push_back(new Page(page_sequence[i]));
        }
        flag = false;

    }

    int buf_size;
    std::cin >> buf_size;
    Clock c(buf_size);


    for (int i = 0; i < page_sequence.size(); i++)
    {
        for (auto &x : pages_vector)
        {
            if (x->get_page_id_in_disk() == page_sequence[i])
            {
                c.page_request(x);
                break;
            }
        }
    }


    std::cout << "Resultado final:\n";
    c.print_buf_pages();
}