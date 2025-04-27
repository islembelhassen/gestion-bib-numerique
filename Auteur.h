#ifndef AUTEUR_H_INCLUDED
#define AUTEUR_H_INCLUDED

#include"Personne.h"

class Auteur : public Personne{
    private:
        string idAut;
    public:
        Auteur();
        Auteur(string,string, Date,string,int,string);
        Auteur(const Auteur&);
        virtual void saisir();
        virtual void afficher();
        void set_idAut(string);
        string get_idAut();

        Auteur& operator=(const Auteur&);
        friend ostream& operator<<(ostream&, const Auteur&);
        friend istream& operator>>(istream&, Auteur&);
};

#endif // AUTEUR_H_INCLUDED
