
CXX= g++
CXXFLAGS= -std=c++11 -Wall -Wextra -Werror -Wshadow

NAME= magic

HEADER= src/AMateria.hpp \
		src/Character.hpp \
		src/Cure.hpp \
		src/Ice.hpp \
		src/ICharacter.hpp \
		src/IMateriaSource.hpp \
		src/MateriaSource.hpp

SDIR= src
SOURCE= main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

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
