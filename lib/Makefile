##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

RM		= rm -f

CXX		= g++ -shared -fPIC

CXXFLAGS	= -W -Wall -Wextra -g3
CXXFLAGS	+= -I./include/ -I.

NAMENCURSE	= ../lib_arcade_ncurses.so

NAMESFML	= ../lib_arcade_sfml.so

SRCSNCURSE	= srcs/libncurses.cpp ../core/environment/Environment.cpp

SRCSSFML	= srcs/libsfml.cpp ../core/environment/Environment.cpp

OBJSNCURSE	= $(SRCSNCURSE:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

all:	$(NAMENCURSE) $(NAMESFML)

sfml:	$(NAMESFML)

ncurse:	$(NAMENCURSE)

$(NAMENCURSE): $(OBJSNCURSE)
	$(CXX) $(OBJSNCURSE) -o $(NAMENCURSE) -lncurses -ldl

$(NAMESFML): $(OBJSSFML)
	$(CXX) $(OBJSSFML) -o $(NAMESFML) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJSNCURSE) $(OBJSSFML)

fclean: clean
	$(RM) $(NAMENCURSE) $(NAMESFML)

re:	fclean all

.PHONY: all clean fclean re
