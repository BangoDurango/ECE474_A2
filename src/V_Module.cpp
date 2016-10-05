#include "V_Module.h"

void V_Module::addPin(std::string sName, std::string sType, std::string sbitWidth) {

	V_Pin nPin(sName, sType, sbitWidth);

	pins.push_back(nPin);

}
void V_Module::printLines(void) {
	for (vector<string>::iterator it = rawFileStrings.begin(); it != rawFileStrings.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
void V_Module::setFileStrings(std::vector<string> lines) {

}
std::vector<string>* V_Module::getFileStringVector() {

	return &rawFileStrings;
}

void V_Module::generatePins() {


	std::vector<string> tok;
	std::vector<string> sNames;
	std::string sType;
	std::string sBitWidthString;

	V_Pin* newPin;

	if (rawFileStrings.size() == 0){
		std::cout << "filestrings vector empty" << std::endl;
		return;
	}
	for(std::vector<string>::iterator it = rawFileStrings.begin(); it != rawFileStrings.end(); ++it){
		tok = Parser::splitByWhitespace(*it);

		sType = tok.at(0);
		if (!V_Pin::CheckType(tok.at(0))) return;

		sBitWidthString = tok.at(1);

		for (std::vector<string>::iterator it = tok.begin() + 2; it != tok.end(); ++it) {
			sNames.push_back(*it);
		}
		for (std::vector<string>::iterator it = sNames.begin(); it != sNames.end(); ++it) {
			newPin = new V_Pin(*it, sType, sBitWidthString);
			if (newPin->getType() == "invalid") {
				delete newPin;
				return;
			}
			else pins.push_back(*newPin);
		}
		sNames.clear();
	}


}