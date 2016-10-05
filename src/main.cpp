#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "parser.h"
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
	//VMod.setFileStrings(Parser::parseFile(argv[0]));
	Parser::parseFile(argv[1], VMod.getFileStringVector());

	VMod.generatePins();

	VMod.printLines();



	return 0;
}