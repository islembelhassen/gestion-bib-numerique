#ifndef ROLE_H_INCLUDED
#define ROLE_H_INCLUDED

#include<iostream>
using namespace std;

class Role {
    private:
        string role;
        float salaire;
    public:
        Role();
        Role(string, float);
        void set_role(string);
        void set_salaire(float);
        string get_role();
        float get_salaire();
        virtual void afficher();
        virtual void saisir();
        virtual ~Role();
};


#endif // ROLE_H_INCLUDED
