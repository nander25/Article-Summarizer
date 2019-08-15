//File Name: readFile.cpp
//Author: Noah Anderson
//Description: Reads text file, parses words, and returns a vector of strings

#include "readFile.h"


void formatedReadFile(string fileName, bool userInputFlag, hashTable *table, vector<SENTENCE*> userInputWordList) {
	
	ifstream file(fileName);
	
	string readString;
	bool endOfSentence = true;
	SENTENCE* currentWord;

	if(file.is_open()) {
		while (file >> readString)
		{
			
			string formatedString = formatString(readString);
			
			if (userInputFlag) {
				//Checks if there is a '.' at the end of the word
				//If so, adds a period to the vector to organize words by sentence

				SENTENCE *newWord = new SENTENCE;
				SENTENCE *currentWord = newWord;
				newWord->word = readString;
				newWord->rating = 0;

				if (endOfSentence) {
					userInputWordList.push_back(newWord);
					currentWord = newWord;
				}
				else {
					currentWord->nextWord = newWord;
					currentWord = newWord;
				}

				if (readString.at(readString.length() - 1) == '.') {
					endOfSentence = true;
				}
				else {
					endOfSentence = false;
				}
			}
			
			table->insert(formatedString);

			
		}
	}
	else {
		cout << "Error, the file \"" << fileName << "\" cannot be found.\n";
	}
	
	file.close();

	return;
}


string formatString(string input) {
	string formattedOutput = "";

	for (size_t i = 0; i < input.size(); i++) {
		if (isalnum(input[i])) {
			formattedOutput += tolower(input[i]);
		}
	}

	cout << formattedOutput << "\n";

	return formattedOutput;
}

