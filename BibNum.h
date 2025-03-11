#ifndef BIBNUM_H_INCLUDED
#define BIBNUM_H_INCLUDED
#include"Document.h"
#include<string>
#include<vector>
using namespace std;

class BibNum{
string nom;
int nbrdoc;
vector<Document*> documents;
public:
    BibNum(string,int);
    BibNum(const BibNum&);
    void saisir();
    void afficher();
    void set_nom(string);
    void set_nbrdoc(int);
    string get_nom();
    int get_nbrdoc();
    void ajouter_doc();
    void supprimer_doc();
    ~BibNum();
};

#endif // BIBNUM_H_INCLUDED
