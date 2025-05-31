/**
* @file main.cpp
* @description Yapılacak islemlerin secilmesi
* @course 1.öğretim B grubu
* @assignment 1.ödev
* @date 6.11.24
* @author Didem Reyhan AKAN / didem.akan@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Dna.hpp"

using namespace std;

int main() {
    int secim = 0;
    int secKromo;
    
    DNA yeniDna;

    ifstream dosya("Dna.txt");
    string satir;

    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi: " << endl;
        return 1;
    }

  
    while (getline(dosya, satir)) {
       
        Kromozom* yeniKromozom = new Kromozom();  

        for (char c : satir) {
            yeniKromozom->ekleGen(string(1, c));  
        }

        yeniDna.ekleKromozom(yeniKromozom);
    }

    dosya.close();   

    do{ 
        cout << "1. listele" << endl;
        cout << "2. caprazla" << endl;
        cout << "3. mutasyon" << endl;
        cout << "4. otomatik islemler" << endl;
        cout << "5. ekrana yaz" << endl;
        cout << "6. cikis" << endl;
        cout << "seciminizi girin: ";
        cin >> secim;

        switch(secim){

            case 1:
            yeniDna.yazdirKromozom();
            break;

            case 2:
            int girdi1, girdi2;
            cout << "caprazlama icin iki kromozom no girin: ";
            cin >> girdi1 >> girdi2;

            yeniDna.caprazla(girdi1, girdi2);
            break;
            
            case 3:
            int kromozomNo, genSira;
            cout << "hangi kromozom mutasyona ugrayacak: ";
            cin >> kromozomNo;
            cout << "hangi gen mutasyona ugrayacak: ";
            cin >> genSira;

            yeniDna.mutasyon(kromozomNo, genSira);
            break;

            case 4:
            yeniDna.otomatik("Islemler.txt");
            break;

            case 5:
            yeniDna.ekranaYaz();
            break;

            case 6:
            break;

            default:
            cout<<"yanlis secim"<<endl;
            break;
        }

    }while(secim!=6);

    return 0;
}