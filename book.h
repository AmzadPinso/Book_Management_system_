// book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    int id;
    std::string title;
    std::string author;
    std::string publisher;
    std::string isbn;
    int quantity;
    int year;
    bool borrowed;
};

#endif