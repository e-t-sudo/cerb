#ifndef CORNERS_H
#define CORNERS_H
#include "Cube.hpp"
class Corners{
    public:
    Cube testCube;
    typedef struct corner{
        char c1, c2, c3;
    }corner;
    const std::string jPerm = "F' U B' U2 F U' F' U2 F B U'";
    const std::string clockCommutator = "F' U L2 U' L2 U' F' U F2 D' L2 D L2"; 
    const std::string counterCommutator = testCube.reverseSequence(clockCommutator);
    const int buffer = 3;
    int cornerMoveCounter = 0;
    corner corners[8], solvedCorners[8];
    Corners(std::string, std::string);
    bool compareCorners(corner, corner);
    std::vector<int> cornerOrientVector;
    void orient(void);
    std::string toOrientBuffer(int);
    std::string revertFromOrientBuffer(int);
    void printCornerOrientMoves(void);
    
    int getPos(corner);
    std::vector<int> cornerPermuteVector;
    std::vector<int> alreadySolved; //only for permutation part
    int nextUnsolved(void);
    std::vector<int> solvedCornerPeices;
    void permute(void);
    std::string toBuffer(int);
    std::string revertFromBuffer(int);
    void printCornerPermuteMoves(void);
};
#endif
