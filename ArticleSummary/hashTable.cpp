//File Name: hashTable.cpp
//Author: Noah Anderson
//Description: Gives hash key for string, add and search values in the hash table

#include "hashTable.h"

struct WORD
{
	string word;
	int noOfAppearances;
	WORD* next;
};

const int tableSize = 104729;
const int prime = 31;

vector<WORD*> hashtable(tableSize);

//Computes the hash key of a string by using a rolling polynomial hash function
long long compute_hashKey(string inpStr) {
	long long hash_key = 0;
	long long power = 1;

	for (int i = 0; i < inpStr.length(); i++) {
		hash_key = (hash_key + (inpStr[i] - 'a' + 1) * power) % tableSize;
		power = (power * prime) % tableSize;
	}

	return hash_key;
}

//Inserts a string into the hash table.
//Uses chaining if two strings have the same hash key.
void insert(string inpStr) {
	
	//Calculates the hash key
	long long hash_key = compute_hashKey(inpStr);

	//If there is nothing at that index, insert the new word
	if (hashtable[hash_key] == NULL)  {

		WORD* newWord = new WORD;
		newWord->word = inpStr;
		newWord->noOfAppearances = 1;
		newWord->next = NULL;

		hashtable[hash_key] = newWord;
	}
	//Otherwise, search to see if the word exists already, or if chaining is necessary.
	else {

		bool found = false;

		WORD* temp = hashtable[hash_key];
		
		//Seaches for the word in the chain
		while (temp != NULL && found != true)
		{
			//If the word is found, do not chain
			if (temp->word.compare(inpStr) == 0) {
				temp->noOfAppearances++;
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
			newWord->noOfAppearances = 1;
			newWord->next = NULL;

			temp->next = newWord;
		}
	}
}

//Finds the number of times a specific word has been inputed into the hash table
int findNumAppearances(string inpStr) {
	long long hash_key = compute_hashKey(inpStr);

	//If the word has not be inputed, return 0
	if (hashtable[hash_key] == NULL) {
		return 0;
	}

	//Searches the chain for the word
	else {
		WORD* temp = hashtable[hash_key];

		int numAppearances = 0;

		while (temp != NULL && numAppearances == 0)
		{
			if (temp->word.compare(inpStr) == 0) {
				numAppearances = temp->noOfAppearances;
			}
			else {
				temp = temp->next;
			}
		}

		return numAppearances;
	}
}

