#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_stackRPN;
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN	&operator=(const RPN &copy);

		void	push(int value);
		void	pop();
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();
		void	calculate(const std::string &expression);
		void	print();

		class EmptyStackException: public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Empty stack");
				}
		};
};

#endif
