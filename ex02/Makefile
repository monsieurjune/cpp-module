# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:13:25 by tponutha          #+#    #+#              #
#    Updated: 2023/11/13 20:12:35 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap

CXX		= c++
CFLAG	= -Wall -Werror -Wextra -std=c++98
RM		= rm -f

DIR		= ./
SRC		= main.cpp\
			ClapTrap.cpp\
			FragTrap.cpp
HEADER	= ClapTrap.hpp\
			FragTrap.hpp
SRCS	= $(addprefix $(DIR), $(SRC))
HEADERS	= $(addprefix $(DIR), $(HEADER))

OBJ		= $(SRCS:.cpp=.o)
.cpp.o:
	$(CXX) $(CFLAG) -c $< -o $(<:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CFLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re