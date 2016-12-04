#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

// Headers du projet
#include "pion.h"
#include "console.h"
#include "case.h"
#include "animal.h"

class Plateau {
private:
    std::vector<Pion> m_montagnes;
    std::vector<std::vector<Case> > m_case;
    int m_longueur;
    int m_largeur;

public:
    Plateau();
    ~Plateau();
    void afficherPlateau(Console*pConsole);
};

#endif // PLATEAU_H_INCLUDED
