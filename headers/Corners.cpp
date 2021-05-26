#include "Corners.hpp"
#include<fstream>
Corners::Corners(std::string scrambledFile, std::string solvedFile){
    std::ifstream cornerFile(scrambledFile);
    for(int i=0; i<8; i++){
        cornerFile>>this->corners[i].c1>>this->corners[i].c2>>this->corners[i].c3;
    }
    cornerFile.close();
    std::ifstream solvedCornerFile(solvedFile);
    for(int i=0; i<12; i++){
        solvedCornerFile>>this->solvedCorners[i].c1>>this->solvedCorners[i].c2>>this->solvedCorners[i].c3;
    }
    solvedCornerFile.close();
    for(int i=0; i<8; i++){
        if(compareCorners(corners[i], solvedCorners[i])){
            alreadySolved.push_back(i+1);
        }
    }
}
bool Corners::compareCorners(corner x, corner y){
    bool firstColInBoth = (x.c1==y.c1||x.c1==y.c2||x.c1==y.c3);
    bool secondColInBoth = (x.c2==y.c1||x.c2==y.c2||x.c2==y.c3);
    bool thirdColInBoth = (x.c3==y.c1||x.c3==y.c2||x.c3==y.c3);
    if(firstColInBoth&&secondColInBoth&&thirdColInBoth){
        return true;
    }else{
        return false;
    }
}
void Corners::orient(void){
    for(int i=0; i<8; i++){
        corner currentCorner = corners[i];
        if(currentCorner.c1=='w'||currentCorner.c1=='y'){
            cornerOrientVector.push_back(0);
        }else if(currentCorner.c2=='w'||currentCorner.c2=='y'){
            cornerOrientVector.push_back(1);
        }else if(currentCorner.c3=='w'||currentCorner.c3=='y'){
            cornerOrientVector.push_back(-1);
        }
    }
}
std::string Corners::toOrientBuffer(int cornerIndex){
    switch(cornerIndex){
        case 1: return "";
        case 2: return "R' D' F";
        case 3: return "R2 D' F";
        case 4: return "";
        case 5: return "D F2";
        case 6: return "F2";
        case 7: return "D' F2";
        case 8: return "D2 F2";
    }
return "";
}
std::string Corners::revertFromOrientBuffer(int cornerIndex){
    return testCube.reverseSequence(toOrientBuffer(cornerIndex));
}
void Corners::printCornerOrientMoves(void){
    for(int i=0; i<cornerOrientVector.size(); i++){
        std::string preBuffer = toOrientBuffer(i+1);
        std::string postBuffer = revertFromOrientBuffer(i+1);
        std::string separatorSpace = (preBuffer=="")?"":" ";
        if(i+1==4) continue;
        if(cornerOrientVector[i]==1){
            //turn counter-clockwise
            std::cout << preBuffer << separatorSpace << counterCommutator << separatorSpace << postBuffer << " ";
        }else if(cornerOrientVector[i]==-1){
            //turn clockwise
            std::cout << preBuffer << separatorSpace << clockCommutator << separatorSpace << postBuffer << " ";
        }else if(cornerOrientVector[i]==0){
            continue;
        }
    }
std::cout << "\n*\n";
}
int Corners::getPos(corner crnr){
    char x = crnr.c1;
    char y = crnr.c2;
    char z = crnr.c3;
    for(int i=0; i<8; i++){
        corner currentCorner = solvedCorners[i];
        if((currentCorner.c1==x||currentCorner.c1==y||currentCorner.c1==z)&&(currentCorner.c2==x||currentCorner.c2==y||currentCorner.c2==z)&&(currentCorner.c3==x||currentCorner.c3==y||currentCorner.c3==z)){
            return i+1;
        }
    }
return 1000;
}
int Corners::nextUnsolved(void){
    for(int j=1; j<=8; j++){
        bool is_j_present = false;
        for(int i=0; i<cornerPermuteVector.size(); i++){
            if(cornerPermuteVector[i]==j) is_j_present = true;
        }
        if(is_j_present==false) return j;
    }
return 9;
}
void Corners::permute(void){
    int starter = buffer;
    START:
    if(starter<=8){
        cornerPermuteVector.push_back(starter);
        int loopcounter = 0;
        for(int f=getPos(corners[starter-1]); f<=8; f=getPos(corners[f-1])){
            loopcounter++;
            if(f==starter){
                HERE:
                int k = nextUnsolved();
                if(testCube.isPresent(alreadySolved, k)){
                   cornerPermuteVector.push_back(k);
                    cornerPermuteVector.push_back(k); 
                    goto HERE;
                }
                if(k){
                    starter = k;
                    cornerPermuteVector.push_back(f);
                    goto START; 
                }else{
                    break;
                }
            }
            cornerPermuteVector.push_back(f);
        }
    }
}
std::string Corners::toBuffer(int cornerIndex){
    switch(cornerIndex){
        case 1: return "L D F'";
        case 2: return "";
        case 3: return "";
        case 4: return "L2 F2";
        case 5: return "F2";
        case 6: return "D' F2";
        case 7: return "D2 F2";
        case 8: return "D F2";
    }
return "";
}
std::string Corners::revertFromBuffer(int cornerIndex){
        return testCube.reverseSequence(toBuffer(cornerIndex));
}
void Corners::printCornerPermuteMoves(void){
    int cornerMoveCount = 0;
    for(int i=0; i<cornerPermuteVector.size(); i++){
        if(cornerPermuteVector[i]==buffer) continue;
        else if((i<cornerPermuteVector.size()-1)&&cornerPermuteVector[i]==cornerPermuteVector[i+1]){
            i++;
            continue;
        }else{
            std::string prePerm = toBuffer(cornerPermuteVector[i]);
            std::string postPerm = revertFromBuffer(cornerPermuteVector[i]);
            if(prePerm!=""){
            std::cout << prePerm << " " << jPerm << " " << postPerm << " ";
            }else{
                std::cout << jPerm << " ";
            }
            cornerMoveCount++;
        }
    }
    if(cornerMoveCount%2==1){
        testCube.parity = !testCube.parity;
    }
std::cout << "\n*\n";
}
void Corners::solve(std::string cornerConfigFile, std::string solvedCornerFile){
    Corners cornerLattice(cornerConfigFile, Cube::solvedCornerFile);
	cornerLattice.orient();
	cornerLattice.printCornerOrientMoves();
	cornerLattice.permute();
	cornerLattice.printCornerPermuteMoves();
}
