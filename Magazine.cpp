#include<iostream>
#include<string>
#include"Magazine.h"
#include"Document.h"
#include<fstream>
#include<iomanip>
using namespace std;

Magazine::Magazine(string id,string titre,float prix,Date datepub,string edition):Document(id,titre,prix,datepub)
{
    this->edition=edition;
}

void Magazine::saisir()
{
    Document::saisir();
    cout<<"Donner l'edition"<<endl;
    cin>>edition;
}

void Magazine::afficher()
{
    Document::afficher();
    cout<<"L'edition: "<<edition<<endl;
}

void Magazine::set_edition(string edition)
{
    this->edition=edition;
}

string Magazine::get_edition()
{
    return edition;
}

Magazine::~Magazine(){}

bool Magazine::operator==(const Magazine& m)const
{
        return (this->id==m.id);
}

ostream& operator<<(ostream& o,Magazine& m)
{
    Document* d=&m;
    o<<*d;
    o<<"Edition: "<<m.edition<<endl;
    return o;
}

istream& operator>>(istream& i,Magazine& m)
{
    Document* d=&m;
    i>>*d;
    cout<<"Donner l'edition: ";
    i>>m.edition;
    return i;
}

ostream& operator<<(ostream& o,Magazine* m)
{
    Document* d=m;
    o<<*d;
    o<<"Edition: "<<setw(10)<<m->edition<<endl;
    return o;
}

istream& operator>>(istream& i, Magazine* m)
{
    Document* d=m;
    i>>*d;
    i>>m->edition;
    return i;
}
