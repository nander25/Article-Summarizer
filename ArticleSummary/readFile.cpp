//File Name: readFile.cpp
//Author: Noah Anderson
//Description: Reads text file, parses words, and returns a vector of strings

#include "readFile.h"
#include "hashTable.h"

//Reads a file and a outputs each word to the specified output
//If userInputFlag is true, each word is added to a vector and organized in sentences
//If userInputFlag is false, each word is added to the hash table
void formatedReadFile(string fileName, bool userInputFlag, hashTable table) {
	
	ifstream file;
	file.open(fileName);
	
	string readString;

	if(file.is_open()) {
		while (file >> readString)
		{
			
			string formatedString = formatString(readString);
			
			if (userInputFlag) {
				//Checks if there is a '.' at the end of the word
				//If so, adds a period to the vector to organize words by sentence
				if (readString.at(readString.length() - 1) == '.') {
					userInputWordList.push_back(formatedString);
					userInputWordList.push_back(".");
				}
				else {
					userInputWordList.push_back(formatedString);
				}
			}
			else {
				table.insert(formatedString);
			}
			
		}
	}
	else {
		cout << "Error, the file \"" << fileName << "\" cannot be found.\n";
	}
	
	file.close();

	return;
}

//Formats a string to be all lowercase and contain only alphanumeric characters
string formatString(string input) {
	string formattedOutput = "";

	for (size_t i = 0; i < input.size(); i++) {
		if (isalnum(input[i])) {
			formattedOutput += tolower(input[i]);
		}
	}

	return formattedOutput;
}

