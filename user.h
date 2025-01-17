// user.h
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "book.h"

struct User {
    int id;
    std::string name;
    std::string email;
    std::vector<Book> borrowedBooks;
};

#endif