/**
* @file Dna.hpp
* @description tanımlamaların ve genel fonksiyonların isimlerinin yazılması
* @course 1.öğretim B grubu
* @assignment 1.ödev
* @date 6.11.24
* @author Didem Reyhan AKAN / didem.akan@ogr.sakarya.edu.tr
*/
#ifndef DNA_HPP
#define DNA_HPP

#include "Kromozom.hpp"
#include <iostream>
#include <string>

using namespace std;

class DNA {
public:
    Kromozom* khead;
    int ksayi;

    DNA();
    ~DNA();
    
    void caprazla(int girdi1,int girdi2);
    void yazdirKromozom();
    void ekleKromozom(Kromozom* kromozom);
    void mutasyon(int kromozomNo,int genSira);
    Kromozom* kromozomGetir(int sira);
    void otomatik(string dosyaAdi);
    void ekranaYaz();
 
};

#endif

