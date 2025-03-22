# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:59 by tponutha          #+#    #+#              #
#    Updated: 2025/03/23 03:55:03 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name & Properties
NAME	:= ./Bureaucrat

# Compiler Properties
CXX			:= c++
CXX_WFLAG	:= -Wall -Werror -Wextra
CXX_STDFLAG	:= -std=c++98
CFLAG		:= $(CXX_WFLAG) $(CXX_STDFLAG)
RM			:= rm -f

# Project
DIR		:= ./
SRC		:= main.cpp \
			Bureaucrat.cpp
HEADER	:= Bureaucrat.hpp
SRCS	:= $(addprefix $(DIR), $(SRC))
HEADERS	:= $(addprefix $(DIR), $(HEADER))

# Objects
OBJ		:= $(SRCS:.cpp=.o)

# Main Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS) Makefile
	$(CXX) $(CFLAG) -c $< -o $(<:.cpp=.o)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all