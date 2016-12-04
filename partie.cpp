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

void Partie::bouclePartie(Console *pConsole)
{
    char y, orientation;
    int lig, col;
    do
    {
        this->afficher(pConsole);
        pConsole->gotoLigCol(7,0);

        cout << " Que voulez-vous faire ?" << endl;
        cout << " a. Faire entrer un pion" << endl;
        cout << " d. Deplacer un pion sur le plateau" << endl;
        cout << " s. Sortir un pion du plateau" << endl;

        cin >> y;
        if (y == 'a')
        {
            cout << "Entrez la ligne : ";
            cin >> lig;
            cout << "Entrez la colonne : ";
            cin >> col;
            cout << "Quelle orientation ? (h, b, g, d) : ";
            cin >> orientation;

            if (!((col >= 1 && col <= 5 && (lig == 0 || lig == 5)) ||
                  (lig >= 1 && lig <= 5 && (col == 1 || col == 5))))
            {
                cout << "Position invalide !";
                while(!pConsole->isKeyboardPressed());
            }
            else
            {
                this->m_joueurs[0].entrerAnimal(this->m_plateau, orientation, lig - 1, col - 1);
            }
        }
        else if (y == 'd')
        {
            vector<Animal*> disponibles;
            int compteur = 0, pion;

            cout << "Pions disponibles au deplacement : " << endl;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (!(this->m_plateau.get_plateau().at(i).at(j).get_animal() == nullptr))
                    {
                        compteur++;
                        cout << compteur << ". " << this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() << " en " << i + 1 << ", " << j + 1 << endl;
                        disponibles.push_back(this->m_plateau.get_plateau().at(i).at(j).get_animal());
                    }
                }
            }

            if (compteur == 0)
            {
                cout << "Pas de pions disponibles au deplacement !";
                while(!pConsole->isKeyboardPressed());
            }
            else
            {
                cout << "Quel pion souhaitez-vous deplacer ? ";
                cin >> pion;
                if (pion <= compteur)
                {
                    auto temp_animal = disponibles.at(pion - 1);

                    cout << "Ou souhaitez-vous le déplacer ? " << endl;
                    cout << "Ligne : ";
                    cin >> lig;
                    cout << "Colonne : ";
                    cin >> col;
                    cout << "Orientation : ";
                    cin >> orientation;

                    if ((lig == temp_animal->get_lig() + 1 || lig == temp_animal->get_lig() - 1) &&
                        (col == temp_animal->get_col() + 1 || col == temp_animal->get_col() - 1))
                    {
                        //this->m_plateau.get_plateau().at(i).at(j)
                    }
                    else
                    {
                        cout << "Position de destination invalide.";
                        while(!pConsole->isKeyboardPressed());
                    }

                }
                else
                {
                    cout << "Ce pion n'existe pas !";
                    while(!pConsole->isKeyboardPressed());
                }
            }

        }

        system("cls");

    } while(y != 'q');
}

void Partie::menu(Console *pConsole)
{
    int choix = 0;
    do
    {
        cout << " Bienvenue dans notre jeu SIAM !" << endl;
        cout << " Que voulez vous faire ?" << endl;
        cout << " 1. Jouer" << endl;
        cout << " 2. Voir les regles" << endl;
        cout << " 3. Quitter" << endl;

        cin >> choix;

        system("cls");

        switch (choix)
        {
        case 1:
            this->bouclePartie(pConsole);
            break;
        case 2:
            cout << "Regles" << endl;
            cout << "Le jeu se compose d'un plateau ou 2 joueurs disposent de 5 animaux chacun." << endl;
            cout << "Le premier joueur utilise des elephants et le second des rhinoceros." << endl;
            cout << "Le but du jeu est de faire sortir une montagne du terrain, se situant au milieu du plateau" << endl;
            cout << "Le gagnant est le joueur qui possede l'animal le plus proche de la montagne" << endl;
            cout << "dans le sens de la poussee." << endl << endl;
            cout << "Les joueurs ont la possibilite de faire rentrer leurs pions sur les bords du terrain" << endl;
            cout << "dans la direction qu'ils souhaitent." << endl;
            cout << "Ils peuvent ensuite les faire sortir pour pouvoir les reutiliser plus tard" << endl << endl;
            while(!pConsole->isKeyboardPressed());
            system("cls");
            break;
        case 3:
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
        }
    } while(choix != 3);
}

void Partie::afficher(Console *pConsole)
{
    int i = 0;

    cout << "        A B C D E   " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "     " << i + 1 << " ";

        for (int j = 0; j < 5; j++)
        {
            if (this->m_plateau.get_plateau().at(i).at(j).get_animal() == nullptr)
                cout << " -";
            else
                cout << " " << this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom();
        }

        cout << endl;
    }

    pConsole->gotoLigCol(1, 1);

    for ( auto& elem : this->m_joueurs[0].get_animaux())
    {
        cout << elem.get_nom()<< endl << " " ;
    }
    pConsole->gotoLigCol(1,20);
    for ( auto& elem : this->m_joueurs[1].get_animaux())
    {
        cout << elem.get_nom()<< endl ;
        i=i+1;
        pConsole->gotoLigCol(1+i,20);
    }
}
