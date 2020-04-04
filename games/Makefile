##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

RM		= rm -f

CXX		= g++ -shared -fPIC -g

CXXFLAGS	= -W -Wall -Wextra -I. -I./pacman/include/ -I./snake/include/

NAMEPACMAN	= ../lib_arcade_pacman.so

NAMENIBBLER	= ../lib_arcade_nibbler.so

SRCSPACMAN	= pacman/src/pacman.cpp

SRCSNIBBLER	= snake/src/snake.cpp

OBJSPACMAN	= $(SRCSPACMAN:.cpp=.o)

OBJSNIBBLER	= $(SRCSNIBBLER:.cpp=.o)

all:	$(NAMEPACMAN) $(NAMENIBBLER)

nibbler:	$(NAMENIBBLER)

pacman:	$(NAMEPACMAN)

$(NAMEPACMAN): $(OBJSPACMAN)
	$(CXX) $(OBJSPACMAN) -o $(NAMEPACMAN)

$(NAMENIBBLER): $(OBJSNIBBLER)
	$(CXX) $(OBJSNIBBLER) -o $(NAMENIBBLER)

clean:
	$(RM) $(OBJSPACMAN) $(OBJSNIBBLER)

fclean: clean
	$(RM) $(NAMEPACMAN) $(NAMENIBBLER)

re:	fclean all

.PHONY: all clean fclean re
