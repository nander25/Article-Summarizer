// File Name: main.cpp
// Author: Noah Anderson
// Description: Handles user input and execution of other files.
#include "hashTable.h"
#include "readFile.h"
#include "tf-idf.h"
#include <iostream>;
#include <filesystem>;
#include <string>;

void printMenu();

namespace fs = std::experimental::filesystem;

int main(){
	
	char userInput;
	string fileDir;
	vector<string> articleList;
	hashTable *corpusTable = new hashTable;


	fs::path P("C:\\");

	printMenu();
	
	do {
		
		P = "C:\\";

		cin >> userInput;
		switch (userInput) {
			
			/*
			Opens every ".txt" file in the user inputed directory.
			Considers each file to be a part of the corpus.
			*/
			case 'L':
				cout << "Enter the directory where the corpus files are stored:\n" << P;
				cin >> fileDir;
				P /= fileDir;
				
				if (fs::exists(P)) {
					for (const auto& part : fs::directory_iterator(P)) {

						if (part.path().extension() == ".txt") {
							cout << part.path().filename() << "\n";
							formatedReadFile(part.path().string(), false, corpusTable, articleList);
						}

					}
				}
				else {
					cout << P << " does not exist.\n";
				}

				break;
			
			/*
			Opens the file specific for summarization, then calculates the tf-idf.
			Rates each sentence, then returns the highest rated sentence.
			*/
			case 'S':
				break;

			/*
			Prints the main menu.
			*/
			case 'M':
				printMenu();
				break;
			
			/*
			Quits the program.
			*/
			case 'Q':
				break;
			
			/*
			Default case for invalid inputs.
			*/
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
