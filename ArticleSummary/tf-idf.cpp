//File Name: tf-idf.cpp
//Author: Noah Anderson
//Description: Uses the TF-IDF algorithm to find a rating for each word

#include "tf-idf.h"
#include "hashTable.h"

double calculateTermFreq(string inpStr, int totalTerms, hashTable articleTable) {
	int numSpecificTerm = articleTable.findNumAppearances(inpStr);

	return (double) numSpecificTerm / (double) totalTerms;
}


double calculateInvDocFreq(string inpStr, int totalTerms, hashTable corpusTable) {
	int numSpecificTerm = corpusTable.findNumAppearances(inpStr);
	
	return log((double) totalTerms / (double) numSpecificTerm);
}


int tfidf(string inpStr, int articleTerms, int corpusTerms, hashTable articleTable, hashTable corpusTable) {
	return calculateTermFreq(inpStr, articleTerms, articleTable) * calculateInvDocFreq(inpStr, corpusTerms, corpusTable);
}