#include "Edges.hpp"
#include<fstream>
std::string Edges::edgeBuffer[] = {"M D2 M", "", "", "L2 D M2", "M'", "", "M2 D2 M", "L2 D' M", "L D' M", "L D M2", "E' L D' M", "E' L D M2", "E2 L D' M", "E L' D' M", "L' D M2", "L' D' M", "D2 M", "D M", "M", "D' M", "M2", "D' M2", "D2 M2", "D M2", ""};
Edges::Edges(std::string scrambledFile, std::string solvedFile){
        std::ifstream edgeFile(scrambledFile);
        for(int i=0; i<12; i++){
            edgeFile>>this->edges[i].e1>>this->edges[i].e2;
        }
        edgeFile.close();
        std::ifstream solvedEdgeFile(solvedFile);
        for(int i=0; i<12; i++){
            solvedEdgeFile>>this->solvedEdges[i].e1>>this->solvedEdges[i].e2;
        }
        solvedEdgeFile.close();
}
int Edges::getPos(edge ej){
    char x = ej.e1;
    char y = ej.e2;
    for(int i=0; i<12; i++){
        edge currentEdge = this->solvedEdges[i];
        if(currentEdge.e1==x&&currentEdge.e2==y){
            return i+1;
        }else if(currentEdge.e1==y&&currentEdge.e2==x){
            return -(i+1);
        }
    }
return 0;
}
int Edges::normalize(int pos){
    switch(pos){
        case 1: case 2: case 3: case 4: return pos;
        case -1: case -2: case -3: case -4: return -(pos)+4;
        case 5: case 6: case 7: case 8: return 2*pos-1;
        case -5: case -6: case -7: case -8: return -(pos)*2;
        case 9: case 10: case 11: case 12: return pos+8;
        case -9: case -10: case -11: case -12: return -(pos)+12;
        default: return 0;
    }
}
int Edges::denormalize(int num){
    switch(num){
        case 1: case 2: case 3: case 4: return num;
        case 5: case 6: case 7: case 8: return 4-num;
        case 9: case 11: case 13: case 15: return (num+1)/2;
        case 10: case 12: case 14: case 16: return -num/2;
        case 17: case 18: case 19: case 20: return num-8;
        case 21: case 22: case 23: case 24: return 12-num;
        default: return 0;
    }
}

int Edges::nextUnsolved(void){
    for(int j=1; j<=12; j++){
        bool is_j_present = false;
        for(int i=0; i<this->solvedEdgePeices.size(); i++){
            if(this->solvedEdgePeices[i]==j) is_j_present = true;
        }
        if(is_j_present==false) return j;
    }
return 0;
}
void Edges::permute(void){
    int starter = Edges::buffer;
    int l = 0;
    START:
    this->solvedEdgePeices.push_back(starter);
    for(int f = this->normalize(this->getPos(this->edges[starter-1]));true;){
        if(abs(denormalize(f))==starter){
            this->edgePermuteVector.push_back(f);
            int k = this->nextUnsolved();
            edgePermuteVector.push_back(normalize(k));
            if(k==0) break;
            starter = k;
            goto START;
        }else{
            this->edgePermuteVector.push_back(f);
            this->solvedEdgePeices.push_back(abs(denormalize(f)));
        }
        if(denormalize(f)>0){
            f = this->normalize(this->getPos(this->edges[abs(this->denormalize(f))-1]));
        }else{
            f = this->normalize(-this->getPos(this->edges[abs(this->denormalize(f))-1]));
        }
    }
}
std::string Edges::toBuffer(int ej){
	if(ej<=24) return Edges::edgeBuffer[ej-1];
return "";
}
std::string Edges::revertFromBuffer(int ej){
	return testCube.reverseSequence(toBuffer(ej));
}
void Edges::printPermuteMoves(void){
    if(testCube.parity==false){
        std::cout << jPerm << " ";
    }
    for(int i=0; i<edgePermuteVector.size()-1; i++){
        if(edgePermuteVector[i]==edgePermuteVector[i+1]){
            i++;
        }else if(edgePermuteVector[i]==2||edgePermuteVector[i]==6){
            continue;
        }else{
            std::string edgePreBuffer = this->toBuffer(this->edgePermuteVector[i]);
            std::string edgePostBuffer = this->revertFromBuffer(this->edgePermuteVector[i]);
            std::string separator = (edgePreBuffer=="")?"":" ";
            std::cout << edgePreBuffer << separator << jPerm << separator << edgePostBuffer << " ";
            edgeMoveCounter++;
        }
    }
   std::cout << "\n*\n";
}
void Edges::solve(std::string edgeConfigFile, std::string solvedEdgeFile){
    Edges edgeLattice(edgeConfigFile, Cube::solvedEdgeFile);
	edgeLattice.permute();
	edgeLattice.printPermuteMoves();
}
