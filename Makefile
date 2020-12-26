PROGRAM = parser
PROGRAM1 = ./parser
GRAMMARFOLDER = ./Linux/
BUILDFOLDER = build/
BUILDIO = build/io
NASM = nasm
BUILDIOEXIST = $(shell if [ -d $(BUILDIO) ]; then echo "exist"; else echo "notexist"; fi;)
GRAMMAREXIST = $(shell if [ -d $(GRAMMARFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
BUILDEXIST = $(shell if [ -d $(BUILDFOLDER) ]; then echo "exist"; else echo "notexist"; fi;)
DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./ -name "*.cpp")
OBJ = $(SRC:%.cpp=%.o)
CXX = g++
FLEX = flex
BISON = bison
CXXVER = c++11

$(PROGRAM): $(OBJ)
	$(CXX) -o $(PROGRAM) $(OBJ) -std=$(CXXVER) -g

run: ./lexical/lexical.l ./lexical/ch.y
ifeq ($(GRAMMAREXIST),notexist)
	mkdir $(GRAMMARFOLDER)
endif
	$(BISON) --output="./Linux/grammar.tab.cpp" --defines="./Linux/grammar.tab.h" ./lexical/ch.y
	$(FLEX) --outfile="./Linux/lexer.flex.cpp" ./lexical/lexical.l
	sed -i "1i\#include \"../grammar/Nodes.h\"" ./Linux/grammar.tab.h 

%.o: %.cpp $(DEPS)
	$(CXX) -c $< -o $@ -std=$(CXXVER) -g

clean:
	rm -rf $(GRAMMARFOLDER) $(OBJ) $(PROGRAM) $(BUILDFOLDER) grammar/InterMediate/asm_io.o

build:
ifeq ($(BUILDEXIST),notexist)
	mkdir $(BUILDFOLDER)
endif
ifeq ($(BUILDIOEXIST),notexist)
	mkdir $(BUILDIO)
endif
	$(NASM) -f elf -d ELF_TYPE grammar/InterMediate/asm_io.asm -o grammar/InterMediate/asm_io.o
	cp $(PROGRAM) $(BUILDFOLDER)
	cp grammar/InterMediate/asm_io.o $(BUILDIO)
	cp grammar/InterMediate/asm_io.inc $(BUILDIO)
	cp -r test/ $(BUILDFOLDER)
	cp example/Makefile $(BUILDFOLDER)
	# $(PROGRAM1) ./test.c
	# $(NASM) -f elf test.asm -o test.o
	# $(CXX) -o test test.o grammar/InterMediate/asm_io.o -m32


	