#pragma once

/***
Author: Kevin Gilliam
NetID: keving
Assignment #: 2
File: V_Module.h
*/
#ifndef V_MODULE_H
#define V_MODULE_H

#include<string>
#include <sstream>
#include<vector>
#include <iostream>
#include <fstream>
//include<boost/tokenizer.hpp>
#include "V_Pin.h"
#include "Parser.h"

using namespace std;
//using namespace boost;

class V_Module {

public:
	~V_Module();//to delete strings

	void getPinsByName(std::string s);
	void addPin(std::string sName, std::string sType, std::string sbitWidth);

	void addParsedFile(Parser ParsedFile);

private:
	std::vector<string*> inputFile;
	std::vector<V_Pin> Pins;


};

#endif //V_MODULE_H
