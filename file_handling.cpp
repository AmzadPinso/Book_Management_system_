// file_handling.cpp
#include "library.h"
#include <fstream>
#include <sstream>

void Library::loadData() {
    std::ifstream booksFile("books.txt");
    std::ifstream usersFile("users.txt");

    if (booksFile.is_open()) {
        std::string line;
        while (std::getline(booksFile, line)) {
            std::istringstream iss(line);
            Book book;
            iss >> book.id >> book.title >> book.author >> book.publisher >> book.isbn >> book.quantity >> book.year >> book.borrowed;
            books.push_back(book);
        }
        booksFile.close();
    }

    if (usersFile.is_open()) {
        std::string line;
        while (std::getline(usersFile, line)) {
            std::istringstream iss(line);
            User user;
            iss >> user.id >> user.name >> user.email;
            users.push_back(user);
        }
        usersFile.close();
    }
}

void Library::saveData() {
    std::ofstream booksFile("books.txt");
    std::ofstream usersFile("users.txt");

    if (booksFile.is_open()) {
        for (const auto& book : books) {
            booksFile << book.id << " " << book.title << " " << book.author << " " << book.publisher << " "
                      << book.isbn << " " << book.quantity << " " << book.year << " " << book.borrowed << std::endl;
        }
        booksFile.close();
    }

    if (usersFile.is_open()) {
        for (const auto& user : users) {
            usersFile << user.id << " " << user.name << " " << user.email << std::endl;
        }
        usersFile.close();
    }
}