
#include "Types.hpp"

Types::Types(std::string const& literal): _literal(literal) { }
Types::~Types() { }

void	Types::basicChecks() {
	std::string buf = this->_literal;
	
	if (buf.empty())
		throw ParseException("empty string");
	if (buf.back() == 'F' || buf.back() == 'f')
		buf.pop_back();
	if ((buf.front() == '+' || buf.front() == '-') && buf.size() > 1)
		buf = buf.substr(1, buf.size());
	if (buf.find_first_of('.') != buf.find_last_of('.'))
		throw ParseException("multiple decimal points");
	if (buf.front() == '.' && buf.back() == '.')
		throw ParseException("string has no valid conversion");
	if (buf.find_first_not_of("1234567890.") != std::string::npos)
		throw ParseException("string has no valid conversion");

	size_t trim = buf.find_first_not_of('0');
	buf = trim != std::string::npos ? buf.substr(trim, buf.size()) : "0.0";
	if (buf.front() == '.')
		buf = "0" + buf;
	if (buf.back() == '.')
		buf.append("0");
	size_t i = buf.find_first_of('.');
	if (i == std::string::npos) {
		this->_beforeDecPoint = buf.size();
		buf.append(".0");
	}
	else {
		this->_afterDecPoint = i == buf.size() - 1 ? 1 : buf.size() - (i + 1);
		this->_beforeDecPoint = i == 0 ? 1 : i;
	}
	if (this->_literal.front() == '-')
		buf = "-" + buf;
	this->_trimmedLit = buf;
}

void	Types::convertChar() {
	std::cout << "Char: '" << this->_c << "'\n";
	this->_i = static_cast<int>(this->_c);
	std::cout << "Int: " << this->_i << "\n";
	this->_f = static_cast<float>(this->_c);
	std::cout << "Float: " << std::fixed << std::setprecision(this->_afterDecPoint) << this->_f << "f\n";
	this->_d = static_cast<double>(this->_c);
	std::cout << "Double: " << std::fixed << std::setprecision(this->_afterDecPoint) << this->_d << std::endl;
}

void	Types::convertInt() {
	if (this->_i < std::numeric_limits<char>::min() || this->_i > std::numeric_limits<char>::max())
		std::cout << "Char: impossible\n";
	else {
		this->_c = static_cast<char>(this->_i);
		if (isprint(this->_c) && this->_c != ' ')
			std::cout << "Char: '" << this->_c << "'\n";
		else
			std::cout << "Char: non displayable\n";
	}
	std::cout << "Int: " << this->_i << "\n";
	this->_f = static_cast<float>(this->_i);
	if (static_cast<int>(this->_f) != this->_i)
		std::cout << "Float: precision loss during conversion" << RED << " {" << std::fixed << std::setprecision(this->_afterDecPoint) << this->_f << "f}\n" << RESET;
	else
		std::cout << "Float: " << std::fixed << std::setprecision(this->_afterDecPoint) << this->_f << "f\n";
	this->_d = static_cast<double>(this->_i);
	std::cout << "Double: " << std::fixed << std::setprecision(this->_afterDecPoint) << this->_d << std::endl;
}

void	Types::convertFloat() {
	if (this->_f < std::numeric_limits<char>::min() || this->_f > std::numeric_limits<char>::max() || std::isnan(this->_f))
		std::cout << "Char: impossible\n";
	else {
		this->_c = static_cast<char>(this->_f);
		if (isprint(this->_c) && this->_c != ' ')
			std::cout << "Char: '" << this->_c << "'\n";
		else
			std::cout << "Char: non displayable\n";
	}
	if (this->_f < std::numeric_limits<int>::min() || this->_f > std::numeric_limits<int>::max() || std::isnan(this->_f))
		std::cout << "Int: impossible\n";
	else
		std::cout << "Int: " << static_cast<int>(this->_f) << "\n";
	std::cout << "Float: " << std::fixed << std::setprecision(this->_afterDecPoint) << this->_f << "f\n";
	this->_d = static_cast<double>(this->_f);
	std::cout << "Double: " << std::fixed << std::setprecision(this->_afterDecPoint) << this->_d << std::endl;
}

void	Types::convertDouble() {
	if (this->_d < std::numeric_limits<char>::min() || this->_d > std::numeric_limits<char>::max() || std::isnan(this->_d))
		std::cout << "Char: impossible\n";
	else {
		this->_c = static_cast<char>(this->_d);
		if (isprint(this->_c) && this->_c != ' ')
			std::cout << "Char: '" << this->_c << "'\n";
		else
			std::cout << "Char: non displayable\n";
	}
	if (this->_d < std::numeric_limits<int>::min() || this->_d > std::numeric_limits<int>::max() || std::isnan(this->_d))
		std::cout << "Int: impossible\n";
	else
		std::cout << "Int: " << static_cast<int>(this->_d) << "\n";
	this->_f = static_cast<float>(this->_d);
	std::ostringstream doubleStream, floatStream;
	doubleStream << std::fixed << std::setprecision(this->_afterDecPoint) << this->_d;
	floatStream << std::fixed << std::setprecision(this->_afterDecPoint) << this->_f;
	std::string doubleString = doubleStream.str();
	std::string floatString = floatStream.str();
	if ((this->_d < -std::numeric_limits<float>::max() || this->_d > std::numeric_limits<float>::max()) && !std::isinf(this->_d))
		std::cout <<"Float: impossible\n";
	else if (doubleString != floatString)
		std::cout << "Float: precision loss during conversion" << RED << " {" << floatString << "f}\n" << RESET;
	else
		std::cout << "Float: " << floatString << "f\n";
	std::cout << "Double: " << doubleString << std::endl;
}

void	Types::checkSpecial() {
	if (this->_literal == "+inff" || this->_literal == "-inff" || \
		this->_literal == "inff" || this->_literal == "nanf") {
		if (this->_literal == "+inff" || this->_literal == "inff")
			this->_f = std::numeric_limits<float>::infinity();
		else if (this->_literal == "-inff")
			this->_f = -std::numeric_limits<float>::infinity();
		else if (this->_literal == "nanf")
			this->_f = std::numeric_limits<float>::quiet_NaN();
		throw FLOAT;
	}
	if (this->_literal == "+inf" || this->_literal == "-inf" || \
		this->_literal == "inf" || this->_literal == "nan") {
		if (this->_literal == "+inf" || this->_literal == "inf")
			this->_d = std::numeric_limits<double>::infinity();
		else if (this->_literal == "-inf")
			this->_d = -std::numeric_limits<double>::infinity();
		else if (this->_literal == "nan")
			this->_d = std::numeric_limits<double>::quiet_NaN();
		throw DOUBLE;
	}
}

void	Types::checkInt() {
	try {
		size_t	i;
		int		numI = std::stoi(this->_literal, &i);

		if (i != this->_literal.length())
			throw ParseException("String contains non-digits");
		this->_i = numI;
	}
	catch (std::out_of_range&) {
		throw ParseException("stoi: out of range");
	}
	catch (std::invalid_argument&) {
		throw ParseException("stoi: invalid argument");
	}
	throw INT;
}

void	Types::checkFloat() {
	try {
		size_t	i;
		std::string buf = this->_literal;
		!buf.empty() ? buf.pop_back() : throw INVALID ;
		float numF = std::stof(buf, &i);
		if (i != buf.length())
			throw ParseException("String contains non-digits");
		std::ostringstream floatStream;
		floatStream << std::fixed << std::setprecision(this->_afterDecPoint);
		floatStream << numF;
		std::string checkFloat = floatStream.str();
		if (this->_trimmedLit != checkFloat)
			throw ParseException("precision loss in string to float: " + checkFloat);
		this->_f = numF;
	}
	catch (std::out_of_range&) {
		throw ParseException("stof: out of range");
	}
	catch (std::invalid_argument&) {
		throw ParseException("stof: invalid argument");
	}
	throw FLOAT;
}

void	Types::checkDouble() {
	try {
		size_t	i;
		double	numD = std::stod(this->_literal, &i);
		if (i != this->_literal.length())
			throw ParseException("String contains non-digits");
		std::ostringstream doubleStream;
		doubleStream << std::fixed << std::setprecision(this->_afterDecPoint);
		doubleStream << numD;
		std::string checkDouble = doubleStream.str();
		if (this->_trimmedLit != checkDouble)
			throw ParseException("precision loss in string to double: " + checkDouble);
		this->_d = numD;
	}
	catch (std::out_of_range&) {
		throw ParseException("stod: out of range");
	}
	catch (std::invalid_argument&) {
		throw ParseException("stod: invalid argument");
	}
	throw DOUBLE;
}

type	Types::getType() {
	try {
		if (this->_literal.length() < 1)
			throw ParseException("empty string");
		if (this->_literal.length() == 3 && this->_literal[0] == '\'' && this->_literal[2] == '\'') {
			if (isprint(this->_literal[1]) && this->_literal[1] != ' ') {
				this->_c = this->_literal[1];
				throw CHAR;
			}
			else
				throw ParseException("non printable char");
		}
		if (this->_literal.length() == 1 && !isdigit(this->_literal[0]))
			throw ParseException("invalid char format");
		this->checkSpecial();
		this->basicChecks();
		if (this->_literal.back() == 'f' || this->_literal.back() == 'F')
			this->checkFloat();
		else if (this->_literal.find('.') != std::string::npos)
			this->checkDouble();
		else
			this->checkInt();
	} catch (type t) {
		return (t);
	}
	catch (const ParseException& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		return (INVALID);
	}
	return (INVALID);
}

Types::ParseException::ParseException(const std::string& message) : _message(message) {}
const char* Types::ParseException::what() const noexcept  { return (this->_message.c_str()); }
