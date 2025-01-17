// book_management.cpp
#include "library.h"
#include <algorithm>
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
    undoStack.push_back({0, std::to_string(book.id)});
    saveData();
}

void Library::removeBook(int id) {
    auto it = std::find_if(books.begin(), books.end(), [id](const Book& b) { return b.id == id; });
    if (it != books.end()) {
        undoStack.push_back({1, std::to_string(id)});
        books.erase(it);
        saveData();
    }
}

void Library::updateBook(int id, const Book& updatedBook) {
    auto it = std::find_if(books.begin(), books.end(), [id](const Book& b) { return b.id == id; });
    if (it != books.end()) {
        undoStack.push_back({2, std::to_string(id)});
        *it = updatedBook;
        saveData();
    }
}

std::vector<Book> Library::searchBooks(const std::string& criteria) {
    std::vector<Book> results;
    for (const auto& book : books) {
        if (book.title.find(criteria) != std::string::npos ||
            book.author.find(criteria) != std::string::npos ||
            book.isbn.find(criteria) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

void Library::displayBooks() {
    for (const auto& book : books) {
        std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                  << ", ISBN: " << book.isbn << ", Quantity: " << book.quantity << std::endl;
    }
}