#pragma once

#ifndef V_COMPONENT_H
#define V_COMPONENT_H

#include<string>
#include <vector>
#include<iostream>
#include <sstream>
#include "V_Pin.h"

using namespace std;

class V_Component {

public:
//	V_Component();

	V_Component(V_Pin* In1, V_Pin* In2, V_Pin* Output, std::string Operation);//In addition to setting the pin pointers, you can probably just put the verilog string together in here?
	//std::string getVerilogString();//


private:

	std::string name;
	std::string type;//We can create a different class for each type of componenet if we need to? I don't know if that's necessary, your call.
	std::string operation;
	V_Pin* in1;
	V_Pin* in2;
	V_Pin* output;

	std::string verilogString;
};
#endif //V_COMPONENT_H
