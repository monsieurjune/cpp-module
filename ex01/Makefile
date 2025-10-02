# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:59 by tponutha          #+#    #+#              #
#    Updated: 2025/10/03 06:36:58 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name & Properties
NAME	:= ./FixedPoint
RM		:= rm -f
RMDIR	:= rm -rf
MKDIR	:= mkdir -p

# Compiler Properties
CXX			:= c++
CXX_WFLAG	:= -Wall -Werror -Wextra -pedantic
CXX_MFLAG	:= -MP -MD
CXX_STDFLAG	:= -std=c++98
CXXFLAG		:= $(CXX_WFLAG) $(CXX_STDFLAG)

# Directories
BUILD_DIR	:= ./build
SRC_DIR		:= ./
INCLUDE_DIR	:= ./

# Source
MAIN_DIR	:= $(SRC_DIR)
MAIN_SRC	:= main.cpp \
				Fixed.cpp
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

-include $(DEPS)
