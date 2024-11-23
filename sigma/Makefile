all: bytemap draw
bytemap: bytemap.cc
	g++ -o bytemap bytemap.cc
draw: bytemap
	./bytemap <drawing.in > drawing.out
clean:
	rm -f *.o
	rm -f *.out
