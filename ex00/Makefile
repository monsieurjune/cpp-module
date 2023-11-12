# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:14:57 by tponutha          #+#    #+#              #
#    Updated: 2023/11/12 23:15:13 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME	= Orthodox

# Tool Properties
CXX		= c++
CFLAG	= -Wall -Werror -Wextra -std=c++98 -g
RM		= rm -f

# SOURCE FILES
DIR		= ./
SRC		= main.cpp \
			Fixed.cpp
HEADER	= Fixed.hpp
SRCS	= $(addprefix $(DIR), $(SRC))
HEADERS	= $(addprefix $(DIR), $(HEADER))

# Object
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