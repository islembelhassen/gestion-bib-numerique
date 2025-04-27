#include"Document.h"
#include"Magazine.h"
#include"Date.h"
#include"MotCle.h"
#include"Livre.h"
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

Document::Document(string id,string titre, float prix,Date d)
{
    this->id=id;
    this->titre=titre;
    this->prix=prix;
    datepub=d;

}

Document::Document(const Document &d)
{
    id=d.id;
    titre=d.titre;
    prix=d.prix;
    datepub=d.datepub;
    for(int i=0;i<d.description.size();i++)
        description[i]=d.description[i];
}

void Document::saisir()
{
    cout<<"Donner l'id: "<<endl;
    cin>>id;
    cout<<"Donner le titre: "<<endl;
    cin>>titre;
    cout<<"Donner le prix: "<<endl;
    cin>>prix;
    datepub.saisir();
    char rep;
    MotCle* m=new MotCle();
    do
    {
        cout<<"Remplissage de la description"<<endl;
        m->saisir();
        description.push_back(m);
        cout<<"Voulez-vous rajouter?"<<endl;
        cin>>rep;
    }while (rep=='o'||rep=='O');
}

void Document::afficher()
{
    cout<<"L'id: "<<id<<endl;
    cout<<"Le titre: "<<titre<<endl;
    cout<<"Le prix: "<<prix<<endl;
    datepub.afficher();
    for(int i=0;i<description.size();i++)
        description[i]->afficher();
}

void Document::set_id(string id)
{
    this->id=id;
}

void Document::set_titre(string titre)
{
    this->titre=titre;
}

void Document::set_prix(float prix)
{
    this->prix=prix;
}

void Document::set_datepub(Date date)
{
    datepub=date;
}

string Document::get_id()const
{
    return id;
}

string Document::get_titre()
{
    return titre;
}

float Document::get_prix()
{
    return prix;
}

Date Document::get_datepub()
{
    return datepub;
}

void Document::ajouter_description()
{
    MotCle* m;
    m->saisir();
    description.push_back(m);
}

void Document::supprimer_descrption(string libelle)
{
    for(int i=0;i<description.size();i++)
    {
        if(description[i]->get_libelle()==libelle)
            delete description[i];
    }
}

Document::~Document()
{
    for(int i=0;i<description.size();i++)
        delete description[i];
    description.clear();
}

Document& Document::operator=(const Document& d)
{
    MotCle* m;
    if(this!=&d)
    {
        for(int i=0;i<description.size();i++)
            delete description[i];
        description.clear();
        for(int i=0;i<d.description.size();i++)
        {
           MotCle* m= new MotCle(*d.description[i]);
           description.push_back(m);
        }
    }
    return *this;
}

ostream& operator<<(ostream& o,Document& d)
{
    o<<"ID: "<<d.id<<endl;
    o<<"Titre: "<<d.titre<<endl;
    o<<"Prix: "<<d.prix<<endl;
    o<<"Date de publication: "<<d.datepub;
    o<<"Description: "<<endl;
    for(int i=0;i<d.description.size();i++)
    {
        o<<d.description[i];
    }
    return o;
}

istream& operator>>(istream& i,Document& d)
{
    cout<<"Donner l'id: ";
    i>>d.id;
    cout<<"Donner le titre: ";
    i>>d.titre;
    cout<<"Donner le prix: ";
    i>>d.prix;
    cout<<"Donner la date de publication: "<<endl;
    i>>d.datepub;
    cout<<"Donner la description: "<<endl;
    d.description.clear();
    char rep;
    do{
        MotCle* m=new MotCle();
        m->saisir();
        d.description.push_back(m);
        cout<<"Y-a-t-il d'autres mots cles? ";
        i>>rep;
    } while (rep=='o'||rep=='O');
    return i;
}

ostream& operator<<(ostream& o,Document* d)
{
    o<<"ID: "<<setw(10)<<d->id<<endl;
    o<<"Titre: "<<setw(10)<<d->titre<<endl;
    o<<"Prix: "<<setw(10)<<d->prix<<endl;
    o<<"Date de publication: "<<setw(10)<<d->datepub;
    return o;
}

istream& operator>>(istream& i,Document* d)
{
    i>>d->id;
    i>>d->titre;
    i>>d->prix;
    i>>d->datepub;
    for(int j=0;j<d->description.size();j++)
        i>>d->description[j];
    return i;
}

/* fstream f;
    Livre l;
    f.open("C:\\Users\\Ons\\Desktop\\enicar\\1ère année\\semestre 2\\Programmation orienté objet\\projet vf\\ficherlivre.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit(-1);
    cin>>l;
    f<<l<<endl;
    cout<<l;
    f.close();*/
