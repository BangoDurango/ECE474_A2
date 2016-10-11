#include "V_Component.h"

V_Component::V_Component(V_Pin* In1, V_Pin* In2, V_Pin* Output, std::string Operation, int ComponentNumber) {
	componentNumber = ComponentNumber;
	in1 = In1;
	in2 = In2;
	output = Output;
	operation = Operation;
	verilogString = this->buildVerilogString();
}

V_Component::V_Component(V_Pin* In1, V_Pin* Output, int ComponentNumber){
	//This constructor is to create a Register component
	componentNumber = ComponentNumber; //initializes componentNumber
	in1 = In1; //initializes in1
	in2 = NULL; //initializes in2
	output = Output; //initializes output
	int maxBitLength = 0; //stores the max bit length
	bool equalBits = false; //set to true if all inputs/outputs are equal bit length
	operation = ""; //
	std::string extraZeros1 = ""; //string for extra zeros if bit length are different
	std::string extraZeros1end = ""; //for final "}" if need for different bit lengths

	//Checks to see if bit length if different
	if (in1->getBitWidth()  == output->getBitWidth()){
		//set bit length - All are equal
		maxBitLength = in1->getBitWidth();
		//All variables have same bit length
		equalBits = true;
	}
	else{
		//variables have different bit length
		equalBits = false;
		//sets the max bit length 
		if (in1->getBitWidth() < output->getBitWidth()){
			maxBitLength = output->getBitWidth();
		}
		else{
			maxBitLength = output->getBitWidth();
		}
	}

	//if bit length are different zero are added in front of the variable to match the max bit length
	if (equalBits == false){
		int bitDiff = 0;
		if (in1->getBitWidth() != maxBitLength){
			bitDiff = maxBitLength - in1->getBitWidth();
			extraZeros1 = "{" + to_string(bitDiff) + "'b";
			for (int i = 0; i < bitDiff; i++){
				extraZeros1.append("0");
			}
			extraZeros1.append(",");
			extraZeros1end = "}";
		}
	}

	//creates verilog string for REG component
	verilogString = "REG #(" + to_string(maxBitLength) + ") REG_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + output->getName() + ",Clk,Rst)";
	//FOR TESTING
	std::cout << verilogString << std::endl;
}

V_Component::V_Component(V_Pin* In1, V_Pin* In2, V_Pin* Control, V_Pin* Output, int ComponentNumber){
	componentNumber = ComponentNumber;
	in1 = In1;
	in2 = In2;
	std::string extraZeros1 = "";
	std::string extraZeros1end = "";
	std::string extraZeros2 = "";
	std::string extraZeros2end = "";
	control = Control;
	output = Output;
	int maxBitLength = 0;
	bool equalBits = false;
	operation = "";
	std::vector<V_Pin*> pins;
	pins.push_back(in1);
	pins.push_back(in2);
	pins.push_back(output);

	if ((in1->getBitWidth() == output->getBitWidth()) && (in2->getBitWidth() == output->getBitWidth())){
		maxBitLength = in1->getBitWidth();
		equalBits = true;
	}
	else{
		equalBits = false;
		for (std::vector<V_Pin*>::iterator it = pins.begin(); it != pins.end(); ++it){
			if (maxBitLength < (*it)->getBitWidth()){
				maxBitLength = (*it)->getBitWidth();
			}
		}
	}

	if (equalBits == false){
		int bitDiff = 0;
		if (in1->getBitWidth() != maxBitLength){
			bitDiff = maxBitLength - in1->getBitWidth();
			extraZeros1 = "{" + to_string(bitDiff) + "'b";
			for (int i = 0; i < bitDiff; i++){
				extraZeros1.append("0");
			}
			extraZeros1.append(",");
			extraZeros1end = "}";
		}
		if (in2->getBitWidth() != maxBitLength){
			bitDiff = maxBitLength - in2->getBitWidth();
			extraZeros2 = "{" + to_string(bitDiff) + "'b";
			for (int i = 0; i < bitDiff; i++){
				extraZeros2.append("0");
			}
			extraZeros2.append(",");
			extraZeros2end = "}";
		}

	}

	verilogString = "MUX #(" + to_string(maxBitLength) + ") MUX_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + extraZeros2 + in2->getName() + extraZeros2end + "," + control->getName() + "," + output->getName() + ")";
	std::cout << verilogString << std::endl;



}


std::string V_Component::buildVerilogString(){
	int maxBitLength = 0;
	int compOper = 0;
	bool equalBits = false;
	std::string tempString;
	std::string component;
	std::string extraZeros1 = "";
	std::string extraZeros1end = "";
	std::string extraZeros2 = "";
	std::string extraZeros2end = "";
	std::vector<V_Pin*> pins;
	pins.push_back(in1);
	pins.push_back(in2);
	pins.push_back(output);

	if ((in1->getBitWidth() == in2->getBitWidth()) && (in2->getBitWidth() == output->getBitWidth())){
		maxBitLength = in1->getBitWidth();
		equalBits = true;
	}
	else{
		equalBits = false;
		for (std::vector<V_Pin*>::iterator it = pins.begin(); it != pins.end(); ++it){
			if (maxBitLength < (*it)->getBitWidth()){
				maxBitLength = (*it)->getBitWidth();
			}
		}
	}

	if (equalBits == false){
		int bitDiff = 0;
		if (in1->getBitWidth() != maxBitLength){
			bitDiff = maxBitLength - in1->getBitWidth();
			extraZeros1 = "{" + to_string(bitDiff) + "'b";
			for (int i = 0; i < bitDiff; i++){
				extraZeros1.append("0");
			}
			extraZeros1.append(",");
			extraZeros1end = "}";
		}
		if (in2->getBitWidth() != maxBitLength){
			bitDiff = maxBitLength - in2->getBitWidth();
			extraZeros2 = "{" + to_string(bitDiff) + "'b";
			for (int i = 0; i < bitDiff; i++){
				extraZeros2.append("0");
			}
			extraZeros2.append(",");
			extraZeros2end = "}";
		}

	}

	if (operation == "+"){
		component = "ADD";
	}
	else if (operation == "-"){
		component = "SUB";
	}
	else if (operation == "*"){
		component = "MUL";
	}
	else if (operation == ">"){
		component = "COMP";
		compOper = 1;
	}
	else if (operation == "<"){
		component = "COMP";
		compOper = 2;
	}
	else if (operation == ">>"){
		component = "SHR";
	}
	else if (operation == "<<"){
		component = "SHL";
	}
	else if (operation == "=="){
		component = "COMP";
		compOper = 3;
	}
	else{
		cout << "Error Invalid Operator" << endl;
		exit(1);
	}

	if (component == "COMP"){
		switch (compOper){
		case 1: tempString = component + " #(" + to_string(maxBitLength) + ") " + component + "_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + extraZeros2 + in2->getName() + extraZeros2end + "," + output->getName() + ",,)";
			break;
		case 2: tempString = component + " #(" + to_string(maxBitLength) + ") " + component + "_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + extraZeros2 + in2->getName() + extraZeros2end + ",," + output->getName() + ",)";
			break;
		case 3: tempString = component + " #(" + to_string(maxBitLength) + ") " + component + "_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + extraZeros2 + in2->getName() + extraZeros2end + ",,," + output->getName() + ")";
			break;

		}

	}
	else{
		tempString = component + " #(" + to_string(maxBitLength) + ") " + component + "_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + extraZeros2 + in2->getName() + extraZeros2end + "," + output->getName() + ")";
	}
	
	//testing
	cout << tempString << endl;
	return tempString;
}

