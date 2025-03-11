#ifndef LIVREAUDIO_H_INCLUDED
#define LIVREAUDIO_H_INCLUDED
#include"Document.h"
#include"Audio.h"
#include<string>
using namespace std;

class LivreAudio: public Document, public Audio{
string narrateur;
public:
    LivreAudio(string,string,float/*,Date,Auteur* */,int,string,string);
    virtual void saisir();
    virtual void afficher();
    void set_narrateur(string);
    string get_narrateur();
    virtual ~LivreAudio();
};

#endif // LIVREAUDIO_H_INCLUDED
