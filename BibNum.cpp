#include"Document.h"
#include"Livre.h"
#include"LivreAudio.h"
#include"Magazine.h"
#include"RechercheScientifique.h"
#include"BibNum.h"
#include<string>
#include<vector>
#include<iostream>
#include<typeinfo>
#include<fstream>
#include<iomanip>
using namespace std;

BibNum::BibNum(string nom,int nbrdoc)
{
    this->nom=nom;
    this->nbrdoc=nbrdoc;
}

BibNum::BibNum(const BibNum& b)
{
    nom=b.nom;
    nbrdoc=b.nbrdoc;
    Document* d;
    for(int i=0;i<nbrdoc;i++)
    {
        if(typeid(b.documents[i])==typeid(Livre))
            d=new Livre(static_cast<const Livre&>(*b.documents[i]));
        else
            if(typeid(b.documents[i])==typeid(Magazine))
                d=new Magazine(static_cast<const Magazine&>(*b.documents[i]));
            else
                if(typeid(b.documents[i])==typeid(LivreAudio))
                    d=new LivreAudio(static_cast<const LivreAudio&>(*b.documents[i]));
                else
                    if(typeid(b.documents[i])==typeid(RechercheScientifique))
                        d=new RechercheScientifique(static_cast<const RechercheScientifique&>(*b.documents[i]));
        documents.push_back(d);
    }
}

void BibNum::saisir()
{
    cout<<"Donner le nom"<<endl;
    cin>>nom;
    cout<<"Donner le nombre de documents"<<endl;
    cin>>nbrdoc;
    char rep;
    int choix;
    Document* d;
     for(int i=0;i<nbrdoc;i++)
    {
        cout<<"Taper 1:Livre, 2:LivreAudio, 3:Magazine, 4:Recherche Scientifique"<<endl;
        cin>>choix;
        if(choix==1)
            d=new Livre;
        else
            if(choix==2)
                d=new LivreAudio;
            else
                if(choix==3)
                    d=new Magazine;
                else
                    if(choix==4)
                        d=new RechercheScientifique;
                    else break;
        d->saisir();
        documents.push_back(d);
    }
}

void BibNum::afficher()
{
    cout<<"Le nom: "<<nom<<endl;
    cout<<"Le nombre de documents: "<<nbrdoc<<endl;
    for(int i=0;i<nbrdoc;i++)
        documents[i]->afficher();
}

void BibNum::set_nom(string nom)
{
    this->nom=nom;
}

void BibNum::set_nbrdoc(int nbrdoc)
{
    this->nbrdoc=nbrdoc;
}

string BibNum::get_nom()
{
    return nom;
}

int BibNum::get_nbrdoc()
{
    return nbrdoc;
}

void BibNum::ajouter_doc()
{
    Document* d;
    int choix;
    cout<<"Taper 1:Livre, 2:LivreAudio, 3:Magazine, 4:Recherche Scientifique"<<endl;
    cin>>choix;
    if(choix==1)
        d=new Livre;
    else
        if(choix==2)
            d=new LivreAudio;
        else
            if(choix==3)
                d=new Magazine;
            else
                if(choix==4)
                    d=new RechercheScientifique;
                else cout<<"Choic invalide"<<endl;
    d->saisir();
    documents.push_back(d);
    nbrdoc++;
}

void BibNum::supprimer_doc(string id)
{
    for(int i=0;i<documents.size();i++)
        if(documents[i]->get_id()==id)
    {
        delete documents[i];
        cout<<"Suppression effetuee avec succés"<<endl;
        nbrdoc--;
    }
}

BibNum::~BibNum()
{
    for(int i=0;i<nbrdoc;i++)
        delete documents[i];
    documents.clear();
}

ostream& operator<<(ostream& o,BibNum& b)
{
    o<<"Le nom: "<<b.nom<<endl;
    o<<"Le nombre de documents: "<<b.nbrdoc<<endl;
    for(int i=0;i<b.documents.size();i++)
        b.documents[i]->afficher();
    return o;
}

ostream& operator<<(ostream& o,BibNum* b)
{
    o<<setw(10)<<b->nom<<endl;
    o<<setw(10)<<b->nbrdoc<<endl;
    for(int i=0;i<b->nbrdoc;i++)
        o<<setw(50)<<b->documents[i]<<endl;
    return o;
}

istream& operator>>(istream& i,BibNum& b)
{
    cout<<"Donner le nom: ";
    i>>b.nom;
    cout<<"Donner le nombre de documents: ";
    i>>b.nbrdoc;
    Document* d;
    int choix;
     for(int j=0;j<b.nbrdoc;j++)
    {
        cout<<"Taper 1:Livre, 2:LivreAudio, 3:Magazine, 4:Recherche Scientifique"<<endl;
        i>>choix;
        if(choix==1)
            d=new Livre;
        else
            if(choix==2)
                d=new LivreAudio;
            else
                if(choix==3)
                    d=new Magazine;
                else
                    if(choix==4)
                        d=new RechercheScientifique;
                    else break;
        d->saisir();
        b.documents.push_back(d);
    }
    return i;
}

BibNum& BibNum::operator=(const BibNum&b)
{
    Document* d;
    if(this!=&b)
    {
        for(int i=0;i<documents.size();i++)
            delete documents[i];
        documents.clear();
        for(int i=0;i<b.documents.size();i++)
        {
           if(typeid(b.documents[i])==typeid(Livre))
            d=new Livre(static_cast<const Livre&>(*b.documents[i]));
            else
                if(typeid(b.documents[i])==typeid(Magazine))
                    d=new Magazine(static_cast<const Magazine&>(*b.documents[i]));
                else
                    if(typeid(b.documents[i])==typeid(LivreAudio))
                        d=new LivreAudio(static_cast<const LivreAudio&>(*b.documents[i]));
                    else
                        if(typeid(b.documents[i])==typeid(RechercheScientifique))
                            d=new RechercheScientifique(static_cast<const RechercheScientifique&>(*b.documents[i]));
        documents.push_back(d);
        }
    }
    return *this;
}

void BibNum::ouvrir_fichier(fstream& f)
{
    f.open("C:\\Users\\Ons\\Desktop\\enicar\\1ère année\\semestre 2\\Programmation orienté objet\\projet vf\\ficherbib.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit(-1);
}

void BibNum::saisir_dans_fichier(fstream& f)
{

}

void BibNum::afficher_du_fichier(fstream& f)
{

}
