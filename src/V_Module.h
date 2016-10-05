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
#include <vector>
#include<iostream>
#include <sstream>
#include "V_Pin.h"
#include "Parser.h"

class V_Module {

public:
	//~V_Module();//to delete strings

	//void getPinsByName(std::string s);
	void addPin(std::string sName, std::string sType, std::string sbitWidth);
	void printLines(void);
//	void setupPins();
	void setFileStrings(std::vector<string> lines);
	std::vector<string>* getFileStringVector();
	
	void generatePins();

private:
	std::vector<V_Pin> pins;
	std::vector<string> rawFileStrings;

};


#endif V_MODULE_H