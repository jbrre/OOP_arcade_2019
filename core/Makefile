##
## EPITECH PROJECT, 2019
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

RM		= rm -f

CXX		= g++

CPPFLAGS	=	-I..

NAME	= ../arcade

SRCS	= core.cpp	\
		environment/Environment.cpp \
		main.cpp

OBJS	= $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CPPFLAGS) -o $(NAME) -ldl

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

debug: CPPFLAGS += -g3
debug: fclean all

re:	fclean all

.PHONY: all clean fclean re