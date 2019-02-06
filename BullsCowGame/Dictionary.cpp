#include "Dictionary.h"
#include <utility>
#include <map>
#include <fstream>
#include <iostream>
#include <ios>
std::map<int, std::string> Dictionary::dictionary;
void Dictionary::BuildDictionary()
{
	std::ifstream File;
	std::string FilePath;
	do {
		std::cout << "What is the file path?" << std::endl;
		std::cin >> FilePath;
		File.open(FilePath, std::ios::in);
		if (!Dictionary::FileExist(&File)) {
			std::cout << "File doesnt exist, please re-enter the file path" << std::endl;
		}
	} while (!Dictionary::FileExist(&File));
	
	int Counter = 0;
	//looping through all the contents in the csv file
	while (File.good()) {
		std::string Word;
		std::getline(File, Word, ',');
		Dictionary::Insert(Counter, Word);
		Counter++;
	}
	std::cout << "Dictionary is finished construct" << std::endl;
	File.close();
}

bool Dictionary::FileExist(std::ifstream *File)
{
	return File->is_open();
}

void Dictionary::Insert(int Counter, std::string Isogram)
{
	Dictionary::dictionary[Counter] = Isogram;
}