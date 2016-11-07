// 7 AnagramCheck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	std::string strWord1; 
	std::string strWord2;
	const std::string strAlphabet = "abcdefghijklmnopqrstuvwxyz";
	int iCountLetters1[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int iCountLetters2[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	std::string strTryAgain;


	do {
		//reset count letters
		int iLoop = 0;
		
		for (iLoop = 0; iLoop <= 25; iLoop++) {
			iCountLetters1[iLoop] = 0;
			iCountLetters2[iLoop] = 0;
		}
		
		
		//get first word
		std::cout << "Enter your first word.\n";
		std::getline(std::cin, strWord1);

		//get second word
		std::cout << "Enter your second word.\n";
		std::getline(std::cin, strWord2);


		// if they are different lengths they can't be anagrams
		if (strWord1.size() != strWord2.size()) {
			std::cout << "Those words have got different lengths, so they can't be anagrams.\n";
		}
		else {

			int iAlphLoop = 0;
			int iWordSize;

			// run through strWord1 letter by letter and count how many of each letter
			iWordSize = strWord1.size();
			for (iLoop = 0; iLoop < iWordSize; iLoop++){
				
				// run through the alphbet array and count up how many of each letter are included
				for (iAlphLoop = 0; iAlphLoop < 26; iAlphLoop++){
					if (strWord1.at(iLoop) == strAlphabet.at(iAlphLoop)) {
						iCountLetters1[iAlphLoop] = iCountLetters1[iAlphLoop] + 1;
					}
				}
			}

			// run through strWord2 letter by letter and count how many of each letter
			iWordSize = strWord2.size();
			for (iLoop = 0; iLoop < iWordSize; iLoop++){

				// run through the alphbet array and count up how many of each letter are included
				for (iAlphLoop = 0; iAlphLoop < 26; iAlphLoop++){
					if (strWord2.at(iLoop) == strAlphabet.at(iAlphLoop)) {
						iCountLetters2[iAlphLoop] = iCountLetters2[iAlphLoop] + 1;
					}
				}
			}

			for (iLoop = 0; iLoop <= 25; iLoop++) {

				if (iCountLetters1[iLoop] != iCountLetters2[iLoop]) {
					std::cout << "Those words are not anagrams of each other.\n";
					break;
				}
				else if (iLoop == 25) {
					std::cout << "Yes, those words are anagrams of each other.\n";
				}
			}

		}

		std::cout << "Try another two words?\n";
		do {
			std::getline(std::cin, strTryAgain);
			if (strTryAgain != "Yes" && strTryAgain != "No") {
				std::cout << "Please enter 'Yes' or 'No'.\n";
			}
		} while (strTryAgain != "Yes" && strTryAgain != "No");

	} while (strTryAgain != "No");
	return 0;
}

