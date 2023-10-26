# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 13:58:49 by tponutha          #+#    #+#              #
#    Updated: 2023/10/27 03:30:00 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= brain

CXX		= c++
CFLAG	= -Wall -Werror -Wextra -std=c++98
RM		= rm -f

DIR		= ./
SRC		= main.cpp \
			Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp

HEADER	= Weapon.hpp \
			HumanA.hpp \
			HumanB.hpp
			
SRCS	= $(addprefix $(DIR), $(SRC))
HEADERS	= $(addprefix $(DIR), $(HEADER))
SRCS	= $(addprefix $(DIR), $(SRC))
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