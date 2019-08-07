//File Name: tf-idf.cpp
//Author: Noah Anderson
//Description: Uses the TF-IDF algorithm to find a rating for each word

#include "tf-idf.h"
#include "hashTable.h"

//Finds the number of times a term appears within the original article
//Normalizes this by diving by the total number of terms
double calculateTermFreq(string inpStr, int totalTerms, hashTable articleTable) {
	int numSpecificTerm = articleTable.findNumAppearances(inpStr);

	return (double) numSpecificTerm / (double) totalTerms;
}

//Finds the inverse of how frequently a term appears within the corpus
double calculateInvDocFreq(string inpStr, int totalTerms, hashTable corpusTable) {
	int numSpecificTerm = corpusTable.findNumAppearances(inpStr);
	
	return log((double) totalTerms / (double) numSpecificTerm);
}

//Finds the tf-idf for a word (tf-idf = term frequency * inverse document frequency)
int tfidf(string inpStr, int articleTerms, int corpusTerms, hashTable articleTable, hashTable corpusTable) {
	return calculateTermFreq(inpStr, articleTerms, articleTable) * calculateInvDocFreq(inpStr, corpusTerms, corpusTable);
}