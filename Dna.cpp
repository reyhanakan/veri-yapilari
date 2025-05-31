
#include "DNA.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

DNA::DNA() {
    khead=nullptr;
    ksayi=0;
}

DNA::~DNA() {
    Kromozom* itr = khead;
    while (itr != nullptr) {
        Kromozom* sil = itr;
        itr = itr->next;
        delete sil;
    }
    khead=nullptr;
}

Kromozom* DNA::kromozomGetir(int sira) {
  Kromozom* itr=khead;
  int index=1; 

  while(itr!=nullptr&& index < sira){
    itr=itr->next;
    index++;
    }
   if(itr!=nullptr){
    itr->yazdirGen(sira);
   }else{
    cout<<"bulunamadi"<<endl;
   }
  }



void DNA::ekleKromozom(Kromozom* kromozom) {
    if (khead == nullptr) {
        khead = kromozom;
    } else {
        Kromozom* itr = khead;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = kromozom;
        
    }
    ksayi++;
    kromozom->next=nullptr;
}

 void DNA::yazdirKromozom() {
        Kromozom* itr = khead;
        int kromozomNo=1;
        while (itr != nullptr) {
            itr->yazdirGen(kromozomNo);  
            itr = itr->next;  
            kromozomNo++;
        }
    }

    void DNA::mutasyon(int kromozomNo, int genSira) {
        Kromozom* itr = khead;
        int sayac = 1;

        
        while (itr != nullptr && sayac < kromozomNo) {
            itr = itr->next;
            sayac++;
        }

       
        if (itr != nullptr) {
            itr->mutasyon(genSira);  
            cout<<"kromozom"<<kromozomNo<<"mutasyondan sonra"<<endl;
            kromozomGetir(kromozomNo);
        } else {

            cout << "gecerli kromozom bulunamadi." << endl;
        }
    }

void DNA::caprazla(int girdi1, int girdi2) {
    int ilk = girdi1 - 1; 
    int ikinci = girdi2 - 1;

    Kromozom* kromozom1 = nullptr;
    Kromozom* kromozom2 = nullptr;

    Kromozom* itr = khead;
    int sayac = 0;

    while (itr) {
        if (sayac == ilk) kromozom1 = itr;
        if (sayac == ikinci) kromozom2 = itr;
        itr = itr->next;
        sayac++;
    }

    if (!kromozom1 || !kromozom2) {
        cout << "gecersiz numaralar" << endl;
        return;
    }

    Kromozom *sol1, *sag1, *sol2, *sag2;
    kromozom1->bol(sol1, sag1);
    kromozom2->bol(sol2, sag2);

    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    Gen* iter = sol1->head;
    while (iter) {
        yeniKromozom1->ekleGen(iter->gen);
        iter = iter->next;
    }

    iter = sag2->head;
    while (iter) {
        yeniKromozom1->ekleGen(iter->gen);
        iter = iter->next;
    }

    iter = sag1->head;
    while (iter) {
        yeniKromozom2->ekleGen(iter->gen);
        iter = iter->next;
    }

    iter = sol2->head;
    while (iter) {
        yeniKromozom2->ekleGen(iter->gen);
        iter = iter->next;
    }

    ekleKromozom(yeniKromozom1);
    ekleKromozom(yeniKromozom2);

    cout << "caprazlama yapildi "  << endl;
    cout << "yeni populasyon icin listele " << endl;
}

void DNA::otomatik(string dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cerr << "dosyas acilamadi " << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        istringstream ss(satir);  
        char islem;               
        int girdi1, girdi2;      

        ss >> islem >> girdi1 >> girdi2; 

        if (islem == 'C') {

            cout << "caprazlama-> " << girdi1 << " ve " << girdi2 << endl;
            caprazla(girdi1, girdi2); 

        } else if (islem == 'M') {
        
            cout << "mutasyon-> kromozom " << girdi1 << ", gen " << girdi2 << endl;
            mutasyon(girdi1, girdi2);

        } else {
            cerr << "hatali islem " << islem << endl;
        }
    }

    dosya.close();
    cout << "islemler tamamlandi" << endl;
}


    void DNA::ekranaYaz(){
    Kromozom* itr = khead;  

    while (itr != nullptr) {
        itr->ekran();  
        itr = itr->next;   
    }

    cout << endl;

    }
