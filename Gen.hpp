/**
* @file Gen.hpp
* @description Gen sınıfının tanımlanması
* @course 1.öğretim B grubu
* @assignment 1.ödev
* @date 6.11.24
* @author Didem Reyhan AKAN / didem.akan@ogr.sakarya.edu.tr
*/
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

