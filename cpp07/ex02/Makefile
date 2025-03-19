
CXX= g++
CXXFLAGS= -std=c++11 -Wall -Wextra -Werror
IFLAGS= -Iincludes -Itemplates

NAME= ex02

HEADER= includes/Array.hpp \
		includes/Colours.hpp

TEMPLATES= templates/Array.tpp

SDIR= src
SOURCE= main.cpp

ODIR= obj
OBJECT = $(addprefix $(ODIR)/,$(SOURCE:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECT)
	$(CXX) $(CXXFLAGS) $(IFLAGS) $^ -o $@

$(ODIR):
	@mkdir -p $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(HEADER) $(TEMPLATES) | $(ODIR)
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