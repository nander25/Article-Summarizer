//File Name: tf-idf.cpp
//Author: Noah Anderson
//Description: Uses the TF-IDF algorithm to find a rating for each word

#include "tf-idf.h"
#include "hashTable.h"


double calculateTermFreq(string inpStr, int totalTerms, vector<WORD*> hashtable) {
	int numSpecificTerm = findNumAppearances(inpStr, hashtable);

	return (double) numSpecificTerm / (double) totalTerms;
}

double calculateInvDocFreq(string inpStr, int totalTerms, vector<WORD*> hashtable) {
	int numSpecificTerm = findNumAppearances(inpStr, hashtable);
	
	return log((double) totalTerms / (double) numSpecificTerm);
}

//Finds the tf-idf for a word (tf-idf = tf * idf)
int tfidf(string inpStr, int articleTerms, int corpusTerms, vector<WORD*> articletable, vector<WORD*> corpustable) {
	return calculateTermFreq(inpStr, articleTerms, articletable) * calculateInvDocFreq(inpStr, corpusTerms, corpustable);
}