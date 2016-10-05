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
//#include "V_Module.h"

using namespace std;
//using namespace boost;

class Parser {

public:

	//Parser(void);
	//Parser(std::string inFileArg);
//	~Parser(void);

	static void parseFile(std::string inFileStr, std::vector<string>* lines);

	//void setVMod(V_Module* VM);
	static vector<std::string> splitByWhitespace(std::string line);
	//void printLines(void);

	//void parseToVMod(V_Module* VM);
	//void setFileName();

private:
	//V_Module* VMod;

	//std::ifstream inFile;
	//std::ofstream outFile;

	//std::string inFilePath;
	//std::string outFilePath;

	//std::string fileName;
	//std::string filePath;
	//std::vector<std::string> lines;


};

#endif //PARSER_H