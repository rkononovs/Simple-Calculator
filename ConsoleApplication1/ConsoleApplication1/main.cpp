#include <string>
#include <iostream>
#include <cctype>

int main()
{
	// Initialize variables
	float fFirstNumber = 0, fSecondNumber = 0, fResult = 0;
	std::string sInput, sFirstNumber, sSecondNumber;


	// Print menu to the screen
	std::cout << "Welcome to my calculator!" << std::endl;
	std::cout << "To type decimals use point '.' ." << std::endl << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "Enter 'add' to add two numbers" << std::endl;
	std::cout << "Enter 'subtract' to subtract two numbers" << std::endl;
	std::cout << "Enter 'multiply' to multiply two numbers" << std::endl;
	std::cout << "Enter 'divide' to divide two numbers" << std::endl;
	std::cout << "Enter 'options' to print options" << std::endl;
	std::cout << "Enter 'quit' to quit program" << std::endl;

	//Make an exit loop
	while (true) {
		std::cin >> sInput; // Enter a input from menu (add,subtract,multiply,divide,options,quit)

		// Make every character to lower-case ( http://www.cplusplus.com/reference/cctype/tolower/ )
		for (int i = 0; sInput.size() > i; i++) {
			sInput[i] = tolower(sInput[i]);
		}

		// Verify if input is correct i.e. from menu
		while ((sInput != "add") && (sInput != "subtract") && (sInput != "multiply") && (sInput != "divide") && (sInput != "options") && (sInput != "quit")) {
			std::cout << "Sorry, but '" << sInput << "' is not an option.\n" << "Try again!\n";


			std::cin >> sInput;
		}

		if (sInput == "quit") { // if input is quit then quit from loop
			break;
		}
		else if (sInput == "options") { // if input is options print again available options
			std::cout << std::endl;
			std::cout << "Options:" << std::endl;
			std::cout << "Enter 'add' to add two numbers" << std::endl;
			std::cout << "Enter 'subtract' to subtract two numbers" << std::endl;
			std::cout << "Enter 'multiply' to multiply two numbers" << std::endl;
			std::cout << "Enter 'divide' to divide two numbers" << std::endl;
			std::cout << "Enter 'options' to print options" << std::endl;
			std::cout << "Enter 'quit' to quit program" << std::endl;
			continue;
		}
		// Enter two numbers as strings
		std::cout << "Enter a number: "; std::cin >> sFirstNumber;
		std::cout << "Enter another number: "; std::cin >> sSecondNumber;
		try { // Try to execute code (http://www.cplusplus.com/doc/tutorial/exceptions/)
			// Convert strings into floats (http://www.cplusplus.com/reference/string/stof/)
			fFirstNumber = std::stof(sFirstNumber);
			fSecondNumber = std::stof(sSecondNumber);

			if (sInput == "add") { // If input was ADD then add two numbers and print result
				fResult = fFirstNumber + fSecondNumber;
				std::cout << "The result is " << fResult << std::endl;
			}
			else if (sInput == "subtract") { // If input was SUBTRACT then subtract two numbers and print result
				fResult = fFirstNumber - fSecondNumber;
				std::cout << "The result is " << fResult << std::endl;
			}
			else if (sInput == "multiply") { // If input was MULTIPLY then multiply two numbers and print result
				fResult = fFirstNumber * fSecondNumber;
				std::cout << "The result is " << fResult << std::endl;
			}
			else if (sInput == "divide") { // If input was divide then divide two numbers and print result
				while (fSecondNumber == 0) { // If division with zero is detected execute while loop
					// Print error message
					std::cout << "Cannot divide with zero!" << std::endl;
					std::cout << "Try again!\n" << std::endl;
					// Ask for a new input
					std::cout << "Enter a first number again: "; std::cin >> sFirstNumber;
					std::cout << "Enter a second number number again: "; std::cin >> sSecondNumber;
					// Convert new input to float
					fFirstNumber = std::stof(sFirstNumber);
					fSecondNumber = std::stof(sSecondNumber);
				}
				// Print result
				fResult = fFirstNumber / fSecondNumber;
				std::cout << "The result is " << fResult << std::endl;
			}
		}
		catch (...) { // If an exception is detected within try catch it and execute error message ( http://www.cplusplus.com/doc/tutorial/exceptions/ )
			std::cout << "It's not a number, choose option again!" << std::endl;
		}
	}

	return 0; // return zero and terminate program
}
