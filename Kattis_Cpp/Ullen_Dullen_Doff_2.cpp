#include <iostream>
#include <string>
#include <vector>

static void Run() {
	const int orderOffset = 12;
	int n = 0;
	int swapIndex = 0;
	std::cin >> n;

	std::vector<std::string> names;
	for(int i=0; i<n; ++i) {
		std::string input;
		std::cin >> input;
		names.push_back(input);
	}
	if (n <= orderOffset)
		swapIndex = (orderOffset - n) % names.size();
	else swapIndex = orderOffset;

	if(swapIndex != 0)
		std::swap(names[0], names[swapIndex]);

	for (auto n : names)
		std::cout << n << "\n";
}

//int main() {
//	Run();
//}

