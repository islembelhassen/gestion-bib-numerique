#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

#include<iostream>
#include <string>
#include <vector>
#include "Document.h"
#include "Date.h"
using namespace std;

class Personne {
    protected:
        string nom;
        string prenom;
        string email;
        int tel;
        DATE datenaissance;
        vector<Document*> documents;
    public:
        Personne(string,string, DATE,string,string);
        virtual void saisir();
        virtual void afficher();
        void set_nom(string);
        void set_prenom(string);
        void set_email(string);
        void set_tel(int);
        void set_datenaissance(DATE);
        string get_nom();
        string get_prenom();
        string get_email();
        int get_tel();
        DATE get_datenaissance();

        void ajouterDoc(Document*);
        void supprimerDoc(Document*);
        virtual ~Personne();
};



#endif // PERSONNE_H_INCLUDED
