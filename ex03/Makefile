# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 13:09:01 by jhvalenc          #+#    #+#              #
#    Updated: 2026/10/06 13:09:26 by jhvalenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = intern

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = Bureaucrat.cpp \
	      AForm.cpp \
	      ShrubberyCreationForm.cpp \
	      RobotomyRequestForm.cpp \
	      PresidentialPardonForm.cpp \
	      Intern.cpp \
	      main.cpp

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
