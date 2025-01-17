// library.cpp
#include "library.h"
#include <iostream>
#include <algorithm>

Library::Library() {
    loadData();
}

// void Library::addBook(const Book& book) {
//     books.push_back(book);
//     undoStack.push_back({0, std::to_string(book.id)});
//     saveData();
// }

// void Library::removeBook(int id) {
//     auto it = std::find_if(books.begin(), books.end(), [id](const Book& b) { return b.id == id; });
//     if (it != books.end()) {
//         undoStack.push_back({1, std::to_string(id)});
//         books.erase(it);
//         saveData();
//     }
// }

// void Library::updateBook(int id, const Book& updatedBook) {
//     auto it = std::find_if(books.begin(), books.end(), [id](const Book& b) { return b.id == id; });
//     if (it != books.end()) {
//         undoStack.push_back({2, std::to_string(id)});
//         *it = updatedBook;
//         saveData();
//     }
// }

// std::vector<Book> Library::searchBooks(const std::string& criteria) {
//     std::vector<Book> results;
//     for (const auto& book : books) {
//         if (book.title.find(criteria) != std::string::npos ||
//             book.author.find(criteria) != std::string::npos ||
//             book.isbn.find(criteria) != std::string::npos) {
//             results.push_back(book);
//         }
//     }
//     return results;
// }

// void Library::displayBooks() {
//     for (const auto& book : books) {
//         std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
//                   << ", ISBN: " << book.isbn << ", Quantity: " << book.quantity << std::endl;
//     }
// }

// void Library::sortBooks(const std::string& criteria) {
//     if (criteria == "title") {
//         std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
//             return a.title < b.title;
//         });
//     } else if (criteria == "author") {
//         std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
//             return a.author < b.author;
//         });
//     } else if (criteria == "year") {
//         std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
//             return a.year < b.year;
//         });
//     }
// }

// void Library::addUser(const User& user) {
//     users.push_back(user);
//     saveData();
// }

// void Library::borrowBook(int userId, int bookId) {
//     auto userIt = std::find_if(users.begin(), users.end(), [userId](const User& u) { return u.id == userId; });
//     auto bookIt = std::find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.id == bookId; });

//     if (userIt != users.end() && bookIt != books.end() && bookIt->quantity > 0) {
//         userIt->borrowedBooks.push_back(*bookIt);
//         bookIt->quantity--;
//         bookIt->borrowed = true;
//         saveData();
//     }
// }

// void Library::returnBook(int userId, int bookId) {
//     auto userIt = std::find_if(users.begin(), users.end(), [userId](const User& u) { return u.id == userId; });
//     auto bookIt = std::find_if(books.begin(), books.end(), [bookId](const Book& b) { return b.id == bookId; });

//     if (userIt != users.end() && bookIt != books.end()) {
//         auto borrowedBookIt = std::find_if(userIt->borrowedBooks.begin(), userIt->borrowedBooks.end(),
//                                            [bookId](const Book& b) { return b.id == bookId; });
//         if (borrowedBookIt != userIt->borrowedBooks.end()) {
//             userIt->borrowedBooks.erase(borrowedBookIt);
//             bookIt->quantity++;
//             bookIt->borrowed = false;
//             saveData();
//         }
//     }
// }

// std::vector<Book> Library::getOverdueBooks() {
//     std::vector<Book> overdueBooks;
//     // Implement overdue book logic here
//     // For simplicity, let's assume all borrowed books are overdue
//     for (const auto& user : users) {
//         for (const auto& book : user.borrowedBooks) {
//             overdueBooks.push_back(book);
//         }
//     }
//     return overdueBooks;
// }

// void Library::generateInventoryReport() {
//     // Implementation moved to inventory_report.cpp
// }

// std::vector<Book> Library::getRecommendations(int userId) {
//     // Implementation moved to recommendations.cpp
//     return std::vector<Book>();
// }

// void Library::undo() {
//     // Implementation moved to undo_functionality.cpp
// }

// void Library::loadData() {
//     // Implementation moved to file_handling.cpp
// }

// void Library::saveData() {
//     // Implementation moved to file_handling.cpp
// }