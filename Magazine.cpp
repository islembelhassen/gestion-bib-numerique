#include<iostream>
#include<string>
#include"Magazine.h"
#include"Document.h"
using namespace std;

Magazine::Magazine(string id,string titre,float prix,string edition):Document(id,titre,prix)
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
