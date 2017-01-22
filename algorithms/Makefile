CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(notdir $(CPP_FILES:.cpp=.o))
COMPILER_FLAGS = -MMD -std=c++11 -w -c
all:subsystem main
main:$(OBJ_FILES)
%.o: %.cpp %.h
	$(CC) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	setterm -foreground red
	cd bubble && $(MAKE)
	setterm -foreground green
	cd bucket && $(MAKE)
	setterm -foreground yellow
	cd counting && $(MAKE)
	setterm -foreground blue
	cd cocktail && $(MAKE)
	setterm -foreground magenta
	cd heap && $(MAKE)
	setterm -foreground cyan
	cd insertion && $(MAKE)
	setterm -foreground white
	cd merge && $(MAKE)
	setterm -foreground red
	cd quick && $(MAKE)
	setterm -foreground green
	cd radix && $(MAKE)
	setterm -foreground yellow
	cd selection && $(MAKE)
	setterm -foreground blue
	cd shell && $(MAKE)
	setterm -foreground magenta
	cd tim && $(MAKE)
	setterm -foreground cyan
	cd binarytree && $(MAKE)
