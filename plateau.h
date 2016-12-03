#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "includes.h"

class Plateau {
private:
    std::vector<Pion> m_montagnes;
    int m_longueur;
    int m_largeur;

public:
    Plateau();
    ~Plateau();
    void afficherPlateau();
};

#endif // PLATEAU_H_INCLUDED
