// undo_functionality.cpp
#include "library.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Library::undo() {
    if (!undoStack.empty()) {
        auto lastAction = undoStack.back();
        undoStack.pop_back();

        switch (lastAction.first) {
            case 0: // Add book
                removeBook(std::stoi(lastAction.second));
                std::cout << "Undid add book operation.\n";
                break;
            case 1: // Remove book
                {
                    // Find the book in the books.txt file and add it back
                    std::ifstream inFile("books.txt");
                    std::string line;
                    while (std::getline(inFile, line)) {
                        std::istringstream iss(line);
                        Book book;
                        iss >> book.id;
                        if (std::to_string(book.id) == lastAction.second) {
                            iss >> book.title >> book.author >> book.publisher >> book.isbn >> book.quantity >> book.year >> book.borrowed;
                            addBook(book);
                            std::cout << "Undid remove book operation.\n";
                            break;
                        }
                    }
                    inFile.close();
                }
                break;
            case 2: // Update book
                {
                    // Find the previous version of the book in the books.txt file and update it
                    std::ifstream inFile("books.txt");
                    std::string line;
                    while (std::getline(inFile, line)) {
                        std::istringstream iss(line);
                        Book book;
                        iss >> book.id;
                        if (std::to_string(book.id) == lastAction.second) {
                            iss >> book.title >> book.author >> book.publisher >> book.isbn >> book.quantity >> book.year >> book.borrowed;
                            updateBook(book.id, book);
                            std::cout << "Undid update book operation.\n";
                            break;
                        }
                    }
                    inFile.close();
                }
                break;
        }
    } else {
        std::cout << "No actions to undo.\n";
    }
}