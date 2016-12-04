#include "pion.h"

Pion::Pion()
{

}
Pion::Pion(std::string _nom,float _resistance, bool _actif)
{
    m_nom=_nom;
    m_resistance=_resistance;
    m_actif=_actif;
}

Pion::~Pion()
{

}

float Pion::getresistance() const
{
    return m_resistance;
}
int Pion::getlig() const
{
    return m_lig;
}
int Pion::getcol() const
{
    return m_col;
}
std::string Pion::getnom() const
{
    return m_nom;
}
void Pion::setlig(int _ligne)
{
    m_lig=_ligne;
}
void Pion::setcol(int _col)
{
    m_col=_col;
}
