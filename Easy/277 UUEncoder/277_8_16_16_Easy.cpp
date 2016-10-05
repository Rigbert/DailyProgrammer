// 277_8_16_16_Easy.cpp : Defines the entry point for the console application.
//
//convert to ascii then to binary
#include "stdafx.h"
using  std::cout;
using  std::endl;
char encoder(std::bitset<6> bit6set) {
	std::string bit6setString = bit6set.to_string();
	int asciiNumber = std::stoi(bit6setString, 0, 2);
	char asciiRep = asciiNumber + 32;
	return asciiRep;
}

std::string bit24ToBit6(std::bitset<24> bit24set) {
	std::string bit24setString = bit24set.to_string();
	std::string encodedData;
	std::string bit6string;
	int bitCount = 0;
	for (auto individualBit : bit24setString) {
		bitCount++;
		bit6string += individualBit;
		if (bitCount == 6) {
			std::bitset<6> bit6set(bit6string);
			encodedData += encoder(bit6set);
			bitCount = 0;
			bit6string = "";
			bit6set.reset();
		}

	}

	return encodedData;
}
std::string stringToBinary(std::string input) {
	
	std::string encodedData;
	std::string charBytesNumber;
	std::bitset<8> trailZeros(0);
	for (int inputIndex = 0; inputIndex != input.size(); inputIndex++) {
		std::bitset<8>charBytes(input[inputIndex]);
		charBytesNumber += charBytes.to_string();


		if ( (inputIndex + 1) % 3 == 0 || (input.size() % 3 != 0 && input.size() - inputIndex == input.size() % 3)) {
			std::bitset<24> binaryStorage(charBytesNumber);
			charBytesNumber = "";
			encodedData += bit24ToBit6(binaryStorage);
			binaryStorage.reset();
			
		}

	}
	return encodedData;
}




int main(int argc, char* argv[]) // create argument handling
{
	std::string input; //What you're inputting
	std::vector<std::string> encodedInput; //The input that has been encoded - full string
	std::cout << "Input the phrase to be encoded" << std::endl;
	std::vector<std::string> splitCharLines; //Where you intend to split the strings into their appropriate lines
	std::string placeholderString;
	std::fstream encodedTxtFile;
	std::string largeInput;

	getline(std::cin, input);

	for (auto charInput : input) {
		if (placeholderString.size() == 45) {
			splitCharLines.push_back(placeholderString);
			placeholderString = "";
			placeholderString += charInput;
		}
		else {
			placeholderString += charInput;
		}
	}
	splitCharLines.push_back(placeholderString);
	
	for (auto plainTxtLine : splitCharLines) {
		std::string encodedLine;
		char charCount = plainTxtLine.size() + 32;
		if (plainTxtLine == splitCharLines.back() && plainTxtLine.size() % 3 != 0) {
			for (int remainder = plainTxtLine.size() % 3; remainder != 0; remainder--) {
				plainTxtLine += '\0';
			}
		}
		encodedLine = stringToBinary(plainTxtLine);
		encodedLine.insert(encodedLine.begin(), charCount);
		encodedInput.push_back(encodedLine);
	}


	/*if (input.size() <= 10 && input != "\0") { //implement files and you're done
		input += ".txt"; // fix file input!
		encodedTxtFile.open(largeInput, std::fstream::in | std::fstream::out | std::fstream::app);
	}
	if (input.size() > 10) {
		 largeInput = input.substr(input.find_first_of(" ") - 1);
		 largeInput += ".txt";
		encodedTxtFile.open(largeInput, std::fstream::in | std::fstream::out | std::fstream::app);
	} */
	cout << "begin 644 ";
	cout << "file.txt" << endl;
	for (auto i : encodedInput) {
		cout << i << endl;
	}
	cout << "`" << endl;
	cout << "end" << endl;
	

}
