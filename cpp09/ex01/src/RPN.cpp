
#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <exception>
#include <limits>

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::printResult() {
	if (this->_operands.size() != 1)
		throw std::invalid_argument("too many operands left in stack");
	std::cout << this->_operands.top() << std::endl;
}

void	RPN::calcultor(std::string const& rpnOperator) {
	if (this->_operands.size() < 2)
		throw std::invalid_argument("not enough operands for operator => " + rpnOperator);
	int second = this->_operands.top();
	this->_operands.pop();
	int first = this->_operands.top();
	this->_operands.pop();

	int result;
	if (rpnOperator == "+") {
		result = first + second;
		if ((first > 0 && second > 0 && result <= 0) || \
			(first < 0 && second < 0 && result >= 0))
			throw std::overflow_error("addition resulted in an over/underflow");
	}
	else if (rpnOperator == "-") {
		result = first - second;
		if ((first > 0 && second < 0 && result <= 0) || \
			(first < 0 && second > 0 && result >= 0))
			throw std::overflow_error("subtraction resulted in an over/underflow");
	}
	else if (rpnOperator == "/") {
		if (second == 0)
			throw std::runtime_error("division by zero");
		result = first / second;
	}
	else if (rpnOperator == "*") {
		result = first * second;
		if (first != 0 && result / first != second)
			throw std::overflow_error("multiplication resulted in an over/underflow");
	}
	else
		throw std::invalid_argument("unknown operator => " + rpnOperator);
	this->_operands.push(result);
}

void	RPN::processInput(std::string const& input) {
	if (input.empty() || input.find_first_not_of(" \t\n\r\v\f") == std::string::npos)
		throw std::invalid_argument("input empty or only containing whitespaces");
	std::istringstream iss(input);
	std::string token;
	while (iss >> token) {
		if (token == "+" || token == "-" || token == "/" || token == "*")
			this->calcultor(token);
		else {
			try {
				size_t i;
				int num = std::stoi(token, &i);
				if (num < -9 || num > 9 || i != token.size())
					throw std::exception();
				this->_operands.push(num);
			} catch (const std::exception& e){
				throw std::invalid_argument("invalid operand or operator => " + token);
			}
		}
	}
	this->printResult();
}

