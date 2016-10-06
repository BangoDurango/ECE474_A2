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
		std::cout << "Incorrect number of arguments." << std::endl;
		//return 0;
	}

	//std::cout << argv[0] << std::endl;
	V_Module VMod;

	Parser::parseFile(argv[1], VMod.getFileStringVector());
	//Static Parser class reads each line of the file in to VMod member rawFileStrings

	VMod.generatePins();

	//std::cout << "testing getPinByName(): " << VMod.getPinByName("a")->getType() << std::endl;
	VMod.generateComponents();
	//VMod.printLines();



	return 0;
}