CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(notdir $(CPP_FILES:.cpp=.o))
TOTAL_OBJ_FILES = $(wildcard */*.o) $(wildcard */*/*.o) $(wildcard */*/*/*.o)
HEADER_FILES = $(wildcard *.h) $(wildcard */*.h) $(wildcard */*/*.h) $(wildcard */*/*/*.h)
CC = clang++
COMPILER_FLAGS = -MMD -std=c++11 -w -c
LINKER_FLAGS = -lappareo -lncurses -lpessum
PROGRAM_NAME = sort

all: subsystem top_obj $(PROGRAM_NAME)
	clear
	@echo Compleated compiling $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ_FILES) $(wildcard */*.o) $(wildcard */*/*.o) $(wildcard */*/*/*.o)
	setterm -foreground red
	$(CC) $(OBJ_FILES) $(TOTAL_OBJ_FILES) -o $(PROGRAM_NAME) $(LINKER_FLAGS)
	setterm -default

%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : top_obj
top_obj:$(OBJ_FILES)

.PHONY : subsystem
subsystem:
	export CC
	cd algorithms && $(MAKE)
	setterm -default

.PHONY : clean
clean:
	rm -f *.o
	rm -f *.d
	rm -f */*.o
	rm -f */*.d
	rm -f */*/*.o
	rm -f */*/*.d
	rm -f */*/*/*.o
	rm -f */*/*/*.d
	clear
	@echo Cleared all '.o' and '.d' files

.PHONY : tar
tar: clean
	rm $(PROGRAM_NAME).tar.gz
	tar -zcvf $(PROGRAM_NAME).tar.gz ../Sort

.PHONY : log
log:
	less log_output.log

.PHONY : help
help:
	@echo make clean
	@echo make tar
	@echo make log
	@echo make new

.PHONY : new
new: clean all
