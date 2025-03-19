
CXX= g++
CXXFLAGS= -std=c++11 -Wall -Wextra -Werror -Wshadow

NAME= pets

HEADER= src/Animal.hpp \
		src/Dog.hpp \
		src/Cat.hpp \
		src/wrongCat.hpp \
		src/wrongAnimal.hpp

SDIR= src
SOURCE= main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		wrongCat.cpp \
		wrongAnimal.cpp

ODIR= obj
OBJECT= $(addprefix $(ODIR)/,$(SOURCE:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECT)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(ODIR):
	@mkdir -p $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(HEADER) | $(ODIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
