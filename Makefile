INPUT_FOLDER = ./inputs
INPUT_FILE = troll.inp

all: converter converter
conveter: conveter.cc
	g++ -o conveter.o conveter.cc
drawing: conveter.o
	./conveter.o < $(INPUT_FOLDER)/$(INPUT_FILE)
clean:
	rm conveter.o
