// Rack Management 1.cpp : Defines the entry point for the console application.
// Link to project: https://www.reddit.com/r/dailyprogrammer/comments/5go843/20161205_challenge_294_easy_rack_management_1/
// I have done Bonus 1 as well
// Will probably come back and do Bonus 2 tomorrow
#include <string>
#include <map>
#include <iostream>

int scrabble(std::string letters, std::string word) {
	std::map<char, int> letterCount;
	for (int i = 0; i < letters.length(); i++) {  //Yes I realize i and j are awful variable names, I couldn't be bothered at this point to come up with anything else
		if (!letterCount.count(letters[i])) {
			letterCount[letters[i]] = 1;
		}
		else {
			letterCount[letters[i]] += 1;
		}
	}
	for (int j = 0; j < word.length(); j++) {
		if (letterCount[word[j]]) {
			letterCount[word[j]] -= 1;
		}
		else if (letterCount['?']) {
			letterCount['?'] -= 1;
		}
		else {
			std::cout << "False" << std::endl;
			return 0;
		}
	}
	std::cout << "True" << std::endl;
	return 1;
}


int main()
{
	scrabble("ladilmy", "daily");
	scrabble("eerriin", "eerie");
	scrabble("orrpgma", "program");
	scrabble("orppgma", "program");
	scrabble("pizza??", "pizzazz");
	scrabble("piizza?", "pizzazz");
	scrabble("a??????", "program");
	scrabble("b??????", "program");
}

