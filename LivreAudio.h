#ifndef LIVREAUDIO_H_INCLUDED
#define LIVREAUDIO_H_INCLUDED

#include"Document.h"
#include"Audio.h"
#include<string>
using namespace std;

class LivreAudio: public Document, public Audio{
string narrateur;
public:
    LivreAudio(string="",string="",float=0,Date=Date(),int=0,string="",string="");
    virtual void saisir()override;
    virtual void afficher()override;
    void set_narrateur(string);
    string get_narrateur();
    friend ostream& operator<<(ostream&,LivreAudio&);
    friend ostream& operator<<(ostream&,LivreAudio*);
    friend istream& operator>>(istream&,LivreAudio&);
    virtual ~LivreAudio();
}; ostream& operator<<(ostream&,LivreAudio&);
   istream& operator>>(istream&,LivreAudio&);


#endif // LIVREAUDIO_H_INCLUDED
