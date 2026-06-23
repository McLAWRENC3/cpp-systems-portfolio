#include"../include/Operation.h"


double AddOperation::execute(double a, double b) const {
	return a + b;
}
double SubOperation::execute(double a, double b) const {
	return a - b;
}
double MulOperation::execute(double a, double b) const {
	return a * b;
}
double DivOperation::execute(double a, double b) const {
	return a / b;
}
std::unique_ptr<Operation> OperationFactory::create(char op) {
	switch (op) {
	case '+': return std::make_unique<AddOperation>();
	case '-': return std::make_unique<SubOperation>();
	case '*': return std::make_unique<MulOperation>();
	case '/': return std::make_unique<DivOperation>();
	default:
		throw std::runtime_error("Unknown operator");
	}
}