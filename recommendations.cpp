// recommendations.cpp
#include "library.h"
#include <unordered_map>
#include <algorithm>

std::vector<Book> Library::getRecommendations(int userId) {
    std::unordered_map<int, int> bookFrequency;
    std::vector<Book> recommendations;

    // Count book frequency among users who borrowed the same books
    for (const auto& user : users) {
        if (user.id != userId) {
            for (const auto& book : user.borrowedBooks) {
                if (std::find_if(users[userId].borrowedBooks.begin(), users[userId].borrowedBooks.end(),
                                 [&book](const Book& b) { return b.id == book.id; }) != users[userId].borrowedBooks.end()) {
                    for (const auto& otherBook : user.borrowedBooks) {
                        if (std::find_if(users[userId].borrowedBooks.begin(), users[userId].borrowedBooks.end(),
                                         [&otherBook](const Book& b) { return b.id == otherBook.id; }) == users[userId].borrowedBooks.end()) {
                            bookFrequency[otherBook.id]++;
                        }
                    }
                    break;
                }
            }
        }
    }

    // Sort books by frequency and return top 5
    std::vector<std::pair<int, int>> sortedFrequency(bookFrequency.begin(), bookFrequency.end());
    std::sort(sortedFrequency.begin(), sortedFrequency.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; });

    for (int i = 0; i < 5 && i < sortedFrequency.size(); i++) {
        auto it = std::find_if(books.begin(), books.end(),
                               [&sortedFrequency, i](const Book& b) { return b.id == sortedFrequency[i].first; });
        if (it != books.end()) {
            recommendations.push_back(*it);
        }
    }

    return recommendations;
}