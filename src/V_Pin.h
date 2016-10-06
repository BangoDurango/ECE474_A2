#pragma once
/***
Author: Kevin Gilliam
NetID: keving
Assignment #: 2
File: V_Pin.h
*/
#ifndef V_PIN_H
#define V_PIN_H


#include<string>
#include <vector>
#include<iostream>
#include <sstream>
#include "Parser.h"

using namespace std;

class V_Pin {

public:

	//V_Pin(std::string line);
	V_Pin();
	V_Pin(std::string sName, std::string sType, std::string sBitWidthString);

	std::string getName(void);
	std::string getType(void);
	unsigned int getBitWidth(void);
	void printPin();
	static bool CheckType(std::string);
	
private:

	//const std::vector<std::string> types = { "input", "output", "wire" };
	std::string type;
	unsigned int bitWidth;
	std::string name;

};
#endif V_PIN_H