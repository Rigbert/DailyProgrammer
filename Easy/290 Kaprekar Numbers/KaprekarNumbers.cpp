//Currently misses a few - will need to rewrite algorithm to account for more uneven splits - will do tomorrow 
#include <iostream>
#include <sstream>
#include <string>
int main() {
	int *range = new int[2];
	for (int i = 0; i < 2; i++) {
		std::cin >> range[i];
	}
	for (int x = range[0]; x <= range[1]; x++) {
		std::string firstHalfOfSquare = "";
		std::string secondHalfOfSquare = "";
		std::stringstream convert;
		convert << x * x;
		std::string convertString;
		convertString = convert.str();
		for (int j = 0; j < convertString.size(); j++) {
			if (j < convertString.size() / 2) {
				firstHalfOfSquare += convertString[j];
			}
			else {
				secondHalfOfSquare += convertString[j];				}
		}
		int numberFirstSquare = 0;
		int numberSecondSquare = 0;
		if (!firstHalfOfSquare.empty()) {
			numberFirstSquare = std::stoi(firstHalfOfSquare);
		}
		if (!secondHalfOfSquare.empty()) {
			numberSecondSquare = std::stoi(secondHalfOfSquare);
		}
		int result = numberFirstSquare + numberSecondSquare;
		if (result == x) {
			std::cout << x << " ";
		}
		convert.clear();

	}
	std::cout << std::endl;
	delete [] range;
}