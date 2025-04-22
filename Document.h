#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Document{
protected:
    string id;
    string titre;
    float prix;
    //vector<Auteur*> auteurs;
    //Date datepub;
public:
    Document(string="",string="",float=0/*,Date*/);
    Document(const Document&);
    virtual void saisir()=0;
    virtual void afficher();
    void set_id(string);
    void set_titre(string);
    void set_prix(float);
    //
    //void set_datepub(Date);
    string get_id();
    string get_titre();
    float get_prix();
    //
    //Date get_datepub();
    friend ostream& operator<<(ostream&,Document&);
    friend ostream& operator<<(ostream&,Document*);
    friend istream& operator>>(istream&,Document&);
    virtual ~Document();
}; ostream& operator<<(ostream&,Document&);
   istream& operator>>(istream&,Document&);


#endif // DOCUMENT_H_INCLUDED
