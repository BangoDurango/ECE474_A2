#pragma once
/***
Author: Kevin Gilliam
NetID: keving
Assignment #: 2
File: V_Module.h
*/
#ifndef V_PIN_H
#define V_PIN_H


#include<string>
#include <vector>
#include<iostream>
#include <sstream>

using namespace std;

class V_Pin {

public:
	std::string getName(void);
	std::string getType(void);
	V_Pin(std::string sName, std::string sType, std::string sBitWidthString);

private:

	//const std::vector<std::string> types = { "input", "output", "wire" };
	std::string type;
	unsigned int bitWidth;
	std::string name;

};
#endif V_PIN_H