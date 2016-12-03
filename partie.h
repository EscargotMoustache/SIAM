#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "includes.h"

class Partie {
private:
    Plateau m_plateau;
    int m_nbTour;
    std::vector<Joueur>

public:
    Partie();
    ~Partie();
    void bouclePartie();
    void menu();
};

#endif // PARTIE_H_INCLUDED
