
#ifndef GEN_HPP
#define GEN_HPP
#include <iostream>
#include <string>
using namespace std;

class Gen {
public:
    string gen; 
    Gen* next;  
    Gen* prev;   

    Gen(string gen);
      

};

#endif 

