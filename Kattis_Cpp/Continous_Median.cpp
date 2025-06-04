#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>

//static std::vector<int> split_string_to_int(const std::string& str, const char delimiter) {
//    std::vector<int> vec;
//    std::stringstream stringStream (str);
//    std::string stringToAdd;
//    while (std::getline(stringStream, stringToAdd, delimiter)) {
//        vec.push_back(std::stoi(stringToAdd));
//    }
//    return vec;
//}



static bool isEven(const std::multiset<int>& m) {
    return m.size() % 2 == 0;
}


static void Run() {
    int T;
    std::cin >> T;

    // For each test case
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        long long sum = 0;
        std::multiset<int> numbers;
        std::multiset<int>::iterator median;
        for (int j = 0; j < N; j++) {
            int num;
            std::cin >> num;
            numbers.insert(num);
            if (numbers.size() == 1)
                median = numbers.begin();
            else if (num < *median) {
                if (isEven(numbers))
                    --median;
            }
            else if (!isEven(numbers))
                ++median;

            if (!isEven(numbers))
                sum += *median;
            else
                sum += (*median + *std::next(median)) / 2;

        }
        std::cout << sum << "\n";
    }
}

//int main() {
//    Run();
//}
