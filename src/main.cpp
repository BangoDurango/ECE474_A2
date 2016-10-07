#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "Parser.h"
#include "V_Module.h"
#include "V_Pin.h"

using namespace std;

int main (int argc, char* argv[]){
	//std::cout << "Test" << endl;	
	
	if (argc != 3) {
		std::cout << "incorrect number of arguments." << std::endl;
		//return 0;
	}

	//std::cout << argv[0] << std::endl;
	V_Module vmod;

	Parser::parseFile(argv[1], vmod.getFileStringVector());
	//static parser class reads each line of the file in to vmod member rawfilestrings

	vmod.generatePins();
	
	vmod.generateComponents();
	vmod.printLines();



	return 0;
}