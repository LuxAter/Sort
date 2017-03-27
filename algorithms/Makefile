CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(notdir $(CPP_FILES:.cpp=.o))
ALGOS = binary_tree block bubble cocktail comb cube cycle gnome heap in_place_merge insertion intro library merge odd_even patience quick selection shell smooth strand tim tournament

all: $(OBJ_FILES) subsystem

%.o: %.cpp %.hpp
	@printf "Compiling $*.cpp...\n"
	@$(COMPILER) $(FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	@for dir in $(ALGOS); do \
	  $(MAKE) -C $$dir; \
	done
