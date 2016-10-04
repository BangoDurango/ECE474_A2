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
		return 0;
	}
	std::cout << argv[0] << std::endl;

	Parser testParser(argv[1], "ignore");
	V_Pin testVPin("a", "input", "Int32");

	//newParser.PrintLines();
	//newParser.setFileName();

	//ifstream inFile(argv[1]);
	
	//string line;

	//if (inFile.is_open() && inFile.good()) std::cout << "File Opened!" << std::endl;

	//while (getline(inFile, line)) {
	//	std::cout << line << std::endl;
	//}


	//inFile.close();

	return 0;
}