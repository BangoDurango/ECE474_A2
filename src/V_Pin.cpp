
#include "V_Pin.h"

V_Pin::V_Pin(std::string sName, std::string sType, std::string sBitWidthString) {
	name = sName;
	//std::cout<< "in pin constructor" << std::endl;

	if (sType == "input") type = "input";
	else if (sType == "output") type = "output";
	else if (sType == "wire") type = "wire";
	else if (sType == "register") type = "reg";
	else { type = "invalid";
	std::cout << "invalid pin type" << std::endl;
	}


	string bitSubStr = sBitWidthString.substr(3, sBitWidthString.size());
		
	std::istringstream iss(bitSubStr) ;

	if (!(iss >> bitWidth)) std::cout << "Invalid bit string" << std::endl;

}

std::string V_Pin::getName(void) { return name; }
std::string V_Pin::getType(void) { return type; }