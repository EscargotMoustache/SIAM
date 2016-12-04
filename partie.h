#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>

// Headers du projet
#include "plateau.h"
#include "joueur.h"


class Partie {
private:
    Plateau m_plateau;
    int m_nbTour;
    std::vector<Joueur> vect;

public:
    Partie();
    ~Partie();
    void bouclePartie();
    void menu(int* choix);
};

#endif // PARTIE_H_INCLUDED
