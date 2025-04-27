#include"Date.h"

void Date::afficher(){
            cout << jour << "/" << mois << "/" << annee << endl;
        }

void Date::saisir(){
            cout << " jour: ";
            cin>>jour;
            cout<< " mois: " ;
            cin>> mois;
            cout << " annee: ";
            cin>> annee;
    }

string Date::toString()  {
        ostringstream oss;

        oss << setfill('0')
                    << setw(2) << jour << "/"
                    << setw(2) << mois << "/"
                    << setw(4) << annee;
        return oss.str();
    }

Date Date::parseDate(const string& dateStr) {
        char sep;
        int j, m, a;

        if (dateStr.find('/') != string::npos)
                sscanf(dateStr.c_str(), "%d/%d/%d", &j, &m, &a);

        return Date(j, m, a);
    }



Date& Date::operator=(const Date& date) {
        if (this != &date) {
            jour = date.jour;
            mois = date.mois;
            annee = date.annee;
        }
        return *this;
    }

ostream& operator<<(ostream& os, const Date& date) {
        os<< date.jour << "/" << date.mois << "/" << date.annee<<endl;
        return os;
    }

istream& operator>>(istream& is, Date& date) {
        cout << "Entrez le jour: ";
        is >> date.jour;

        cout << "Entrez le mois: ";
        is >> date.mois;

        cout << "Entrez l'annee: ";
        is >> date.annee;

        return is;
    }



Date& Date::operator+(const Date& d){

    int jours=(this->annee+d.annee)*365 +(this->mois+d.mois)*30 + (this->jour+d.jour);

    int annee = jours / 365;
    jours %= 365;
    int mois = jours / 30;
    int jour = jours % 30;

    if(jour == 0) jour = 1;
    if(mois == 0) mois = 1;

    Date somme(jour,mois,annee);

    return somme;
}
