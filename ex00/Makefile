# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:59 by tponutha          #+#    #+#              #
#    Updated: 2024/01/16 07:28:16 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./Animal

CXX		= c++
CFLAG	= -Wall -Werror -Wextra -std=c++98
RM		= rm -f

DIR		= ./
SRC		= main.cpp\
			Animal.cpp\
			Cat.cpp\
			Dog.cpp\
			WrongAnimal.cpp\
			WrongCat.cpp

HEADER	= Animal.hpp\
			Cat.hpp\
			Dog.hpp\
			WrongAnimal.hpp\
			WrongCat.hpp

SRCS	= $(addprefix $(DIR), $(SRC))
HEADERS	= $(addprefix $(DIR), $(HEADER))
OBJ		= $(SRCS:.cpp=.o)

%.o: %.cpp $(HEADERS) Makefile
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