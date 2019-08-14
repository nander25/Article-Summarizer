#pragma once
#include <string>
#include <math.h>
#include "hashTable.h"

using namespace std;

/*
Finds the number of times a term appears within the original article.
Normalizes the number by diving by the total number of terms.
*/
double calculateTermFreq(string inpStr, int totalTerms, hashTable articleTable);

/*
Finds the inverse of how frequently a term appears within the corpus.
*/
double calculateInvDocFreq(string inpStr, int totalTerms, hashTable corpusTable);

/*
Finds the tf-idf for a word (tf-idf = term frequency * inverse document frequency)
*/
int tfidf(string inpStr, int articleTerms, int corpusTerms, hashTable articleTable, hashTable corpusTable);