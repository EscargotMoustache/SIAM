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
void Partie::bouclePartie(Plateau plat,Joueur jou,std::vector<Animal> E_vect,std::vector<Animal> R_vect,Console*pConsole,int i,int _nbTour)
{
    char y;
    do
    {
        plat.afficherPlateau(plat,E_vect,R_vect,pConsole,i);
        pConsole->gotoLigCol(7,0);
        std::cin >> y;
        //jou.entrerAnimal(E_vect,R_vect,_nbTour);
        system("cls");


    }while(y!='q');
}
void Partie::menu(Partie part,Plateau plat,Joueur jou,std::vector<Animal> E_vect,std::vector<Animal> R_vect,Console*pConsole,int i,int _nbtour,int*choix)
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
        //std::cout << "jouer" << std::endl;
        part.bouclePartie(plat,jou,E_vect,R_vect,pConsole,i,_nbtour);
        break;
    case 2:
        std::cout << "regles" <<std::endl;
        break;
    case 3:
        std::cout << "quitter" <<std::endl;
        break;
    }
}
