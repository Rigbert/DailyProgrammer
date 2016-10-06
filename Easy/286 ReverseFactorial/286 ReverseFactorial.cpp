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
	divisibleInput = originalInput; //Set the two equal so I can change divisibleInput while maintaining regular input so it can be out
	while ( divisibleInput % factorial == 0) { // While divisibleInput can still be divided by factorial - allows so that if divisibleInput = 1 it will break and if divisibleInput > 1 but not divisible will still break
		divisibleInput = (divisibleInput / factorial); //Divide and set equal to what the divided is
		factorial++;
	}
	if (divisibleInput == 1) { //Will equal one if it looped through factorial to equal a perfect one.
		std::cout << originalInput << " = " << factorial - 1 << "!" << std::endl; //output
	}
	else { //If divisibleInput wasn't able to be divided evenly by the next number
		std::cout << originalInput << " = NONE" << std::endl; //output
	}
}

