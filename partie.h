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
    std::vector<Joueur> m_joueurs;
    std::vector<Pion> m_montagnes;

public:
    Partie();
    ~Partie();
    void bouclePartie(Console*pConsole);
    void menu(Console*pConsole);
    void afficher(Console*pConsole);
};

#endif // PARTIE_H_INCLUDED
