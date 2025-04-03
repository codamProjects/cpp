
CXX= g++
CXXFLAGS= -std=c++17 -Wall -Wextra -Werror
IFLAGS= -Iincludes

NAME= PmergeMe

HEADER= includes/PmergeMe.hpp \
		includes/PmergeMe.tpp

SDIR= src
SOURCE= main.cpp \
		PmergeMe.cpp

ODIR= obj
OBJECT = $(addprefix $(ODIR)/,$(SOURCE:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECT)
	$(CXX) $(CXXFLAGS) $(IFLAGS) $^ -o $@

$(ODIR):
	@mkdir -p $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(HEADER) | $(ODIR)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@if [ -d "$(ODIR)" ]; then \
		rm -r $(ODIR); \
	fi

fclean: clean
	@if [ -x "$(NAME)" ]; then \
		rm $(NAME); \
	fi

re: fclean all

.PHONY: all clean fclean re