// library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <unordered_map>
#include "book.h"
#include "user.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<std::pair<int, std::string>> undoStack;

public:
    Library();
    void loadData();
    void saveData();

    // Book management
    void addBook(const Book& book);
    void removeBook(int id);
    void updateBook(int id, const Book& updatedBook);
    std::vector<Book> searchBooks(const std::string& criteria);
    void displayBooks();
    void sortBooks(const std::string& criteria);

    // User management
    void addUser(const User& user);
    void borrowBook(int userId, int bookId);
    void returnBook(int userId, int bookId);
    std::vector<Book> getOverdueBooks();

    // Additional functionality
    void generateInventoryReport();
    std::vector<Book> getRecommendations(int userId);
    void undo();
};

#endif