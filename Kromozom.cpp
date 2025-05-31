
#include "Kromozom.hpp"
#include "Gen.hpp"

Kromozom::Kromozom() {
    head=nullptr;
    size=0;
}

Kromozom::~Kromozom() {
    Gen* itr = head;
    while (itr != nullptr) {
        Gen* sil = itr;
        itr = itr->next;
        delete sil;
    }
}

    bool Kromozom::isEmpty()const{
        return size==0;
     }
     int Kromozom::genSayisi()const{
        return size;
     }  

Gen* Kromozom::genGetir(int sira) {
     Gen* itr=head;
     int index=1;

     while(itr!=nullptr){

        if(index==sira){
            return itr;
            itr=itr->next;
            index++;
        }
     }
     return 0;
}

void Kromozom::ekleGen(string gen) {
    Gen* newgen = new Gen(gen);  
    if (head == nullptr) {
        head = newgen;
    } else {
        Gen* itr = head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = newgen;
        newgen->prev = itr;
    }
    size++;
}

 void Kromozom::yazdirGen(int kromozomNo) {
    cout << "Kromozom " << kromozomNo << ": ";
        Gen* itr = head;
        while (itr != nullptr) {
            cout << itr->gen<<" ";
            itr = itr->next;
        }
        cout << endl;
    }

    void Kromozom::mutasyon(int genSira) {
        Gen* itr = head;
        int sayac = 1;
        
       
        while (itr != nullptr && sayac < genSira) {
            itr = itr->next;
            sayac++;
        }

     
        if (itr != nullptr) {
            itr->gen = "X";  
        } else {
            cout << "gecerli gen bulunamadi " << endl;
        }
    }


void Kromozom::bol(Kromozom*& sol,Kromozom*& sag){
    int orta=genSayisi()/2;

    sol= new Kromozom();
    sag=new Kromozom();

    Gen* itr=head;
    int sayac=0;

    while(itr){

        if(genSayisi()%2!=0&&sayac==orta){

            itr=itr->next;
            sayac++;
            continue;
        }
        
        if(sayac<orta){
            sol->ekleGen(itr->gen);
        } else {
            sag->ekleGen(itr->gen);
        }
        itr=itr->next;
        sayac++;
    }
}

void Kromozom::ekran() {
    Gen* itr = head;    
    bool yaz = false;


    string ilkGen = itr->gen;


    while (itr->next != nullptr) {
        itr = itr->next;
    }

   
    while (itr != nullptr) {
        if (itr->gen < ilkGen) {  
            cout << itr->gen << " "; 
            yaz = true;
            break;  
        }
        itr = itr->prev; 
    }

   
    if (!yaz) {
        cout << ilkGen << " ";
    }
}
