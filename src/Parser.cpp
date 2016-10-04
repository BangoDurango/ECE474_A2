
#include "Parser.h"


Parser::Parser(std::string inFileArg, std::string outFileArg) {
	std::string line;
	inFilePath = inFileArg;
	outFilePath = outFileArg;

//	std::cout << inFilePath << std::endl;

	inFile = std::ifstream(inFilePath);
	outFile = std::ofstream(outFilePath);
	//setFileName();

	if (inFile.is_open() && inFile.good() && outFile.is_open() && outFile.good()) {
		//std::cout << "File Opened!" << std::endl;
	}
	else {	
		std::cout << "File(s) not opened." << std::endl;
		return;
	}

	//std::cout << "Inside constructor" << std::endl;

	while (getline(inFile, line)) {
		//std::cout << line << std::endl;
		lines.push_back(line);
	}

	
	inFile.close();

	outFile.flush();
	outFile.close();
	return;

}

void Parser::PrintLines(void) {
	for (vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

//void Parser::setFileName() {
//	
//	std::size_t found = inFilePath.find_last_of("/\\");
//	fileName = inFilePath.substr(found + 1);
//	filePath= inFilePath.substr(0, found);
//	//std::cout << fileName << std::endl;
//	//std::cout << filePath << std::endl;
//
//}