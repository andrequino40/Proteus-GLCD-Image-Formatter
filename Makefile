INPUT_FOLDER = ./inputs
OUTPUT_FOLDER = ./outputs
FILE_NAME = doner
INPUT_FILE = $(FILE_NAME).inp
OUTPUT_FILE = $(FILE_NAME).h


all: converter drawing
converter: bytemap_converter.cc
	g++ -o bytemap_converter.o bytemap_converter.cc
drawing: converter
	./bytemap_converter.o < $(INPUT_FOLDER)/$(INPUT_FILE) > $(OUTPUT_FOLDER)/$(OUTPUT_FILE)
clean:
	rm bytemap_converter.o drawing.h
