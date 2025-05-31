
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
