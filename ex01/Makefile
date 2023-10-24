# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 02:44:48 by tponutha          #+#    #+#              #
#    Updated: 2023/10/25 03:19:48 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

CXX		= c++
CFLAG	= -Wall -Werror -Wextra -std=c++98

DIR		= ./
HEADER	= PhoneBook.hpp \
			Contact.hpp

SRC		= main.cpp \
			PhoneBook.cpp \
			Contact.cpp

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