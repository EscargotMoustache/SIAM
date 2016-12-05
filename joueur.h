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
    bool m_victoire;

public:
    Joueur();
    Joueur(std::string _nom);
    ~Joueur();
    void entrerAnimal(Plateau& plat, char orientation, int x, int y);
    void deplacerAnimal(Plateau& plat, Animal* animal, char orientation, int x, int y);
    void orienterAnimal(Animal* animal, char orientation);
    void sortirAnimal(Animal* animal, Plateau& plat);
    bool pousserAnimal(Animal* anima, Plateau& plat);
    bool get_victoire() const;
    std::vector<Animal> get_animaux() const;
    std::string get_nom() const;

};

#endif // JOUEUR_H_INCLUDED
