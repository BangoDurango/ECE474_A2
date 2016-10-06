
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
V_Pin::V_Pin() {
	//default constructor
	type = "invalid";
}
bool V_Pin::CheckType(std::string sType) {
	//This function verifies that the string is a type input or output etc
	bool flag = false;

	if (sType == "input") flag = true;
	else if (sType == "output") flag = true;
	else if (sType == "wire") flag = true;
	else if (sType == "register") flag = true;
	return flag;
}



std::string V_Pin::getName(void) { return name; }
std::string V_Pin::getType(void) { return type; }
unsigned int V_Pin::getBitWidth(void) { return bitWidth;}

void V_Pin::printPin() {
	std::cout << "Type: " << type << "; Bit Width: " << bitWidth << "; Name: " << name << std::endl;
}

