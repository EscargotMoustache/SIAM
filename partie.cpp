#include "partie.h"
#include "joueur.h"
#include "plateau.h"
#include "animal.h"

Partie::Partie()
{

}
Partie::~Partie()
{

}

void Partie::menu(int* choix)
{
    std::cout << " Bienvenu dans notre jeu SIAM !" <<std::endl;
    std::cout << " Que voulez vous faire ?" <<std::endl;
    std::cout << " 1. Jouer" <<std::endl;
    std::cout << " 2. Voir les regles" <<std::endl;
    std::cout << " 3. Quitter" <<std::endl;
    std::cin >> *choix;
    system("cls");
    switch (*choix)
    {
    case 1:
        std::cout << "jouer" << std::endl;
        break;
    case 2:
        std::cout << "regles" <<std::endl;
        break;
    case 3:
        std::cout << "quitter" <<std::endl;
        break;

    }

}
