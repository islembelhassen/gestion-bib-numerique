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

    string toString()  {
        ostringstream oss;

        oss << setfill('0')
                    << setw(2) << jour << "/"
                    << setw(2) << mois << "/"
                    << setw(4) << annee;
        return oss.str();
    }

    Date parseDate(const string& dateStr) {
        char sep;
        int j, m, a;

        if (dateStr.find('/') != string::npos)
                sscanf(dateStr.c_str(), "%d/%d/%d", &j, &m, &a);

        return Date(j, m, a);
    }

};
#endif // DATE_H_INCLUDED
