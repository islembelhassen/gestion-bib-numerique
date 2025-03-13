#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<iostream>
using namespace std;

class Date {
    public:
        int jour;
        int mois;
        int annee;
        Date(): jour(0), mois(0), annee(0000) {}
        Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}
        void afficher(){
            cout << jour << "/" << mois << "/" << annee << endl;
        }
        void saisir(){
            cout << " jour: ";
            cin>>jour;
            cout<< " mois: " ;
            cin>> mois;
            cout << " annee: ";
            cin>> annee;
    }

};
#endif // DATE_H_INCLUDED
