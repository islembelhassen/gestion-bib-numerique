#ifndef MOTCLE_H_INCLUDED
#define MOTCLE_H_INCLUDED
#include<string>
using namespace std;

class MotCle{
string libelle;
string categorie;
string langue;
public:
    MotCle(string="",string="",string="");
    void saisir();
    void afficher();
    void set_libelle(string);
    void set_categorie(string);
    void set_langue(string);
    string get_libelle();
    string get_categorie();
    string get_langue();
    friend ostream& operator<<(ostream&,MotCle&);
    friend ostream& operator<<(ostream&,MotCle*);
    friend istream& operator>>(istream&,MotCle&);
    friend istream& operator>>(istream&,MotCle*);
    ~MotCle();
}; ostream& operator<<(ostream&,MotCle&);
   istream& operator>>(istream&,MotCle&);

#endif // MOTCLE_H_INCLUDED
