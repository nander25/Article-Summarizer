//File Name: readFile.cpp
//Author: Noah Anderson
//Description: Reads text file, parses words, and returns a vector of strings

#include "readFile.h"

//Reads a file and adds each word to a vector
vector<string> getWordsFromFile(string fileName) {
	
	ifstream file;
	file.open(fileName);
	
	string temp;

	if(file.is_open()) {
		while (file >> temp)
		{
			wordList.push_back(formatString(temp));
		}
	}
	else {
		cout << "Error, the file \"" << fileName << "\" cannot be found.\n";
	}
	
	file.close();

	return wordList;
}

//Formats a string to be all lowercase and contain only alphanumeric characters
string formatString(string input) {
	string output;

	for (size_t i = 0; i < input.size(); i++) {
		if (isalnum(input[i])) {
			output += tolower(input[i]);
		}
	}

	return output;
}

