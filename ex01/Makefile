# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:59 by tponutha          #+#    #+#              #
#    Updated: 2025/03/24 06:07:54 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name & Properties
NAME	:= ./Bureaucrat
RM		:= rm -f
RMDIR	:= rm -r
MKDIR	:= mkdir -p

# Compiler Properties
CXX			:= c++
CXX_WFLAG	:= -Wall -Werror -Wextra
CXX_MFLAG	:= -MP -MD
CXX_STDFLAG	:= -std=c++98
CFLAG		:= $(CXX_WFLAG) $(CXX_STDFLAG)

# Directories
BUILD_DIR	:= ./build
SRC_DIR		:= ./
INCLUDE_DIR	:= ./

# Source
SRC		:= main.cpp \
			Bureaucrat.cpp \
			ft_std.cpp \
			GradeOutOfBoundException.cpp \
			Form.cpp
SRCS	:= $(addprefix $(SRC_DIR), $(SRC))

# Objects & Dependencies File
OBJS	:= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS	:= $(OBJS:.o=.d)

# Main Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CFLAG) $(OBJS) -o $(NAME)

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

-include $(DEPS)