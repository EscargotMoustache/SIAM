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

float Pion::get_resistance() const
{
    return m_resistance;
}

int Pion::get_lig() const
{
    return m_lig;
}

int Pion::get_col() const
{
    return m_col;
}

std::string Pion::get_nom() const
{
    return m_nom;
}

void Pion::set_lig(int _ligne)
{
    m_lig=_ligne;
}

void Pion::set_col(int _col)
{
    m_col=_col;
}
