#include "V_Component.h"

V_Component::V_Component(V_Pin* In1, V_Pin* In2, V_Pin* Output, std::string Operation, int ComponentNumber) {
	componentNumber = ComponentNumber;
	in1 = In1;
	in2 = In2;
	output = Output;
	operation = Operation;
	//verilogString = this->buildVerilogString(in1, in2, output, operation);
	verilogString = this->buildVerilogString();
}

V_Component::V_Component(V_Pin* In1, V_Pin* Output, int ComponentNumber){
	componentNumber = ComponentNumber;
	in1 = In1;
	in2 = NULL;
	output = Output;
	int maxBitLength = 0;
	bool equalBits = false;
	operation = "";
	std::string extraZeros1 = "";
	std::string extraZeros1end = "";

	if (in1->getBitWidth()  == output->getBitWidth()){
		maxBitLength = in1->getBitWidth();
		equalBits = true;
	}
	else{
		equalBits = false;
		if (in1->getBitWidth() < output->getBitWidth()){
			maxBitLength = output->getBitWidth();
		}
		else{
			maxBitLength = output->getBitWidth();
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
	}

	verilogString = "REG #(" + to_string(maxBitLength) + ") REG_" + to_string(componentNumber) + "(" + extraZeros1 + in1->getName() + extraZeros1end + "," + output->getName() + ",Clk,Rst)";
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

//std::string V_Component::buildVerilogString(V_Pin* In1, V_Pin* In2, V_Pin* Output, std::string inputOperation){
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
		cout << "Error Invalid Operator";
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

