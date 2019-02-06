#pragma once
#include <string>
#include <map>
#ifndef Dictionary_H
#define Dictionary_H
class Dictionary
{
private:
	static std::map<int, std::string> dictionary;
	static bool FileExist(std::ifstream *);
public:
	static void BuildDictionary();
	static void Insert(int, std::string);
	static std::string GetRandomIsogram(int);
	static void Clear();
	static void VeiwAll();
};

#endif Dictionary_H