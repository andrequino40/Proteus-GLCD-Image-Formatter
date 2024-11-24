INPUT_FOLDER = ./inputs
INPUT_FILE = hector.inp

all: converter drawing
converter: bytemap_converter.cc
	g++ -o bytemap_converter.o bytemap_converter.cc
drawing: converter
	./bytemap_converter.o < $(INPUT_FOLDER)/$(INPUT_FILE)
clean:
	rm bytemap_converter.o drawing.h
