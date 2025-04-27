#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

#include<iostream>
#include <string>
#include <vector>
#include "Document.h"
#include "Date.h"
#include<fstream>

using namespace std;

class Personne {
    protected:
        string nom;
        string prenom;
        string email;
        int tel;
        Date datenaissance;
        vector<Document*> documents;
    public:
        Personne();
        Personne(string,string, Date,string,int);
        Personne(const Personne&);
        virtual void saisir()=0;
        virtual void afficher();
        void set_nom(string);
        void set_prenom(string);
        void set_email(string);
        void set_tel(int);
        void set_datenaissance(Date);
        string get_nom();
        string get_prenom();
        string get_email();
        int get_tel();
        Date get_datenaissance();

        void ajouterDoc(Document*);
        void supprimerDoc(string id);
        virtual ~Personne();

        Personne& operator=(const Personne&);
        friend ostream& operator<<(ostream&, const Personne&);
        friend istream& operator>>(istream&, Personne&);

        friend ostream& operator<<(ostream&, const Personne*);
        friend istream& operator>>(istream&, Personne*);
        void ecriture_fichier(fstream&);
        void lecture_fichier(fstream&);
};



#endif // PERSONNE_H_INCLUDED
