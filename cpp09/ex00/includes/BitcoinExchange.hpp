
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define DATABASE "data.csv"

# include <map>
# include <string>

struct Date {
	int year;
	int month;
	int day;

	bool operator<(Date const& other) const {
		if (year != other.year)
			return (year < other.year);
		if (month != other.month)
			return (month < other.month);
		return (day < other.day);
	}
};

class BitcoinExchange {
	private:
		Date _today;
		std::map<Date, float>	_dataBase;

		BitcoinExchange(BitcoinExchange const& other) = delete;
		BitcoinExchange& operator=(BitcoinExchange const& other) = delete;
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	outputCalculations(std::string const& d, std::string const& v);
};

std::map<Date, float> const	parseDataBase(std::string const& file_name, Date const& today);
void	readInput(std::string const& input_file);
Date	getTodaysDate();
float 	parseFloat(std::string const& value);
Date	parseDate(std::string const& key);

#endif
