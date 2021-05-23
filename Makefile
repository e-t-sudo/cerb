all: compile link clean
compile:
	@echo "Compiling..."
	@g++ -c main.cpp headers/Cube.cpp headers/Edges.cpp headers/Corners.cpp
link:
	@g++ main.o Cube.o Edges.o Corners.o -o cerb
clean:
	@rm *.o
	@echo "Run ./cerb to generate the solution\n"
