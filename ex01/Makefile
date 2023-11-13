# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:13:25 by tponutha          #+#    #+#              #
#    Updated: 2023/11/13 23:52:50 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ScavTrap

CXX		= c++
CFLAG	= -Wall -Werror -Wextra -std=c++98
RM		= rm -f

DIR		= ./
SRC		= main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp
HEADER	= ClapTrap.hpp\
			ScavTrap.hpp
SRCS	= $(addprefix $(DIR), $(SRC))
HEADERS	= $(addprefix $(DIR), $(HEADER))

OBJ		= $(SRCS:.cpp=.o)
.cpp.o:
	$(CXX) $(CFLAG) -c $< -o $(<:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADERS)
	$(CXX) $(CFLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
