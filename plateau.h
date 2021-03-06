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
    std::vector<std::vector<Case> > m_case;
    int m_longueur;
    int m_largeur;

public:
    Plateau();
    ~Plateau();
    void set_case(int x, int y, Animal *animal);
    void set_case(int x, int y, Pion *pion);
    Case get_case(int x, int y) const;
    void clear_case(int x, int y);
    bool is_case_surrounded(int x, int y);
    std::vector<std::vector<Case> > get_plateau() const;
};

#endif // PLATEAU_H_INCLUDED
