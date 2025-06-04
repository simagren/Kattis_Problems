#include <vector>
#include <iostream>
#include <algorithm>


int main() {
	int length, height;
	std::cin >> length >> height;
	std::vector<int> stalagmites, stalacites;
	std::pair<int, int> heightResults = {INT_MAX, 0};
	for (int i = 0; i < length; ++i) {
		int input;
		std::cin >> input;
		
		if (i % 2 == 0) // Stalagmite (from floor)
			stalagmites.emplace_back(input);	
		else			// Stalacite (from ceiling)	
			stalacites.emplace_back(input);
	}
	std::sort(stalagmites.begin(), stalagmites.end());
	std::sort(stalacites.begin(), stalacites.end());
	for (int i = 1; i <= height; ++i) {
		// Check stalagmite collision
		auto lowerIt = std::lower_bound(stalagmites.begin(), stalagmites.end(), i);
		int stalagHits = stalagmites.end() - lowerIt;

			// Check stalacite collision
		lowerIt = std::lower_bound(stalacites.begin(), stalacites.end(), height - i + 1);
		int stalacHits = stalacites.end() - lowerIt;
		int result = stalagHits + stalacHits;
		if (result < heightResults.first)
			heightResults = { result, 1 };
		else if (result == heightResults.first)
			heightResults.second++;
	}
	std::cout << heightResults.first << " " << heightResults.second << "\n";
}