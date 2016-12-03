#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

// Headers du projet
#include "animal.h"

class Joueur {
private:
    std::vector<Animal> m_animaux;
    std::string m_nom;

public:
    Joueur();
    ~Joueur();
    void entrerAnimal(std::vector<Animal>& E, std::vector<Animal>& R, int*tour);
    void deplacerAnimal();
    void orienterAnimal();
    void sortirAnimal();
    void pousserAnimal();

};

#endif // JOUEUR_H_INCLUDED
