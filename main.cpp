#include <iostream>
#include <fstream>
#include "Clock.h"

#define PAGE_RECORD_SIZE 8
int main()
{
    std::ifstream file;
    file.open("db.txt");
    std::vector<Page *> pages_in_disk {};
    int id_page = 65;
    int x = 0;
    while(!file.eof())
    {
        Page * new_page = new Page(id_page); 
        while(new_page->records_in_page.size() < PAGE_RECORD_SIZE && !file.eof())
        {
            int m_id, u_id, rating;
            std::string time;
            file >> m_id >> u_id >> rating >> time;
            new_page->records_in_page.insert(new_page->records_in_page.end(),new Record(m_id,u_id,rating,time));
        }
        pages_in_disk.insert(pages_in_disk.end(), new_page);
        id_page++;
    }

    int buf_size;
    std::cin >> buf_size;
    Clock c(buf_size);

    std::string page_sequence {};
    std::cin >> page_sequence;

    for (int j = 0; j < page_sequence.size(); j++)
    {
        for (int i = 0; i < pages_in_disk.size(); i++)
        {
            if (pages_in_disk[i]->get_page_id_in_disk() == page_sequence[j] )
            {
                c.page_request(pages_in_disk[i]);
                break;
            }
        }
    }


/*
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

*/
    std::cout << "Resultado final:\n";
    c.print_buf_pages();
}