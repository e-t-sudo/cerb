#ifndef CUBE_H
#define CUBE_H
#include<iostream>
#include<vector>
#include<string>
class Cube{
    public:
        static bool parity;
        const std::string clockCommutator = "F' U L2 U' L2 U' F' U F2 D' L2 D L2"; 
        const std::string counterCommutator = this->reverseSequence(clockCommutator);
        std::string reverseSequence(std::string);
        bool isPresent(std::vector<int>, int);
};
#endif