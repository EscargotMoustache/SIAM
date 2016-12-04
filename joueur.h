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
    Joueur(std::string _nom,std::vector<Animal> _animaux);
    ~Joueur();
    void entrerAnimal(std::vector<Animal>& E, std::vector<Animal>& R, int _nbtour);
    void deplacerAnimal();
    void orienterAnimal();
    void sortirAnimal();
    void pousserAnimal();

};

#endif // JOUEUR_H_INCLUDED
