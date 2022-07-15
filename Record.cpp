#include "Record.h"

Record::Record(int movie_id, int user_id, int rating, std::string time)
{
    this->movie_id = movie_id;
    this->user_id = user_id;
    this->rating = rating;
    this->time = time;
}