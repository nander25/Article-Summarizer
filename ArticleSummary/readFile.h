#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

vector<string> userInputWordList;

void formatedReadFile(string fileName, bool userInputFlag, hashTable table);

string formatString(string input);