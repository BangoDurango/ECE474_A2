#include "V_Component.h"

V_Component::V_Component(V_Pin* In1, V_Pin* In2, V_Pin* Output, std::string Operation) {
	in1 = In1;
	in2 = In2;
	output = Output;
	operation = Operation;
}