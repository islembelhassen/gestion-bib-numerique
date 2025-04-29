#ifndef LICENCE_H_INCLUDED
#define LICENCE_H_INCLUDED

#include"Document.h"
#include<list>

class Licence{
    private:
        int numL;
        string titre;
        list<Document*> documents;
        float TVA; //static float TVA
        float tot;


    public:
        Licence();
        Licence(int,string,float,float);
        float calculTot();
        void saisir();
        void afficher();
        void set_numL(int);
        void set_titre(string);
        void set_TVA(float);
        int get_numL();
        string get_titre();
        float get_TVA();
        void ajouterDocument(string);
        void supprimerDocument(string);



        Licence& operator=(const Licence&);
        friend ostream& operator<<(ostream&, const Licence&);
        friend istream& operator>>(istream&, Licence&);
};

#endif // LICENCE_H_INCLUDED


/*


void Admin::ecrireDansFichier(char file[20])  {

    ofstream fout(file);
    if (!fout) {
        cout << "Impossible d'ouvrir " << file << endl;
        return;
    }


    fout << "=== Donnees Administrateur ===" << endl;
    fout << "ID Admin: " << idA << endl;
    fout << "Date prise de fonction: " << date_prise_fct.toString() << endl;

    fout << "Nom: " << getNom() << endl;
    fout << "Prenom: " << getPrenom() << endl;
    fout << "Email: " << getEmail() << endl;


    fout.close();
    cout << "Donnees enregistrees dans " << file << endl;
}

void Admin::lireDepuisFichier( char file[20]) {

    ifstream fin(file);
    if (!fin) {
        cout << "Impossible d'ouvrir " << file << " en lecture" << endl;
        return;
    }

    cout << "\nContenu du fichier " << file << ":\n";
    cout << "----------------------------------------\n";

    string ligne;
    while (getline(fin, ligne)) {
        if (ligne.find("ID Admin: ") != string::npos) {
            idA = ligne.substr(10); // Extrait tout après "ID Admin: "
        }
        else if (ligne.find("Date prise de fonction: ") != string::npos) {
            string dateStr = ligne.substr(23);
            // Convertir dateStr en objet Date (à implémenter)
            date_prise_fct = parseDate(dateStr);
        }
        else if (ligne.find("Nom: ") != string::npos) {
            setNom(ligne.substr(5)); // Méthode héritée de Personne
        }
        else if (ligne.find("Prenom: ") != string::npos) {
            setPrenom(ligne.substr(8));
        }
        else if (ligne.find("Email: ") != string::npos) {
            setEmail(ligne.substr(7));
        }

        cout << ligne << endl; // Affichage du contenu
    }

    fin.close();
    cout << "----------------------------------------\n";
    cout << "Données admin chargées avec succès!\n";
}

*/
