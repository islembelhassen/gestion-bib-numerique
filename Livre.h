#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED

#include "Document.h"
#include "Chapitre.h"
#include "Date.h"
#include "Auteur.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Livre: public Document{
string ISBN;
int nbrchaps;
vector<Chapitre*>chaps;
public:
    Livre(string="",string="",float=0,Date=Date(),string="",int=0);
    Livre(const Livre&);
    void saisir()override;
    void afficher();
    void ajouter_chap();
    void supprimer_chap(string);
    void set_isbn(string);
    void set_nbrchaps(int);
    string get_isbn();
    int get_nbrchaps();
    friend ostream& operator<<(ostream&,Livre&);
    friend ostream& operator<<(ostream&,Livre*);
    friend istream& operator>>(istream&,Livre&);
    friend istream& operator>>(istream&,Livre*);
    Livre& operator=(Livre&);
    void ouvrir_fichier(fstream&);
    void ecriture_fichier(fstream&);
    void lecture_fichier(fstream&);
    ~Livre();
}; ostream& operator<<(ostream&,Livre&);
   istream& operator>>(istream&,Livre&);


#endif // LIVRE_H_INCLUDED
