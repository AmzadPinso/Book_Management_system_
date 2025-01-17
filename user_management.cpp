// user_management.cpp
#include "library.h"
#include <algorithm>

void Library::addUser(const User& user) {
    users.push_back(user);
    saveData();
}

void Library::borrowBook(int userId, int bookId) {
    auto userIt = std::find_if(users.begin(), users.end(), [userId](const User& u) { return u.id == userId; });
    auto bookIt = std::find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.id == bookId; });

    if (userIt != users.end() && bookIt != books.end() && bookIt->quantity > 0) {
        userIt->borrowedBooks.push_back(*bookIt);
        bookIt->quantity--;
        bookIt->borrowed = true;
        saveData();
    }
}

void Library::returnBook(int userId, int bookId) {
    auto userIt = std::find_if(users.begin(), users.end(), [userId](const User& u) { return u.id == userId; });
    auto bookIt = std::find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.id == bookId; });

    if (userIt != users.end() && bookIt != books.end()) {
        auto borrowedBookIt = std::find_if(userIt->borrowedBooks.begin(), userIt->borrowedBooks.end(),
                                           [bookId](const Book& b) { return b.id == bookId; });
        if (borrowedBookIt != userIt->borrowedBooks.end()) {
            userIt->borrowedBooks.erase(borrowedBookIt);
            bookIt->quantity++;
            bookIt->borrowed = false;
            saveData();
        }
    }
}

std::vector<Book> Library::getOverdueBooks() {
    std::vector<Book> overdueBooks;
    // Implement overdue book logic here
    // For simplicity, let's assume all borrowed books are overdue
    for (const auto& user : users) {
        for (const auto& book : user.borrowedBooks) {
            overdueBooks.push_back(book);
        }
    }
    return overdueBooks;
}