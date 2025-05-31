/**
* @file Kromozom.hpp
* @description tanımların ve fonksiyonların isimleri
* @course 1.öğretim B grubu
* @assignment 1.ödev
* @date 6.11.24
* @author Didem Reyhan AKAN / didem.akan@ogr.sakarya.edu.tr
*/
#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "Gen.hpp"
#include <iostream>
#include <string>

using namespace std;

class Kromozom {
public:
    Gen* head;
    Kromozom* next;
    int size;

    Kromozom();
    ~Kromozom();

    bool isEmpty() const;
    int genSayisi() const;
    void yazdirGen(int kromozomNo);
    void ekleGen(string gen);
    void mutasyon(int genSira);
    Gen* genGetir(int sira);
    void bol(Kromozom*& sol,Kromozom*& sag);
    void ekran();
    
};

#endif
