#pragma once
#include <string>
#include <math.h>

using namespace std;

double calculateTermFreq(string inpStr, int totalTerms, vector<WORD*> hashtable);

double calculateInvDocFreq(string inpStr, int totalTerms, vector<WORD*> hashtable);

int tfidf(string inpStr, int articleTerms, int corpusTerms, vector<WORD*> articletable, vector<WORD*> corpustable);