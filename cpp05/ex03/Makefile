
CXX= g++
CXXFLAGS= -std=c++11 -Wall -Wextra -Werror

NAME= intern

HEADER= includes/Bureaucrat.hpp \
		includes/AForm.hpp \
		includes/PresidentialPardonForm.hpp \
		includes/RobotomyRequestForm.hpp \
		includes/ShrubberyCreationForm.hpp \
		includes/Intern.hpp \
		includes/Colours.hpp

SDIR= src
SOURCE= main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

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