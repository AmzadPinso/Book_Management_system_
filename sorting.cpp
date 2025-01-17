// sorting.cpp
#include "library.h"
#include <algorithm>

void Library::sortBooks(const std::string& criteria) {
    if (criteria == "title") {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.title < b.title;
        });
    } else if (criteria == "author") {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.author < b.author;
        });
    } else if (criteria == "year") {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.year < b.year;
        });
    }
}