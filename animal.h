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
    Animal(std::string _nom);
    ~Animal();
    void entrer();
    void deplacer();
    void orienter();
    void pousser();
    void sortir();
};

#endif // ANIMAL_H_INCLUDED
