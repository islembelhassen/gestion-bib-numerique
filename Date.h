#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Date {
    public:
        int jour;
        int mois;
        int annee;
        Date(): jour(0), mois(0), annee(0000) {}
        Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}

        void afficher();
        void saisir();

        string toString();

        Date parseDate(const string&);


        Date& operator=(const Date&);
        Date& operator+(const Date&);

        friend ostream& operator<<(ostream&, const Date&);
        friend istream& operator>>(istream&, Date&);



};
#endif // DATE_H_INCLUDED
