#include <Mage.h>
#include <Stage.h>
#include <conio.h>
#include <Point.h>
#include <iostream>
#include <windows.h> // Para `system("cls")` no Windows

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

Stage::Stage(Enemy* enemy, Mage* mage)
{
    this->enemy = enemy;
    this->mage = mage;
}

Stage::~Stage() { }

void Stage::showBattleMenu()
{
    string options[2][2] = { { "Attack", "Fireball" }, { "Magic Missile", "Heal" } };
    string arrow = ">";
    Point currentOption = { 0, 0 };  // Posição inicial (0, 0)

    while (true) {
        system("cls");

        // Exibe informações do Mago e do Inimigo
        cout << mage->name << " Lv. " << mage->level
             << "                             "
             << enemy->name << " Lv. " << enemy->level << endl;
        
        cout << "HP:"<< mage->hp << "/" << mage->maxHP
             << "                               "
             << "HP:" << enemy->hp << "/" << enemy->maxHP << endl;
        cout << "MP:" << mage->maxMana << "/" << mage->mana << endl;
        
        cout << "---------------------------------------------------------------------------------------------------" << endl;

        // Exibe o menu de combate 2x2
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == currentOption.x && j == currentOption.y) {
                    cout << arrow << " " << options[i][j] << "\t\t\t\t"; // Seta antes da opção selecionada
                } else {
                    cout << "  " << options[i][j] << "\t\t\t\t"; // Espaço antes das outras opções
                }
            }
            cout << endl;
        }

        // Lê a tecla pressionada
        bool heroAttacked = false;
        int key = _getch();
        switch (key) {
            case KEY_UP:
                if (currentOption.x > 0) currentOption.x--;
                break;
            case KEY_DOWN:
                if (currentOption.x < 1) currentOption.x++;
                break;
            case KEY_LEFT:
                if (currentOption.y > 0) currentOption.y--;
                break;
            case KEY_RIGHT:
                if (currentOption.y < 1) currentOption.y++;
                break;
            case KEY_ENTER:
                switch (currentOption.x) {
                    case 0:
                        switch (currentOption.y) {
                            case 0:
                                mage->attackEnemy(*enemy);
                                heroAttacked = true;
                                break;
                            case 1:
                                mage->castFireball(*enemy);
                                heroAttacked = true;
                                break;
                        }
                        break;
                    case 1:
                        switch (currentOption.y) {
                            case 0:
                                mage->castMagicMissile(*enemy);
                                heroAttacked = true;
                                break;
                            case 1:
                                mage->castHeal();
                                heroAttacked = true;
                                break;
                        }
                        break;
                }
                break;
        }
        system("cls");

        // Verifica se o inimigo morreu
        if (enemy->hp <= 0) {
            cout << "You defeated the " << enemy->name << "!" << endl;
            cout << "You gained " << enemy->experiencePoints * (1 + (enemy->level - mage->level)) << " experience points!";
            mage->experience += enemy->experiencePoints * (1 + (enemy->level - mage->level));
            std::cin.ignore();

            // Verifica se o Mago subiu de nível
            if (mage->experience >= mage->experienceToNextLevel) {
                mage->levelUp();
                cout << "You leveled up! You are now level " << mage->level << "!";
                std::cin.ignore();
            }
            return;
        }

        // Vez do inimigo
        if (heroAttacked) {
            enemy->attackCharacter(*mage);
            heroAttacked = false;
        }

        // Verifica se o Mago morreu
        if (mage->hp <= 0) {
            cout << "You were defeated by the " << enemy->name << "!" << endl;
            std::cin.ignore();
            return;
        }

        system("cls");
    }
}