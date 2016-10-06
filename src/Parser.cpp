
#include "Parser.h"


void Parser::parseFile(std::string inFileStr, std::vector<string> *destVector) {
	std::string line;
	std::ifstream inFile;

	inFile = std::ifstream(inFileStr.c_str());
	//outFile = std::ofstream(outFilePath);
	std::cout << inFileStr << std::endl;

	//&& outFile.is_open() && outFile.good()
	if (inFile.is_open() && inFile.good()) {
	//	std::cout << "File Opened!" << std::endl;
	}
	else {
		std::cout << "File(s) not opened." << std::endl;
		//return std::vector<std::string>();
	}

	//std::cout << "Inside constructor" << std::endl;
	//fstream::getline()
	//line = new std::string;
	while (std::getline(inFile, line)) {
	//	std::cout << line << std::endl;
		if (line != "") {
			destVector->push_back(line);
		}
		//push_back(line);

	}


	inFile.close();

	//outFile.flush();
	//outFile.close();
	//return  lines;
}

vector<std::string> Parser::splitByWhitespace(std::string str) {

	string buf; // Have a buffer string
	stringstream ss(str); // Insert the string into a stream

	vector<string> tokens; // Create vector to hold our words

	while (ss >> buf) {
		buf.erase(std::remove(buf.begin(), buf.end(), ','), buf.end());
		tokens.push_back(buf);
	//	std::cout << buf << std::endl;
	}
	return tokens;

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