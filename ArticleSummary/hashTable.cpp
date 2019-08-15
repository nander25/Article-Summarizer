//File Name: hashTable.cpp
//Author: Noah Anderson
//Description: Gives hash key for string, add and search values in the hash table

#include "hashTable.h"

struct WORD
{
	string word;
	int wordInfo;
	WORD* next;
};

const int TABLESIZE = 104729;
const int PRIME = 31;

/*
Default Constructor
Initializes data structure to set size
*/
hashTable::hashTable() {
	table.resize(TABLESIZE);
	wordCount = 0;
}

/*
Returns the total number of words in the table.
*/
int hashTable::getWordCount() {
	return wordCount;
}

/*
Uses a rolling polynomial hash function to calculate the hash 
key of a string.
*/
int hashTable::compute_hashKey(string inpStr) {
	long long hash_key = 0;
	long long power = 1;

	for (int i = 0; i < inpStr.length(); i++) {
		hash_key = (hash_key + (inpStr[i] - 'a' + 1) * power) % TABLESIZE;
		power = (power * PRIME) % TABLESIZE;
	}

	return (int)hash_key;
}

/*
Inserts a string into the hash table.
Uses chaining if two strings have the same hash key.
*/
void hashTable::insert(string inpStr) {
	
	//Calculates the hash key
	long long hash_key = compute_hashKey(inpStr);

	//Adds the word to the table using chaining
	if (table[hash_key] == NULL)  {

		WORD* newWord = new WORD;
		newWord->word = inpStr;
		newWord->wordInfo = 1;
		newWord->next = NULL;

		table[hash_key] = newWord;
	}
	else {

		bool found = false;

		WORD* temp = table[hash_key];
		
		//Seaches for the word in the chain
		//Adds the word if it is found
		while (temp != NULL && found != true)
		{
			if (temp->word.compare(inpStr) == 0) {
				temp->wordInfo++;
				found = true;
			}
			else {
				temp = temp->next;
			}
		}

		//Add to the end of the chain if not found
		if (found != true) {
			WORD* newWord = new WORD;
			newWord->word = inpStr;
			newWord->wordInfo = 1;
			newWord->next = NULL;

			temp->next = newWord;
		}
	}

	wordCount++;
}

/*
Finds the number of times a specific word has been inputed
into the hash table.
*/
int hashTable::findNumAppearances(string inpStr) {
	long long hash_key = compute_hashKey(inpStr);

	//If the word has not be inputed, return 0
	if (table[hash_key] == NULL) {
		return 0;
	}

	//Searches the chain for the word
	else {
		WORD* temp = table[hash_key];

		int numAppearances = 0;

		while (temp != NULL && numAppearances == 0)
		{
			if (temp->word.compare(inpStr) == 0) {
				numAppearances = temp->wordInfo;
			}
			else {
				temp = temp->next;
			}
		}

		return numAppearances;
	}
}

