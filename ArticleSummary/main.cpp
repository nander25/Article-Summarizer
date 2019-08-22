// File Name: main.cpp
// Author: Noah Anderson
// Description: Handles user input and execution of other files.
#include "main.h"

int main(){
	
	char userInput;
	vector<SENTENCE*> articleList;
	hashTable *corpusTable = new hashTable;
	hashTable *articleTable = new hashTable;


	fs::path filePath("C:\\");

	printMenu();
	
	do {
		
		filePath = "C:\\";

		cin >> userInput;
		switch (userInput) {
			
			//Loads all files for the corpus
			case 'L':
				loadCorpus(filePath, corpusTable, articleList);
				break;
			
			//Runs tf-idf on the selected file
			case 'S':
				loadArticle(filePath, articleTable, corpusTable, articleList);
				break;

			//Prints the main menu.			
			case 'M':
				printMenu();
				break;
			
			//Quits the program.
			case 'Q':
				break;
			
			//Default case for invalid inputs.
			default:
				cout << "Invalid Input\n";
		}

	} while (userInput != 'Q');


	exit(0);
}

/*
Prints the menu.
*/
void printMenu() {
	cout << "Menu:\nLoad Corpus : L\nSummarize File : S\nPrint Menu : M\nQuit : Q\n";
}

/*
Opens every ".txt" file in the user inputed directory.
Considers each file to be a part of the corpus.
*/
void loadCorpus(fs::path filePath, hashTable *corpusTable, vector<SENTENCE*> articleList) {
	string fileDir;
	
	cout << "Enter the directory where the corpus files are stored:\n" << filePath;
	cin >> fileDir;
	filePath /= fileDir;

	if (fs::exists(filePath)) {
		for (const auto& part : fs::directory_iterator(filePath)) {

			if (part.path().extension() == ".txt") {
				cout << part.path().filename() << "\n";
				formatedReadFile(part.path().string(), false, corpusTable, articleList);
			}

		}
	}
	else {
		cout << filePath << " does not exist.\n";
	}
}

/*
Opens the file specific for summarization, then calculates the tf-idf.
Rates each sentence, then returns the highest rated sentence.
*/
void loadArticle(fs::path filePath, hashTable *articleTable, hashTable *corpusTable, vector<SENTENCE*> articleList) {
	string fileDir;
	
	cout << "Enter the file path of the article:\n" << filePath;
	cin >> fileDir;
	filePath /= fileDir;

	if (fs::exists(filePath)) {
		if (filePath.extension() == ".txt") {
			cout << "File found\n";
			formatedReadFile(filePath.string(), true, articleTable, articleList);

			//Calculate the total TF-IDF score for each sentence.
			for (int i = 0; i < articleList.size(); i++) {

				SENTENCE *firstWord = articleList.at(i);
				SENTENCE *iterator = articleList.at(i);

				while (iterator->nextWord != NULL) {
					firstWord->rating += tfidf(formatString(iterator->word), articleTable, corpusTable);
					iterator = iterator->nextWord;
				}
			}

			//Find the highest rated sentence
			SENTENCE *largest = articleList.at(0);
			for (int j = 1; j < articleList.size(); j++) {
				if (articleList.at(j)->rating > largest->rating) {
					largest = articleList.at(j);
				}
			}

			//Print the highest rated sentence
			while (largest->nextWord != NULL) {
				cout << largest->word << " ";
				largest->nextWord = largest;
			}
			

		}
		else
		{
			cout << filePath.filename() << " is not a readable file";
		}
	}
	else
	{
		cout << filePath << " does not exist.\n";
	}
}

