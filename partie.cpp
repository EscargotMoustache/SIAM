#include "partie.h"
#include "joueur.h"
#include "plateau.h"
#include "animal.h"

using namespace std;
Partie::Partie()
{
    Joueur j1("E");
    Joueur j2("R");
    m_joueurs.push_back(j1);
    m_joueurs.push_back(j2);
}
Partie::~Partie()
{

}
void Partie::bouclePartie(Console*pConsole)
{
    char y;
    do
    {
        this->afficher(pConsole);
        pConsole->gotoLigCol(7,0);
        std::cin >> y;
        this->m_joueurs[0].entrerAnimal();
        system("cls");

    }while(y!='q');
}
void Partie::menu(Console*pConsole)
{
    int choix=0;
    std::cout << " Bienvenu dans notre jeu SIAM !" <<std::endl;
    std::cout << " Que voulez vous faire ?" <<std::endl;
    std::cout << " 1. Jouer" <<std::endl;
    std::cout << " 2. Voir les regles" <<std::endl;
    std::cout << " 3. Quitter" <<std::endl;
    std::cin >> choix;
    system("cls");
    switch (choix)
    {
    case 1:
        this->bouclePartie(pConsole);
        break;
    case 2:
        std::cout << "regles" <<std::endl;
        break;
    case 3:
        std::cout << "quitter" <<std::endl;
        break;
    }
}
void Partie::afficher(Console*pConsole)
{
    int i=0;
    cout << "        A B C D E   "<<endl;
    cout << "     1  - - - - -   "<< endl;
    cout << "     2  - - - - -   "<< endl;
    cout << "     3  - - - - -   "<< endl;
    cout << "     4  - - - - -   "<< endl;
    cout << "     5  - - - - -   "<< endl;

    pConsole->gotoLigCol(1,1);

    for ( auto& elem : this->m_joueurs[0].getanimaux())
    {
        cout << elem.getnom()<< endl << " " ;
    }
    pConsole->gotoLigCol(1,20);
    for ( auto& elem : this->m_joueurs[1].getanimaux())
    {
        cout << elem.getnom()<< endl ;
        i=i+1;
        pConsole->gotoLigCol(1+i,20);
    }
}
