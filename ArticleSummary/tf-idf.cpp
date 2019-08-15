//File Name: tf-idf.cpp
//Author: Noah Anderson
//Description: Uses the TF-IDF algorithm to find a rating for each word

#include "tf-idf.h"


double calculateTermFreq(string inpStr, int totalTerms, hashTable *articleTable) {
	int numSpecificTerm = articleTable->findNumAppearances(inpStr);

	return (double) numSpecificTerm / (double) totalTerms;
}


double calculateInvDocFreq(string inpStr, int totalTerms, hashTable *corpusTable) {
	int numSpecificTerm = corpusTable->findNumAppearances(inpStr);
	
	return log((double) totalTerms / (double) numSpecificTerm);
}


double tfidf(string inpStr, hashTable *articleTable, hashTable *corpusTable) {
	return calculateTermFreq(inpStr, articleTable->getWordCount(), articleTable) * calculateInvDocFreq(inpStr, corpusTable->getWordCount(), corpusTable);
}