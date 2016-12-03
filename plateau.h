#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

// Headers du projet
#include "pion.h"
#include "console.h"
#include "case.h"

class Plateau {
private:
    std::vector<Pion> m_montagnes;
    std::vector<std::vector<Case> > m_case;
    int m_longueur;
    int m_largeur;

public:
    Plateau();
    Plateau(std::vector<std::vector<Case> > m_case);
    ~Plateau();
    void afficherPlateau();
};

#endif // PLATEAU_H_INCLUDED
