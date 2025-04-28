#ifndef CHAPITRE_H_INCLUDED
#define CHAPITRE_H_INCLUDED

#include<string>
using namespace std;

class Chapitre{
string titre;
int nbrpages;
public:
    Chapitre(string="",int=0);
    void saisir();
    void afficher();
    void set_titre(string);
    void set_nbrpages(int);
    string get_titre();
    int get_nbrpages();
    Chapitre& operator+(const Chapitre&);
    friend ostream& operator<<(ostream&,Chapitre&);
    friend ostream& operator<<(ostream&,Chapitre*);
    friend istream& operator>>(istream&,Chapitre&);
    friend istream& operator>>(istream&,Chapitre*);
    ~Chapitre();
}; ostream& operator<<(ostream&,Chapitre&);
   istream& operator>>(istream&,Chapitre&);
   ostream& operator<<(ostream&,Chapitre*);
   istream& operator>>(istream&,Chapitre*);

#endif // CHAPITRE_H_INCLUDED
