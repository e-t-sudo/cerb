#include "./headers/Cube.hpp"
#include "./headers/Edges.hpp"
#include "./headers/Corners.hpp"
void Cube::solve(std::string edgeConfigFile, std::string cornerConfigFile){
	Corners::solve(cornerConfigFile, Cube::solvedCornerFile);
	Edges::solve(edgeConfigFile, Cube::solvedEdgeFile);
}
int main(int argc, char * argv[]){
	//+--------------------------------------------------------------+
	//| Cube::solve(EDGE_CONFIG_FILE_PATH, CORNER_CONFIG_FILE_PATH); |
	//+--------------------------------------------------------------+
	std::cout << "Solution for test #1\n";
	Cube::solve("./tests/test01/edges.txt", "./tests/test01/corners.txt");
	std::cout << "Solution for test #2\n";
	Cube::solve("./tests/test02/edges.txt", "./tests/test02/corners.txt");
	std::cout << "Solution for test #3\n";
	Cube::solve("./tests/test03/edges.txt", "./tests/test03/corners.txt");
	std::cout << "Solution for test #4\n";
	Cube::solve("./tests/test04/edges.txt", "./tests/test04/corners.txt");
return 0;
}
