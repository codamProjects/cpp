
CXX= g++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

NAME= violence

HEADERS= src/HumanA.hpp \
		src/HumanB.hpp \
		src/Weapon.hpp

SDIR= src
SOURCE= main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp 

ODIR= obj
OBJECT= $(addprefix $(ODIR)/,$(SOURCE:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECT)
	   $(CXX) $(CXXFLAGS) $^ -o $@

$(ODIR):
	@mkdir -p $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(HEADERS)| $(ODIR)
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
