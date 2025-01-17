// inventory_report.cpp
#include "library.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

void Library::generateInventoryReport() {
    int totalBooks = 0;
    int totalBorrowedBooks = 0;
    std::unordered_map<int, int> borrowCount;

    for (const auto& book : books) {
        totalBooks += book.quantity;
        if (book.borrowed) {
            totalBorrowedBooks++;
            borrowCount[book.id]++;
        }
    }

    std::cout << "Inventory Report" << std::endl;
    std::cout << "Total books: " << totalBooks << std::endl;
    std::cout << "Total borrowed books: " << totalBorrowedBooks << std::endl;

    std::vector<std::pair<int, int>> sortedBorrowCount(borrowCount.begin(), borrowCount.end());
    std::sort(sortedBorrowCount.begin(), sortedBorrowCount.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; });

    std::cout << "Most borrowed books:" << std::endl;
    for (int i = 0; i < 5 && i < sortedBorrowCount.size(); i++) {
        auto it = std::find_if(books.begin(), books.end(),
                               [&sortedBorrowCount, i](const Book& b) { return b.id == sortedBorrowCount[i].first; });
        if (it != books.end()) {
            std::cout << it->title << " by " << it->author << " - Borrowed " << sortedBorrowCount[i].second << " times" << std::endl;
        }
    }
}