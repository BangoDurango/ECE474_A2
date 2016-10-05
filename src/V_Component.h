#pragma once
/***
Author: Kevin Gilliam
NetID: keving
Assignment #: 2
File: V_Module.h
*/
#ifndef V_COMPONENT_H
#define V_COMPONENT_H


#include<string>
#include <vector>
#include<iostream>
#include <sstream>
#include "v_pin.h"
#include "V_Module.h"

using namespace std;

class V_Component {

public:


private:
	std::string name;

	V_Pin* in1;
	V_Pin* in2;
	V_Pin* out;

	V_Module* VMod;

};
#endif //V_COMPONENT_H
