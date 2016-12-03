#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

#include "includes.h"

class Pion {
protected:
    std::string m_nom;
    float m_resistance;
    int m_lig;
    int m_col;
    bool m_actif;

public:
    Pion();
    ~Pion();
};

#endif // PION_H_INCLUDED
