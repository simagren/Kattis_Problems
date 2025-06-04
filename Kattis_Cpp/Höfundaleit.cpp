#include <iostream>
#include <stdlib.h>
#include <string>
#include <ranges>
#include <string_view>
#include <vector>
#include <map>
#include<unordered_map>
#include <algorithm>

static void Run()
{
    std::string nInput, yInput;
    std::cin >> nInput >> yInput;
    int n = std::stoi(nInput);
    int q = std::stoi(yInput);
    std::string author, bookTitle;

    std::vector<std::pair<std::string, std::string>> library;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::string input;      
        std::getline(std::cin, input);

        size_t commaPos = input.find(',');
        if (commaPos != std::string::npos) {
            bookTitle = input.substr(0, commaPos);
            author = input.substr(commaPos + 1);
            author.erase(0, 1);
        }

        library.push_back(std::make_pair(bookTitle, author));
    }

    // Sort by authors
    std::sort(library.begin(), library.end(), [](const auto a, const auto& b) {
        if (a.second == b.second) // If same author, sort by book title
            return a.first < b.first;
        return a.second < b.second; // sort by author normally
        });

    std::unordered_map<std::string, size_t> sortedTitleIndex;
    for (size_t i = 0; i < library.size(); i++) {
        sortedTitleIndex[library[i].first] = i;
    }

    // Find desired books
    for (int i = 0; i < q; i++) {
        std::string desiredBook;
        std::cin >> desiredBook;

        if(sortedTitleIndex.find(desiredBook) != sortedTitleIndex.end())
            std::cout << sortedTitleIndex[desiredBook] + 1 << "\n";
        else
            std::cout << -1 << "\n";
    }
}


/*int main(){
    Run();
}*/
