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
## Tests
These tests were performed with the help of the <a href="https://github.com/cubing/AnimCubeJS">AnimCubeJs</a> Rubik's cube simulator.

### Test (I)
<table style='border: 0'>
  <thead><th>Stage</th><th>Cube State</th><th>Move Sequence</th></thead>
  <tr><td>Scrambled Cube</td><td><img src='./tests/test01/images/scrambled.png' style='width: 200px'></td><td><b>B2 D U2 L R2 B' U' R U R' U2 R' D2 R2 U D B' F' U' R2 D' B' F2 D B</b></td></tr>
  <tr><td>Corners Oriented</td><td><img src='./tests/test01/images/corners_oriented.png' style='width: 200px'></td><td><b>L2 D' L2 D F2 U' F U L2 U L2 U' F R2 D' F L2 D' L2 D F2 U' F U L2 U L2 U' F F' D R2 F2 L2 D' L2 D F2 U' F U L2 U L2 U' F F2 D' F2 L2 D' L2 D F2 U' F U L2 U L2 U' F F2 D</b></td></tr>
  <tr><td>Corners Solved</td><td><img src='./tests/test01/images/corners_solved.png' style='width: 200px'></td><td><b>L D F' F' U B' U2 F U' F' U2 F B U' F D' L' D2 F2 F' U B' U2 F U' F' U2 F B U' F2 D2 L2 F2 F' U B' U2 F U' F' U2 F B U' F2 L2 D' F2 F' U B' U2 F U' F' U2 F B U' F2 D L2 F2 F' U B' U2 F U' F' U2 F B U' F2 L2</b></td></tr>
  <tr><td>Edges Solved</td><td><img src='./tests/test01/images/fully_solved.png' style='width: 200px'></td><td><b>F' U B' U2 F U' F' U2 F B U' E' L D M2 F' U B' U2 F U' F' U2 F B U' M2 D' L' E L D M2 F' U B' U2 F U' F' U2 F B U' M2 D' L' M F' U B' U2 F U' F' U2 F B U' M' D' M F' U B' U2 F U' F' U2 F B U' M' D D2 M F' U B' U2 F U' F' U2 F B U' M' D2 M D2 M F' U B' U2 F U' F' U2 F B U' M' D2 M' L2 D' M F' U B' U2 F U' F' U2 F B U' M' D L2 D M F' U B' U2 F U' F' U2 F B U' M' D' F' U B' U2 F U' F' U2 F B U' L' D M2 F' U B' U2 F U' F' U2 F B U' M2 D' L M D2 M F' U B' U2 F U' F' U2 F B U' M' D2 M'</b></td></tr>
</table>

### Test (II)
<table style='border: 0'>
  <thead><th>Stage</th><th>Cube State</th><th>Move Sequence</th></thead>
  <tr><td>Scrambled Cube</td><td><img src='./tests/test02/images/scrambled.png' style='width: 200px'></td><td><b>U F2 B2 U F L' U' F2 L' R2 D L' F2 U' D2 B2 F R' D' B' D2 L' D2 L2 D</b></td></tr>
  <tr><td>Corners Oriented</td><td><img src='./tests/test02/images/corners_oriented.png' style='width: 200px'></td><td><b>R' D' F L2 D' L2 D F2 U' F U L2 U L2 U' F F' D R R2 D' F F' U L2 U' L2 U' F' U F2 D' L2 D L2 F' D R2 D F2 L2 D' L2 D F2 U' F U L2 U L2 U' F F2 D' F2 F' U L2 U' L2 U' F' U F2 D' L2 D L2 F2 D' F2 F' U L2 U' L2 U' F' U F2 D' L2 D L2 F2 D</b></td></tr>
  <tr><td>Corners Solved</td><td><img src='./tests/test02/images/corners_solved.png' style='width: 200px'></td><td><b>L D F' F' U B' U2 F U' F' U2 F B U' F D' L' L2 F2 F' U B' U2 F U' F' U2 F B U' F2 L2 F' U B' U2 F U' F' U2 F B U' D2 F2 F' U B' U2 F U' F' U2 F B U' F2 D2 D F2 F' U B' U2 F U' F' U2 F B U' F2 D' D' F2 F' U B' U2 F U' F' U2 F B U' F2 D F2 F' U B' U2 F U' F' U2 F B U' F2
</b></td></tr>
  <tr><td>Edges Solved</td><td><img src='./tests/test02/images/fully_solved.png' style='width: 200px'></td><td><b>F' U B' U2 F U' F' U2 F B U' M2 D2 M F' U B' U2 F U' F' U2 F B U' M' D2 M2 D M2 F' U B' U2 F U' F' U2 F B U' M2 D' M' F' U B' U2 F U' F' U2 F B U' M L' D M2 F' U B' U2 F U' F' U2 F B U' M2 D' L D' M2 F' U B' U2 F U' F' U2 F B U' M2 D E2 L D' M F' U B' U2 F U' F' U2 F B U' M' D L' E2 L D' M F' U B' U2 F U' F' U2 F B U' M' D L' M F' U B' U2 F U' F' U2 F B U' M' L2 D M2 F' U B' U2 F U' F' U2 F B U' M2 D' L2 L2 D' M F' U B' U2 F U' F' U2 F B U' M' D L2 E' L D' M F' U B' U2 F U' F' U2 F B U' M' D L' E M2 F' U B' U2 F U' F' U2 F B U' M2 E' L D' M F' U B' U2 F U' F' U2 F B U' M' D L' E'</b></td></tr>
</table>
