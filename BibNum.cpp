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
        documents.erase(documents.begin() + i);
        cout<<"Suppression effetuee avec succes"<<endl;
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
    o<<"Nom: "<<setw(10)<<b->nom<<endl;
    o<<"Nombre de documents: "<<b->nbrdoc<<endl;
    for(int i=0;i<b->nbrdoc;i++)
        {
            if(typeid(*b->documents[i])==typeid(Livre))
               {
                   o<<"1. Livre:"<<endl;
                   o<<static_cast<Livre&>(*b->documents[i])<<endl;
               }
            else
                if(typeid(*b->documents[i])==typeid(Magazine))
                {
                    o<<"3. Magazine:"<<endl;
                    o<<static_cast<Magazine&>(*b->documents[i])<<endl;
                }
                else
                    if(typeid(*b->documents[i])==typeid(LivreAudio))
                    {
                        o<<"2. Livre Audio:"<<endl;
                        o<<static_cast<LivreAudio&>(*b->documents[i])<<endl;
                    }
                    else
                        if(typeid(*b->documents[i])==typeid(RechercheScientifique))
                        {
                            o<<"4. Recherche Scientifique:"<<endl;
                            o<<static_cast<RechercheScientifique&>(*b->documents[i]);
                        }
        }
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
        this->nom=b.nom;
        this->nbrdoc=b.nbrdoc;
        }
    }
    return *this;
}

void BibNum::ouvrir_fichier(fstream& f)
{
    f.open("C:\\Users\\Ons\\Desktop\\enicar\\1ère année\\semestre 2\\Programmation orienté objet\\projet vf - Copie\\ficherbib.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) throw -1;
}

istream& operator>>(istream& i,BibNum* b)
{
    int choix;
    i.seekg(0);
    while(1)
    {
        /*i.getline(ch,100);
        if(i.eof()) break;
        i>>ch>>endl;*/
        i>>choix;
        if(i.eof()) break;
        if(choix==1)
        {
            Livre* l=new Livre();
            i>>*l;
            b->documents.push_back(l);
        }
        else if(choix==2)
        {
            Magazine* m=new Magazine();
            i>>*m;
            b->documents.push_back(m);
        }
        else if(choix==3)
        {
            LivreAudio* la=new LivreAudio();
            i>>*la;
            b->documents.push_back(la);
        }
        else if (choix==4)
        {
            RechercheScientifique* rs=new RechercheScientifique();
            i>>*rs;
            b->documents.push_back(rs);
        }
    }
    return i;
}


void BibNum::ecriture_fichier(fstream& f)
{
        BibNum b1;

        b1.ouvrir_fichier(f);
        cout<<"--------------Remplissage du fichier----------------"<<endl;
        cin>>b1;
        f<<&b1<<endl;
}



void BibNum::lecture_fichier(fstream& f)
{
        BibNum b1;

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


