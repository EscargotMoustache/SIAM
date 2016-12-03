#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>


class Pion {
protected:
    std::string m_nom;
    float m_resistance;
    int m_lig;
    int m_col;
    bool m_actif;

public:
    Pion();
    Pion(std::string _nom);
    ~Pion();
    std::string getnom() const;
};

#endif // PION_H_INCLUDED
