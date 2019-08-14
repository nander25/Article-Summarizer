#pragma once
#include <string>
#include <vector>

using namespace std;

/*
The hashTable class contains the functionality for storing
and retrieving strings in O(1) time. 
*/
class hashTable {

public:

	struct WORD
	{
		string word;
		int wordInfo;
		WORD* next;
	};

	vector<WORD*> table;

	hashTable();

	int compute_hashKey(string inpStr);
	void insert(string inpStr);
	int findNumAppearances(string inpStr);

};