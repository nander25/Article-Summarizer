#pragma once
#include <string>
#include <vector>

using namespace std;

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

	long long compute_hashKey(string inpStr);
	void insert(string inpStr);
	int findNumAppearances(string inpStr);

};