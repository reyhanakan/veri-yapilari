
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

