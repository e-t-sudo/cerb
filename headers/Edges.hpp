#ifndef EDGES_H
#define EDGES_H
#include "Cube.hpp"
class Edges{
    public:
        Cube testCube;
        typedef struct edge{
            char e1, e2;
        }edge;
        const std::string jPerm = "F' U B' U2 F U' F' U2 F B U'";
        const int buffer = 2;
        int edgeMoveCounter = 0;
        edge edges[12], solvedEdges[12];
        std::vector<int> edgePermuteVector;
        std::vector<int> solvedEdgePeices;
        Edges(std::string, std::string);
        int getPos(edge);
        int normalize(int);
        int denormalize(int);
        int nextUnsolved(void);
        void permute(void);
        std::string toBuffer(int);
        std::string revertFromBuffer(int);
        void printPermuteMoves(void);
        static void solve(std::string, std::string);
	static std::string edgeBuffer[];
};
#endif
