# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:59 by tponutha          #+#    #+#              #
#    Updated: 2025/06/16 17:44:41 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name & Properties
NAME	:= ./RPN
RM		:= rm -f
RMDIR	:= rm -rf
MKDIR	:= mkdir -p

# Compiler Properties
CXX			:= c++
CXX_WFLAG	:= -Wall -Werror -Wextra
CXX_MFLAG	:= -MP -MD
CXX_STDFLAG	:= -std=c++98
CXXFLAG		:= $(CXX_WFLAG) $(CXX_STDFLAG)

# Directories
BUILD_DIR	:= ./build
SRC_DIR		:= ./
INCLUDE_DIR	:= ./

# Source
SRC		:= main.cpp \
			RPN.cpp
SRCS	:= $(addprefix $(SRC_DIR), $(SRC))

# Objects & Dependencies File
OBJS	:= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS	:= $(OBJS:.o=.d)

# Main Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o:	%.cpp
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAG) $(CXX_MFLAG) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RMDIR) $(BUILD_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	$(NAME)
	$(NAME) "1 2 +"
	$(NAME) "3 4 -"
	$(NAME) "2 3 *"
	$(NAME) "8 4 /"
	$(NAME) "5 1 2 + 4 * + 3 -"
	$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	$(NAME) "7 7 * 7 -"
	$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	$(NAME) "5 1 2 + 4 * + 3 - 2 /"
	$(NAME) "1 2 + 3 4 + * 5 + 6 7 + * 8 +"
	$(NAME) "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +"
	$(NAME) "1 2 + 3 * 0 / 4 + 5 +"
	$(NAME) "1 2 + 3 4 +"
	$(NAME) "2 3 + + "

-include $(DEPS)