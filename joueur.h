#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

// Headers du projet
#include "animal.h"
#include "plateau.h"

class Joueur {
private:
    std::vector<Animal> m_animaux;
    std::string m_nom;

public:
    Joueur();
    Joueur(std::string _nom);
    ~Joueur();
    void entrerAnimal(Plateau& plat, char orientation, int x, int y);
    void deplacerAnimal();
    void orienterAnimal();
    void sortirAnimal();
    void pousserAnimal();
    std::vector<Animal> get_animaux() const;

};

#endif // JOUEUR_H_INCLUDED
