#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include "hashTable.h"


/*
Reads a file and a outputs each word to the specified output.

If userInputFlag is true, each word is added to a vector and organized in sentences.
If userInputFlag is false, each word is added to the hash table.
*/
void formatedReadFile(string fileName, bool userInputFlag, hashTable *table, vector<string> userInputWordList);

/*
Formats a string to be all lowercase and remove any punctuation.

Returns lowercase alphanumer string 
*/
string formatString(string input);