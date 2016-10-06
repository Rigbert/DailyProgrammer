// 286 ReverseFactorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	int originalInput; //original input by user
	int factorial = 2; //Number being check against the divisibleInput
	int divisibleInput;//Number to be divided
	std::cout << "Enter an integer and find it's factorial- will return none if it does not exist" << std::endl;
	std::cin >> originalInput;
	divisibleInput = originalInput; //Set the two equal so I can change divisibleInput while maintaining regular input so I can output it
	while ( divisibleInput % factorial == 0) { // While divisibleInput can still be divided by factorial - 
		divisibleInput = (divisibleInput / factorial); //Divide and set equal to what the divided is
		factorial++;
	}
	if (divisibleInput == 1) {
		std::cout << originalInput << " = " << factorial - 1 << "!" << std::endl; //output
	}
	else {
		std::cout << originalInput << " = NONE" << std::endl; //output
	}
}

