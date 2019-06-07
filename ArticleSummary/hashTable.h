#pragma once
#include <string>
#include <vector>


using namespace std;

struct WORD
{
	string word;
	int wordInfo;
	WORD* next;
};

long long compute_hashKey(string inpStr, vector<WORD*> hashtable);
void insert(string inpStr, vector<WORD*> hashtable);
int findNumAppearances(string inpStr, vector<WORD*> hashtable);
