// main.cpp
#include <iostream>
#include "library.h"

void displayMenu() {
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. Add a book\n";
    std::cout << "2. Remove a book\n";
    std::cout << "3. Update a book\n";
    std::cout << "4. Search for books\n";
    std::cout << "5. Display all books\n";
    std::cout << "6. Sort books\n";
    std::cout << "7. Add a user\n";
    std::cout << "8. Borrow a book\n";
    std::cout << "9. Return a book\n";
    std::cout << "10. Get book recommendations\n";
    std::cout << "11. Generate inventory report\n";
    std::cout << "12. Undo last action\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook;
                std::cout << "Enter book details:\n";
                std::cout << "ID: ";
                std::cin >> newBook.id;
                std::cin.ignore();
                std::cout << "Title: ";
                std::getline(std::cin, newBook.title);
                std::cout << "Author: ";
                std::getline(std::cin, newBook.author);
                std::cout << "Publisher: ";
                std::getline(std::cin, newBook.publisher);
                std::cout << "ISBN: ";
                std::getline(std::cin, newBook.isbn);
                std::cout << "Quantity: ";
                std::cin >> newBook.quantity;
                std::cout << "Year: ";
                std::cin >> newBook.year;
                newBook.borrowed = false;
                
                library.addBook(newBook);
                std::cout << "Book added successfully!\n";
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter the ID of the book to remove: ";
                std::cin >> id;
                library.removeBook(id);
                std::cout << "Book removed successfully!\n";
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter the ID of the book to update: ";
                std::cin >> id;
                Book updatedBook;
                std::cout << "Enter updated book details:\n";
                std::cout << "Title: ";
                std::cin.ignore();
                std::getline(std::cin, updatedBook.title);
                std::cout << "Author: ";
                std::getline(std::cin, updatedBook.author);
                std::cout << "Publisher: ";
                std::getline(std::cin, updatedBook.publisher);
                std::cout << "ISBN: ";
                std::getline(std::cin, updatedBook.isbn);
                std::cout << "Quantity: ";
                std::cin >> updatedBook.quantity;
                std::cout << "Year: ";
                std::cin >> updatedBook.year;
                library.updateBook(id, updatedBook);
                std::cout << "Book updated successfully!\n";
                break;
            }
            case 4: {
                std::string criteria;
                std::cout << "Enter search criteria: ";
                std::cin.ignore();
                std::getline(std::cin, criteria);
                auto results = library.searchBooks(criteria);
                std::cout << "Search results:\n";
                for (const auto& book : results) {
                    std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << std::endl;
                }
                break;
            }
            case 5:
                library.displayBooks();
                break;
            case 6: {
                std::string criteria;
                std::cout << "Enter sort criteria (title/author/year): ";
                std::cin >> criteria;
                library.sortBooks(criteria);
                std::cout << "Books sorted successfully!\n";
                break;
            }
            case 7: {
                User newUser;
                std::cout << "Enter user details:\n";
                std::cout << "ID: ";
                std::cin >> newUser.id;
                std::cin.ignore();
                std::cout << "Name: ";
                std::getline(std::cin, newUser.name);
                std::cout << "Email: ";
                std::getline(std::cin, newUser.email);
                library.addUser(newUser);
                std::cout << "User added successfully!\n";
                break;
            }
            case 8: {
                int userId, bookId;
                std::cout << "Enter user ID: ";
                std::cin >> userId;
                std::cout << "Enter book ID: ";
                std::cin >> bookId;
                library.borrowBook(userId, bookId);
                std::cout << "Book borrowed successfully!\n";
                break;
            }
            case 9: {
                int userId, bookId;
                std::cout << "Enter user ID: ";
                std::cin >> userId;
                std::cout << "Enter book ID: ";
                std::cin >> bookId;
                library.returnBook(userId, bookId);
                std::cout << "Book returned successfully!\n";
                break;
            }
            case 10: {
                int userId;
                std::cout << "Enter user ID for recommendations: ";
                std::cin >> userId;
                auto recommendations = library.getRecommendations(userId);
                std::cout << "Book recommendations:\n";
                for (const auto& book : recommendations) {
                    std::cout << "Title: " << book.title << ", Author: " << book.author << std::endl;
                }
                break;
            }
            case 11:
                library.generateInventoryReport();
                break;
            case 12:
                library.undo();
                std::cout << "Last action undone!\n";
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}