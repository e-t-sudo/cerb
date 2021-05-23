# cerb
Cerb is a C++ implementation of a simple algorithm to solve a 3x3x3 Rubik's Cube.
## Don't get your hopes up
In contrast to the conventional approaches like the Beginner's method, Roux method, ZZ and Fridrich method which are targeted towards minimizing the total number of moves required to solve the cube, Cerb solves the cube piece by piece. Since there are eight corner pieces and twelve edge pieces in a 3x3x3 Rubik's Cube, it would take a little more than twenty iterations to get all of them to their respective positions. Further, the separation of orientation and permutation of corner peices adds to the verbosity of the solution. The average number of quarter moves required for a full solve is roughly about 500-600, which corresponds to atleast two-three minutes. So we're certainly not making the Guinness book, least of all in the minimum-moves category!



## Usage
Insert your cube configuration in two .txt files, one for the corner pieces and the other for the edge pieces. Place the cube config files in the `./test_cubes/` directory and instantiate `Corners::Corners("./test_cubes/cornerConfig.txt", "./test_cubes/solvedCorners.txt")` where `cornerConfig.txt` can be replaced by the name of your corner config file, and `solvedCorners.txt` is already present in the directory. Follow the below lettering scheme to format your `cornerConfig.txt` file. Enter space separated lowercase letters for the colors occuring at positions `a, b, c, d, ...x`. We are basically going from top-left-front corner to the bottom-left-back corner traversing each corner in the clockwise direction.


<img src="./piece_labels/corner_labels.png">

Follow the lettering scheme given below to format the `edgeConfig.txt` file and instantiate `Edges::Edges("./test_cubes/edgeConfig.txt", "./test_cubes/solvedEdges.txt")` replacing `edgeConfig.txt` by the name of your edge configuration file.

<img src="./piece_labels/edge_labels.png">

After doing all the prework, let's compile the project into a neat little executable.


## Compilation
The entire project is divided into three class files, so compiling the program ought to be simple enough. A Makefile is provided in the root directory of the project which simplies the compilation and linking process. 
#### Manual Compilation
If `make` is not installed, then the project can be manually compiled with the `g++` compiler

```shell 
g++ -c main.cpp headers/Cube.cpp headers/Edges.cpp headers/Corners.cpp
```

This compiles the source files into object files which can then be linked into an `cerb`

```shell
g++ main.o Cube.o Edges.o Corners.o -o cerb
```

Finally, to generate the solution to cube configuration in the `test_cubes/edges.txt` and `test_cubes/corners.txt`, just run `./cerb` 
