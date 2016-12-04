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
    Pion(std::string _nom,float _resistance,bool _actif);
    ~Pion();
    float get_resistance() const;
    int get_lig() const;
    int get_col() const;
    std::string get_nom() const;
    void set_lig(int _ligne);
    void set_col(int _col);
};

#endif // PION_H_INCLUDED
