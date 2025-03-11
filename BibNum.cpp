#include"Document.h"
#include"BibNum.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

BibNum::BibNum(string nom,int nbrdoc)
{
    this->nom=nom;
    this->nbrdoc=nbrdoc;
    for(int i=0;i<nbrdoc;i++)
    {
        Document* d=new Document();
        d->saisir();
        documents.push_back(d);
    }
}

BibNum::BibNum(const BibNum& b)
{
    nom=b.nom;
    nbrdoc=b.nbrdoc;
    for(int i=0;i<nbrdoc;i++)
    {
        Document* d=new Document();
        d->saisir();
        documents.push_back(d);
    }
}

void BibNum::saisir()
{
    cout<<"Donner le nom"<<endl;
    cin>>nom;
    cout<<"Donner le nombre de documents"<<endl;
    cin>>nbrdoc;
    for(int i=0;i<nbrdoc;i++)
    {
        Document* d=new Document();
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
    Document* d=new Document();
    d->saisir();
    documents.push_back(d);
}

void BibNum::supprimer_doc()
{

}

BibNum::~BibNum()
{
    for(int i=0;i<nbrdoc;i++)
        delete documents[i];
    documents.clear();
}
