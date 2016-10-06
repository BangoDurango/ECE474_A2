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
#include <algorithm>
//#include "V_Module.h"

using namespace std;

class Parser {

public:

	static void parseFile(std::string inFileStr, std::vector<string>* lines);
	static vector<std::string> splitByWhitespace(std::string line);
};

#endif //PARSER_H