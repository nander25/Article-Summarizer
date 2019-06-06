#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

vector<string> wordList;

vector<string> getWordsFromFile(string fileName);

string formatString(string input);