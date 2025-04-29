#include<iostream>
#include<string>
#include "Document.h"
#include"RechercheScientifique.h"
#include<iomanip>
using namespace std;

int RechercheScientifique::duree=365;
int RechercheScientifique::getDuree() {
    return duree;
}
void RechercheScientifique::setDuree(const int& d) {
    duree=d;
}


RechercheScientifique::RechercheScientifique(string id,string titre,float prix,Date datepub,string institut):Document(id,titre,prix,datepub)
{
    this->institut=institut;
}

void RechercheScientifique::saisir()
{
    Document::saisir();
    cout<<"Donner l'institut"<<endl;
    cin>>institut;
}

void RechercheScientifique::afficher()
{
    Document::afficher();
    cout<<"L'institut: "<<institut<<endl;
}

void RechercheScientifique::set_institut(string institut)
{
    this->institut=institut;
}

string RechercheScientifique::get_institut()
{
    return institut;
}

RechercheScientifique::~RechercheScientifique(){}

ostream& operator<<(ostream& o,RechercheScientifique& r)
{
    Document* d=&r;
    o<<*d;
    o<<"Institut: "<<r.institut<<endl;
    return o;
}

istream& operator>>(istream& i,RechercheScientifique& r)
{
    Document* d=&r;
    i>>*d;
    cout<<"Donner l'institut: ";
    i>>r.institut;
    return i;
}

ostream& operator<<(ostream& o,RechercheScientifique* rs)
{
    Document* d=rs;
    o<<*d;
    o<<setw(10)<<rs->institut<<endl;
    return o;
}
