#include "./headers/Cube.hpp"
#include "./headers/Edges.hpp"
#include "./headers/Corners.hpp"

int main(int argc, char * argv[]){
    Corners cornerLattice("./test_cubes/corners.txt", "./test_cubes/solvedCorners.txt");
    cornerLattice.orient();
    cornerLattice.printCornerOrientMoves();
    cornerLattice.permute();
    cornerLattice.printCornerPermuteMoves();
    Edges edgeLattice("./test_cubes/edges.txt", "./test_cubes/solvedEdges.txt");
    edgeLattice.permute();
    edgeLattice.printPermuteMoves();
}