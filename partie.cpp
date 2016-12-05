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

    m_plateau = Plateau();

    for (int i = 0; i < 3; i++)
    {
        m_montagnes.push_back(Pion("M", 0.9f, true));
    }

    for (int i = 1; i < 4; i++)
    {
        this->m_plateau.set_case(i, 2, &m_montagnes.at(i - 1));
    }
}

Partie::~Partie()
{

}

void Partie::bouclePartie(Console *pConsole)
{
    char y, orientation;
    int lig, col;
    int tour = 0;

    do
    {
        int joueur_actuel = tour % 2;
        this->afficher(pConsole);
        pConsole->gotoLigCol(7,0);

        cout << " Joueur " << this->m_joueurs[joueur_actuel].get_nom() << " que voulez-vous faire ? (Tour " << tour + 1 << ")" << endl;
        cout << " a. Faire entrer un pion" << endl;
        cout << " d. Deplacer un pion sur le plateau" << endl;
        cout << " o. Orienter un pion" << endl;
        cout << " p. Pousser avec un pion" << endl;
        cout << " s. Sortir un pion du plateau" << endl;
        cout << " q. Quitter la partie" << endl;

        cin >> y;
        if (y == 'a')
        {
            cout << "Entrez la ligne : ";
            cin >> lig;
            cout << "Entrez la colonne : ";
            cin >> col;
            cout << "Quelle orientation ? (h, b, g, d) : ";
            cin >> orientation;

            if (!((col >= 1 && col <= 5 && (lig == 1 || lig == 5)) ||
                  (lig >= 1 && lig <= 5 && (col == 1 || col == 5))))
            {
                cout << "Position invalide !";
                while(!pConsole->isKeyboardPressed());
            }
            else
            {
                if (this->m_plateau.get_plateau().at(lig - 1).at(col - 1).get_animal() == nullptr)
                {
                    this->m_joueurs[joueur_actuel].entrerAnimal(this->m_plateau, orientation, lig - 1, col - 1);
                    tour++;
                }
                else
                {
                    cout << "Position invalide !";
                    while(!pConsole->isKeyboardPressed());
                }
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
                    if (this->m_plateau.get_plateau().at(i).at(j).get_animal() != nullptr && this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() == this->m_joueurs[joueur_actuel].get_nom())
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
                    Animal* temp_animal = disponibles.at(pion - 1);

                    cout << "Ou souhaitez-vous le deplacer ? " << endl;
                    cout << "Ligne : ";
                    cin >> lig;
                    cout << "Colonne : ";
                    cin >> col;
                    cout << "Orientation : ";
                    cin >> orientation;

                    lig--;
                    col--;

                    if ((lig == temp_animal->get_lig() + 1 || lig == temp_animal->get_lig() - 1 || lig == temp_animal->get_lig()) &&
                        (col == temp_animal->get_col() + 1 || col == temp_animal->get_col() - 1 || col == temp_animal->get_col()))
                    {
                        this->m_joueurs[joueur_actuel].deplacerAnimal(this->m_plateau, temp_animal, orientation, lig, col);
                        tour++;
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
        else if (y == 's')
        {
            vector<Animal*> disponibles;
            int compteur = 0, pion;

            cout << "Pions disponibles a la sortie : " << endl;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (this->m_plateau.get_plateau().at(i).at(j).get_animal() != nullptr && this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() == this->m_joueurs[joueur_actuel].get_nom())
                    {
                        if (!((j >= 1 && j <= 5 && (i == 0 || i == 5)) ||
                              (i >= 1 && i <= 5 && (j == 1 || j == 5))))
                        {
                            compteur++;
                            cout << compteur << ". " << this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() << " en " << i + 1 << ", " << j + 1 << endl;
                            disponibles.push_back(this->m_plateau.get_plateau().at(i).at(j).get_animal());
                        }
                    }
                }
            }

            if (compteur == 0)
            {
                cout << "Aucun pion ne peut sortir !";
                while(!pConsole->isKeyboardPressed());
            }
            else
            {
                cout << "Quel pion souhaitez-vous sortir ? ";
                cin >> pion;
                if (pion <= compteur)
                {
                    Animal* temp_animal = disponibles.at(pion - 1);

                    this->m_joueurs[joueur_actuel].sortirAnimal(temp_animal, this->m_plateau);
                    tour++;
                }
                else
                {
                    cout << "Ce pion n'existe pas !";
                    while(!pConsole->isKeyboardPressed());
                }
            }
        }
        else if (y == 'p')
        {
            vector<Animal*> disponibles;
            int compteur = 0, pion;

            cout << "Pions disponibles pour pousser : " << endl;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (this->m_plateau.get_plateau().at(j).at(i).get_animal() != nullptr && this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() == this->m_joueurs[joueur_actuel].get_nom())
                    {
                        if (this->m_plateau.is_case_surrounded(i, j))
                        {
                            compteur++;
                            cout << compteur << ". " << this->m_plateau.get_plateau().at(j).at(i).get_animal()->get_nom() << " en " << i + 1 << ", " << j + 1 << endl;
                            disponibles.push_back(this->m_plateau.get_plateau().at(j).at(i).get_animal());
                        }
                    }
                }
            }

            if (compteur == 0)
            {
                cout << "Aucun pion ne peut pousser !";
                while(!pConsole->isKeyboardPressed());
            }
            else
            {
                cout << "Quel pion souhaitez-vous faire pousser ? ";
                cin >> pion;
                if (pion <= compteur)
                {
                    Animal* temp_animal = disponibles.at(pion - 1);

                    if (this->m_joueurs[joueur_actuel].pousserAnimal(temp_animal, this->m_plateau) == true)
                    {
                        tour++;
                    }
                    else
                    {
                        while(!pConsole->isKeyboardPressed());
                    }
                    if (this->m_joueurs[joueur_actuel].get_victoire() == true)
                    {
                        cout << "Le joueur " << this->m_joueurs[joueur_actuel].get_nom() << " gagne la partie !" << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Ce pion n'existe pas !";
                    while(!pConsole->isKeyboardPressed());
                }
            }
        }
        else if (y == 'o')
        {
            vector<Animal*> disponibles;
            int compteur = 0, pion;

            cout << "Pions disponibles : " << endl;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (this->m_plateau.get_plateau().at(i).at(j).get_animal() != nullptr && this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() == this->m_joueurs[joueur_actuel].get_nom())
                    {
                        if (!((j >= 1 && j <= 5 && (i == 0 || i == 5)) ||
                              (i >= 1 && i <= 5 && (j == 1 || j == 5))))
                        {
                            compteur++;
                            cout << compteur << ". " << this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() << " en " << i + 1 << ", " << j + 1 << endl;
                            disponibles.push_back(this->m_plateau.get_plateau().at(i).at(j).get_animal());
                        }
                    }
                }
            }

            if (compteur == 0)
            {
                cout << "Aucun pion disponible !";
                while(!pConsole->isKeyboardPressed());
            }
            else
            {
                cout << "Quel pion souhaitez-vous orienter ? ";
                cin >> pion;
                cout << "Dans quelle direction ? (h, b, g, d) ";
                cin >> orientation;
                if (pion <= compteur)
                {
                    Animal* temp_animal = disponibles.at(pion - 1);

                    this->m_joueurs[joueur_actuel].orienterAnimal(temp_animal, orientation);
                    tour++;
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
        choix = 0;
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
        cout << "     " << i + 1 << "  ";

        for (int j = 0; j < 5; j++)
        {
            if (this->m_plateau.get_plateau().at(i).at(j).get_animal() == nullptr && this->m_plateau.get_plateau().at(i).at(j).get_montagne() == nullptr)
                cout << "- ";
            else if (this->m_plateau.get_plateau().at(i).at(j).get_montagne() != nullptr)
                cout << this->m_plateau.get_plateau().at(i).at(j).get_montagne()->get_nom() << " ";
            else
                cout << this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_nom() << this->m_plateau.get_plateau().at(i).at(j).get_animal()->get_dir();
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
