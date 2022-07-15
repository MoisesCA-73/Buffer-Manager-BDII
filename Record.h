#ifndef _RECORD_H_
#define _RECORD_H_

#include <bits/stdc++.h>

class Record
{
private:
    int movie_id;
    int user_id;
    int rating;
    std::string time;
public:
    Record(int movie_id, int user_id, int rating, std::string time);

};

#endif