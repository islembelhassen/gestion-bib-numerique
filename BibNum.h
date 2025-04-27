#ifndef BIBNUM_H_INCLUDED
#define BIBNUM_H_INCLUDED

#include"Document.h"
#include<string>
#include<vector>
#include<fstream>
using namespace std;

typedef int Erreur;
class BibNum{
string nom;
int nbrdoc;
vector<Document*> documents;
public:
    BibNum(string="",int=0);
    BibNum(const BibNum&);
    void saisir();
    void afficher();
    void set_nom(string);
    void set_nbrdoc(int);
    string get_nom();
    int get_nbrdoc();
    void ajouter_doc();
    void supprimer_doc(string);
    friend ostream& operator<<(ostream&,BibNum&);
    friend ostream& operator<<(ostream&,BibNum*);
    friend istream& operator>>(istream&,BibNum&);
    friend istream& operator>>(istream&,BibNum*);
    BibNum& operator=(const BibNum&);
    void ouvrir_fichier(fstream&);
    void ecriture_fichier(fstream&);
    void lecture_fichier(fstream&);
    ~BibNum();
}; ostream& operator<<(ostream&,BibNum&);
   istream& operator>>(istream&,BibNum&);
   ostream& operator<<(ostream&,BibNum*);
   istream& operator>>(istream&,BibNum*);


#endif // BIBNUM_H_INCLUDED
