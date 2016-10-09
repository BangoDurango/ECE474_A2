#include "V_Module.h"

//void V_Module::addPin(std::string sName, std::string sType, std::string sbitWidth) {
//
//	V_Pin nPin(sName, sType, sbitWidth);
//
//	pins.push_back(nPin);
//
//}
V_Module::~V_Module() {
	for (std::vector<V_Pin*>::iterator it = pins.begin(); it != pins.end(); ++it) {
		delete *it;
		it = pins.erase(it);
	}

	//Then need to loop again for components
}
void V_Module::printLines(void) {
	for (vector<string>::iterator it = rawFileStrings.begin(); it != rawFileStrings.end(); ++it) {
		std::cout << *it << std::endl;
	}
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
		//For each string in the vector which the file was loaded in to
		tok = Parser::splitByWhitespace(*it);//break the line up by whitespace

		sType = tok.at(0);//the first token should be input, output, wire etc
		if (!V_Pin::CheckType(tok.at(0))) {
			//if it's not, then it's a component (probably), so we're done generating pins...
			MOF = it;//set the iterator to this point so generateComponents can start here. 
			return;
		}
		sBitWidthString = tok.at(1); //The second item is always the bitwidth string

		for (std::vector<string>::iterator it = tok.begin() + 2; it != tok.end(); ++it) {
			sNames.push_back(*it);//Everything after the bitwidth string is a new pin, so we're making a vector of pin names
		}
		for (std::vector<string>::iterator it = sNames.begin(); it != sNames.end(); ++it) {
			//loop through the vector of pin names, and make a new V_Pin object for it
			newPin = new V_Pin(*it, sType, sBitWidthString);
			if (newPin->getType() == "invalid") {//For safety
				delete newPin;
				return;
			}
			
			else {
			//	newPin->printPin();//printPin(); for debugging
				if(pins.size() == 0) pins.push_back(newPin);//If the vector is empty, just put this in there.
				else pins.insert(pins.begin(), newPin);//They should load in order on their own
			}
			
		}
		sNames.clear();//After making all of the pins with this type and bitwidth, empty the name vector and move to the next type
	}


}

V_Pin* V_Module::getPinByName(std::string sName) {
	
	for (std::vector<V_Pin*>::iterator it = pins.begin(); it != pins.end(); ++it) {
		if ((*it)->getName() == sName) return *it;
	}
	return NULL;
}

void V_Module::generateComponents() {
	//Similar to generatePins() but creates a vector of v_components
	int componentNumber = 1; //store the number of component (used for distinguish multipil)
	V_Component* newComp; //stores new component pointer
	newComp = NULL; //initializes pointer to null everytime function is called
	std::vector<string> tok; //Stores the tokenized string
	std::string outputPin; //Stores the output pin string
	std::string input1Pin; //Stores the 1st input pin string
	std::string input2Pin; //Stores the 2nd input pin in string
	std::string operation; //Stores the operator
	//testing
	V_Pin* pin1;
	
	//Note: you can use the private method getPinByName() to pass input/output pointers to the componnent constructor...
	//for example, let's say you have string variables called input1 and input2 and output, and they have an "a", "b", and "x" in them...
	//you can say  newComp = new V_Component(getPinByName(input1), getPinByName(input2), getPinByName(output))

	for (std::vector<string>::iterator it = MOF; it != rawFileStrings.end(); it++) {
		//tokenizes string
		tok = Parser::splitByWhitespace(*it);
		//checks for size
		int size = tok.size();

		if (size == 3){
			outputPin = tok.at(0);
			//checks to see if pin name is stored
			pin1 = getPinByName(outputPin);
			//Error is thrown if pin cannot be found
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			if (tok.at(1) != "="){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			input1Pin = tok.at(2);
			//checks to see if pin name is stored
			pin1 = getPinByName(input1Pin);
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			newComp = new V_Component(getPinByName(input1Pin), getPinByName(outputPin), componentNumber);

		}

		//1 ouput; 1 equalSign; 2 inputs; 1 operator
		if (size == 5){
			//1st letter should be the output
			outputPin = tok.at(0);
			//checks to see if pin name is stored
			pin1 = getPinByName(outputPin);
			//Error is thrown if pin cannot be found
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			if (tok.at(1) != "="){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			input1Pin = tok.at(2);
			//checks to see if pin name is stored
			pin1 = getPinByName(input1Pin);
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			operation = tok.at(3);

			input2Pin = tok.at(4);
			//checks to see if pin name is stored
			pin1 = getPinByName(input1Pin);
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			//testing
			/*
			std::cout << "input1: " << input1Pin << std::endl;
			std::cout << "input2: " << input2Pin << std::endl;
			std::cout << "comp: " << operation << std::endl;
			std::cout << "output: " << outputPin << std::endl;*/

			//creates component to store in vector
			newComp = new V_Component(getPinByName(input1Pin), getPinByName(input2Pin), getPinByName(outputPin), operation, componentNumber);

		}

		if (size == 7){
			std::string input3Pin;
			int muxOut = 0;

			outputPin = tok.at(0);
			//checks to see if pin name is stored
			pin1 = getPinByName(outputPin);
			//Error is thrown if pin cannot be found
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			//Checking file format
			if (tok.at(1) != "="){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			if (tok.at(3) != "?"){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			if (tok.at(5) != ":"){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			input3Pin = tok.at(2);
			//checks to see if pin name is stored
			pin1 = getPinByName(input1Pin);
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			input1Pin = tok.at(4);
			//checks to see if pin name is stored
			pin1 = getPinByName(input1Pin);
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			input2Pin = tok.at(6);
			//checks to see if pin name is stored
			pin1 = getPinByName(input1Pin);
			if (pin1 == NULL){
				std::cout << "File Read Error: generateComponent() function" << std::endl;
				exit(1); //error end program
			}

			
			newComp = new V_Component(getPinByName(input1Pin), getPinByName(input2Pin), getPinByName(input3Pin), getPinByName(outputPin), componentNumber);


		}

		//add to component list
		comps.push_back(newComp);
		//updates componentNumber
		componentNumber = componentNumber + 1;
		//for (int i = 0; i < 3; i++){
		//	std::cout << tok.at(i) << std::endl;
		//}
		std::cout << std::endl;

	}
}