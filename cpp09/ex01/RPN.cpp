#include <iostream>
#include <stack>
#include <cmath>
#include "RPN.hpp"

int	eval_operation(char c)
{
	std::string	operations = "+-*/% ";
	size_t		pos = operations.find(c);
	if (pos != std::string::npos)
		return (pos);
	else if (c >= '0' && c <= '9')
		return (DIGIT);
	return (-1);
}

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN()
{
}

RPN	&RPN::operator=(const RPN &copy)
{
	if (this == &copy)
		return (*this);
	this->_stackRPN = copy._stackRPN;
	return (*this);
}

void	RPN::push(int value)
{
	this->_stackRPN.push(value);
}

void	RPN::pop()
{
	if (this->_stackRPN.empty())
		throw RPN::EmptyStackException();
	this->_stackRPN.pop();
}

void	RPN::add()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->pop();
	int	b = this->_stackRPN.top();
	this->pop();
	this->push(b + a);
	std::cout << b << " + " << a << " = " << b + a << std::endl;
}

void	RPN::sub()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->pop();
	int	b = this->_stackRPN.top();
	this->pop();
	this->push(b - a);
	std::cout << b << " - " << a << " = " << b - a << std::endl;
}

void	RPN::mul()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->pop();
	int	b = this->_stackRPN.top();
	this->pop();
	this->push(b * a);
	std::cout << b << " * " << a << " = " << b * a << std::endl;
}

void	RPN::div()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->pop();
	int	b = this->_stackRPN.top();
	this->pop();
	this->push(b / a);
	std::cout << b << " / " << a << " = " << b / a << std::endl;
}

void	RPN::mod()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->pop();
	int	b = this->_stackRPN.top();
	this->pop();
	this->push(b % a);
	std::cout << b << " % " << a << " = " << b % a << std::endl;
}

void	RPN::calculate(const std::string &expression)
{
	std::string::const_iterator	it = expression.begin();
	std::string::const_iterator	ite = expression.end();
	while (it != ite)
	{
		switch (eval_operation(*it))
		{
			case ADD:
				this->add();
				break;
			case SUB:
				this->sub();
				break;
			case MUL:
				this->mul();
				break;
			case DIV:
				this->div();
				break;
			case MOD:
				this->mod();
				break;
			case SPACE:
				break;
			case DIGIT:
				this->push(*it - '0');
				break;
			default:
				throw RPN::InvalidExpressionException();
		}
		++it;
	}
	this->print();
}

void	RPN::print()
{
	if (this->_stackRPN.empty())
		throw RPN::EmptyStackException();
	std::cout << this->_stackRPN.top() << std::endl;
}

const char	*RPN::EmptyStackException::what() const throw()
{
	return ("Error: empty stack");
}

const char	*RPN::InvalidExpressionException::what() const throw()
{
	return ("Error: invalid expression");
}
