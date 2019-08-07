#pragma once
#include <string>
#include <math.h>

using namespace std;

double calculateTermFreq(string inpStr, int totalTerms, hashTable articleTable);

double calculateInvDocFreq(string inpStr, int totalTerms, hashTable corpusTable);

int tfidf(string inpStr, int articleTerms, int corpusTerms, hashTable articleTable, hashTable corpusTable);