/**
* @file Gen.cpp
* @description Genin kurucu fonksiyonu 
* @course 1.öğretim B grubu
* @assignment 1.ödev
* @date 6.11.24
* @author Didem Reyhan AKAN / didem.akan@ogr.sakarya.edu.tr
*/
#include "Gen.hpp"

Gen::Gen(string gen) {
    this->gen = gen;
    this->next = nullptr;
    this->prev = nullptr;
}


