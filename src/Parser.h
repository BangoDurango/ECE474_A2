#pragma once

/***
Author: Kevin Gilliam
NetID: keving
Assignment #: 2
File: Parser.h
*/
#ifndef PARSER_H
#define PARSER_H

#include<string>
#include <sstream>
#include<vector>
#include <iostream>
#include <fstream>
#//include<boost/tokenizer.hpp>

using namespace std;
//using namespace boost;

class Parser {

public:

	//Parser(void);
	Parser(std::string inFileArg, std::string outFileArg);
//	~Parser(void);
	void PrintLines(void);

	//void setFileName();

private:
	std::ifstream inFile;
	std::ofstream outFile;

	std::string inFilePath;
	std::string outFilePath;

	//std::string fileName;
	//std::string filePath;
	std::vector<std::string> lines;


};

#endif //PARSER_H