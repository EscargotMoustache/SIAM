#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

// Headers du projet
#include "pion.h"
class Animal : public Pion {
private:
    char m_direction;
    float m_force;

public:
    Animal();
    Animal(std::string _nom, float _resistance, bool _actif, float _force);
    ~Animal();
    void entrer();
    void deplacer();
    void pousser();
    void sortir();
    char get_dir() const;
    void set_dir(char _direction);
};

#endif // ANIMAL_H_INCLUDED
