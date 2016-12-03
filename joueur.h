#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "includes.h"

class Joueur {
private:
    std::vector<Animal> m_animaux;
    std::string m_nom;

public:
    Joueur();
    ~Joueur();
    void entrerAnimal();
    void deplacerAnimal();
    void orienterAnimal();
    void sortirAnimal();
    void pousserAnimal();

};

#endif // JOUEUR_H_INCLUDED
