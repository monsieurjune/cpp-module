# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:59 by tponutha          #+#    #+#              #
#    Updated: 2025/10/01 17:49:11 by tponutha         ###   ########.fr        #
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

# Main Source
MAIN_DIR	:= $(SRC_DIR)
MAIN_SRC	:= main.cpp \
				RPN.cpp
MAIN_SRCS	:= $(addprefix $(MAIN_DIR), $(MAIN_SRC))

# Objects & Dependencies File
DIRS		:= $(MAIN_DIR)
SRCS		:= $(MAIN_SRCS)
OBJS		:= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
OBJS_DIR	:= $(addprefix $(BUILD_DIR)/, $(DIRS))
DEPS		:= $(OBJS:.o=.d)

# Main Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	$(MKDIR) $@

$(BUILD_DIR)/%.o:	%.cpp
	$(CXX) $(CXXFLAG) $(CXX_MFLAG) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RMDIR) $(BUILD_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

# Misc Rules
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
