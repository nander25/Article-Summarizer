Program: Article Summarizer
Developer: Noah Anderson
Language: C++

-------------------------------------------------------------------------------------------------------------------------------------------

Goal:
	The aim of this project is to create a program that will provide a summary of a given peice of text, usually an essay or news arti-
cle. The Article Summarizer will shorten the text into the most important sentences and return only the most important information to the 
user. The Article Sumarizer is designed to make getting the main points from long essays and articles easier.

Implementation:
	The Article Summarizer uses the Term Frequency - Inverse Document Frequency algorithm to find which sentences are the most importa-
nt. This algorithm gives a rating to each word in the article based upon how many times it appears in the article and how many times it ap-
pears in a collection of documents called a corpus. This rating is lower for common words like 'the', 'it', 'was', 'is, etc. because they
appear many times within the corpus. The rating is high for words that are less frequent, such as unique proper nouns which may only appea-
r once or twice in the corpus. Once each word has been rated, the program will attribute a score to each sentence based on the total rating
of all of it's words. The top ranking sentences are then chosen and presented to the user.

Data-Structures:
	This program uses a hash table with chaining to store each word and it's number of appearances. Each word in a document is formated
to be all lower case and contain only characters from a to z. Then, each of the characters is assigned a value which is used in the polyno-
mial rolling hash function to assign a value to each word.  
	