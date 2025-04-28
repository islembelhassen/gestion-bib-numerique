#include <iostream>
#include <string>
#include "Document.h"
#include "Livre.h"
#include "Chapitre.h"
#include<fstream>
#include<iomanip>
using namespace std;

Livre::Livre(string id,string titre,float prix,Date datepub,string ISBN,int nbrchaps):Document(id,titre,prix,datepub)
{
    this->ISBN=ISBN;
    this->nbrchaps=nbrchaps;
}

Livre::Livre(const Livre& l)
{
    id=l.id;
    titre=l.titre;
    prix=l.prix;
    datepub=l.datepub;
    ISBN=l.ISBN;
    for(int i=0;i<l.description.size();i++)
    {
        MotCle* m=new MotCle(*l.description[i]);
        description.push_back(m);

    }
    nbrchaps=l.nbrchaps;
    for(int i=0;i<l.chaps.size();i++)
    {
        Chapitre* c=new Chapitre(*l.chaps[i]);
        chaps.push_back(c);
    }

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
    for(int i=0;i<chaps.size();i++)
    {
        if(chaps[i]->get_titre()==titre)
        {
            delete chaps[i];
            chaps.erase(chaps.begin() + i);
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
    for(int i=0;i<l.chaps.size();i++)
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
    l.chaps.clear();
    for(int i=0;i<l.nbrchaps;i++)
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
        id=l.id;
        titre=l.titre;
        datepub=l.datepub;
        ISBN=l.ISBN;
        nbrchaps=l.nbrchaps;
        prix=l.prix;
        for(int i=0;i<chaps.size();i++)
            delete chaps[i];
        chaps.clear();
        for(int i=0;i<l.chaps.size();i++)
        {
            Chapitre* c=new Chapitre(*l.chaps[i]);
            chaps.push_back(c);
        }
    }
    return *this;
}

ostream& operator<<(ostream& o,Livre* l)
{

    Document* d=l;
    o<<*d;
    o<<"ISBN: "<<l->ISBN<<endl;
    o<<"Nombre de chapitres: "<<l->nbrchaps<<endl;
    for(int i=0;i<l->nbrchaps;i++)
         o<<l->chaps[i]<<endl;


    return o;
}

istream& operator>>(istream& i,Livre*l)
{
    Document* d=l;
    i>>*d;
    i>>l->ISBN;
    i>>l->nbrchaps;
    Chapitre* chap=new Chapitre();
    for(int j=0;j<l->nbrchaps;j++)
        {
        chap->saisir();
        l->chaps.push_back(chap);}

    return i;
}

void Livre::ouvrir_fichier(fstream& f)
{
    f.open("ficherlivre.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit(-2);
}

void Livre::ecriture_fichier(fstream& f)
{
    /*Livre l;
    l.ouvrir_fichier(f);
    cout<<"--------------Remplissage du fichier----------------"<<endl;
    cin>>l;
    f<<&l<<endl;
    */
    this->ouvrir_fichier(f);
    cout<<"--------------Remplissage du fichier----------------"<<endl;
    cin>>*this;
    f<<this;

}

void Livre::lecture_fichier(fstream& f)
{

        cout<<"--------------Lecture du fichier--------------------"<<endl;
        f.seekg(0);
        char str[100];
        while(1)
        {
        f.getline(str,100,'\n');
        if(f.eof()) break;
        cout<<str<<endl;
        }
        f.close();
        cout<<"------------Fin de lecture du fichier----------------"<<endl;
}
