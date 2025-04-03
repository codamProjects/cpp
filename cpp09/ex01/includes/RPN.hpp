
#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {
	private:
		std::stack<int> _operands;

		RPN(RPN const& other) = delete;
		RPN& operator=(RPN const& other) = delete;
		void	calcultor(std::string const& rpnOperator);
		void	printResult();
	public:
		RPN();
		~RPN();
		void	processInput(std::string const& input);
};

#endif