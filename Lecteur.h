#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED

#include "Personne.h"
#include "Date.h"


class Lecteur : public Personne {
    private:
        string idLec;
        Date date_adhes;
        int nbrdoc;
    public:
        Lecteur();
        Lecteur(string, string, Date, string, int, string, Date, int);
        Lecteur(const Lecteur&);
        void acheter_doc();
        void set_idLec(string);
        void set_date_adhes(Date);
        void set_nbrdoc(int);
        string get_idLec();
        Date get_date_adhes();
        int get_nbrdoc();
        virtual void afficher();
        virtual void saisir();
        virtual ~Lecteur();

        Lecteur& operator=(const Lecteur&);
        friend ostream& operator<<(ostream&, const Lecteur&);
        friend istream& operator>>(istream&, Lecteur&);


        friend ostream& operator<<(ostream&, const Lecteur*);
        friend istream& operator>>(istream&, Lecteur*);
};

#endif // LECTEUR_H_INCLUDED
