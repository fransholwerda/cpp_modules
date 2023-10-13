#include <iostream>
#include "RPN.hpp"

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
	this->_stackRPN.pop();
	int	b = this->_stackRPN.top();
	this->_stackRPN.pop();
	this->_stackRPN.push(a + b);
}

void	RPN::sub()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->_stackRPN.pop();
	int	b = this->_stackRPN.top();
	this->_stackRPN.pop();
	this->_stackRPN.push(a - b);
}

void	RPN::mul()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->_stackRPN.pop();
	int	b = this->_stackRPN.top();
	this->_stackRPN.pop();
	this->_stackRPN.push(a * b);
}

void	RPN::div()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->_stackRPN.pop();
	int	b = this->_stackRPN.top();
	this->_stackRPN.pop();
	this->_stackRPN.push(a / b);
}

void	RPN::mod()
{
	if (this->_stackRPN.size() < 2)
		throw RPN::EmptyStackException();
	int	a = this->_stackRPN.top();
	this->_stackRPN.pop();
	int	b = this->_stackRPN.top();
	this->_stackRPN.pop();
	this->_stackRPN.push(a % b);
}

void	RPN::calculate(const std::string &expression)
{
	std::string::const_iterator	it = expression.begin();
	std::string::const_iterator	ite = expression.end();
	while (it != ite)
	{
		if (*it == ' ')
			;
		else if (*it == '+')
			this->add();
		else if (*it == '-')
			this->sub();
		else if (*it == '*')
			this->mul();
		else if (*it == '/')
			this->div();
		else if (*it == '%')
			this->mod();
		else if (*it >= '0' && *it <= '9')
		{
			int	value;
			while (it != ite && *it >= '0' && *it <= '9')
			{
				value = *it - '0';
				++it;
			}
			this->push(value);
			continue ;
		}
		else
			throw RPN::EmptyStackException();
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
