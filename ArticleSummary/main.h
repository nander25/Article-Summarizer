#pragma once

#include "hashTable.h"
#include "readFile.h"
#include "tf-idf.h"
#include <iostream>;
#include <filesystem>;
#include <string>;

namespace fs = std::experimental::filesystem;



int main();
void printMenu();
void loadCorpus(fs::path filePath, hashTable *corpusTable, vector<SENTENCE*> articleList);
void loadArticle(fs::path filePath, hashTable *articleTable, hashTable *corpusTable, vector<SENTENCE*> articleList);