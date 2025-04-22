#include <iostream>
#include <string>
#include "Document.h"
#include "Livre.h"
#include "Chapitre.h"
#include<fstream>
#include<iomanip>
using namespace std;

Livre::Livre(string id,string titre,float prix, string ISBN,int nbrchaps):Document(id,titre,prix)
{
    this->ISBN=ISBN;
    this->nbrchaps=nbrchaps;
}

Livre::Livre(const Livre& l)
{
    id=l.id;
    titre=l.titre;
    prix=l.prix;
    ISBN=l.ISBN;
    nbrchaps=l.nbrchaps;
    for(int i=0;i<nbrchaps;i++)
        chaps.push_back(l.chaps[i]);
}

void Livre::saisir()
{
    Document::saisir();
    cout<<"Donner l'ISBN: "<<endl;
    cin>>ISBN;
    cout<<"Dooner le nombre de chapitres: ";
    cin>>nbrchaps;
    for(int i=0;i<nbrchaps;i++)
    {
        Chapitre* chap=new Chapitre;
        chap->saisir();
        chaps.push_back(chap);
    }
}

void Livre::afficher()
{
    Document::afficher();
    cout<<"L'ISBN: "<<ISBN<<endl;
    cout<<"Nombre de chapitres: "<<nbrchaps<<endl;
    for(int i=0;i<nbrchaps;i++)
    {
        chaps[i]->afficher();
        cout<<"\t";
    }
    cout<<endl;
}

void Livre::ajouter_chap()
{
    Chapitre* chap=new Chapitre;
    chap->saisir();
    chaps.push_back(chap);
}

void Livre::supprimer_chap(string titre)
{
    for(int i=0;i<nbrchaps;i++)
    {
        if(chaps[i]->get_titre()==titre)
        {
            delete chaps[i];
            cout<<"Suppression effectuee avec succes"<<endl;
            nbrchaps--;
        }
    }
}

void Livre::set_isbn(string ISBN)
{
    this->ISBN=ISBN;
}

void Livre::set_nbrchaps(int nbrchaps)
{
    this->nbrchaps=nbrchaps;
}

string Livre::get_isbn()
{
    return ISBN;
}

int Livre::get_nbrchaps()
{
    return nbrchaps;
}

Livre::~Livre()
{
    for(int i=0;i<chaps.size();i++)
        delete chaps[i];
    chaps.clear();
}

ostream& operator<<(ostream& o,Livre& l)
{
    Document* d=&l;
    o<<*d;
    o<<"ISBN: "<<l.ISBN<<endl;
    o<<"Nombre de chapitres: "<<l.nbrchaps<<endl;
    for(int i=0;i<l.nbrchaps;i++)
        o<<l.chaps[i];
    return o;
}

istream& operator>>(istream& i, Livre& l)
{
    Document* d=&l;
    i>>*d;
    cout<<"Donner l'ISBN: ";
    i>>l.ISBN;
    cout<<"Donner le nombre de chapitres: ";
    i>>l.nbrchaps;
    for(int j=0;j<l.nbrchaps;j++)
    {
        Chapitre* chap=new Chapitre;
        chap->saisir();
        l.chaps.push_back(chap);
    }
    return i;
}

Livre& Livre::operator=(Livre& l)
{
    if(this!=&l)
    {
        for(int i=0;i<chaps.size();i++)
            delete chaps[i];
        chaps.clear();
        for(int i=0;i<l.chaps.size();i++)
        {
            chaps.push_back(l.chaps[i]);
        }
    }
    return *this;
}

ostream& operator<<(ostream& o,Livre* l)
{
    o<<setw(10)<<l->id<<endl;
    o<<setw(10)<<l->ISBN<<endl;
    o<<setw(10)<<l->titre<<endl;
    o<<setw(10)<<l->prix<<endl;
    o<<setw(10)<<l->nbrchaps<<endl;
    return o;
}
