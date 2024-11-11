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

Stage::Stage(Enemy& enemy, Mage& mage)
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
        // Desenha o menu 2x2 no terminal
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == currentOption.x && j == currentOption.y) {
                    cout << arrow << " " << options[i][j] << "\t"; // Exibe a seta antes da opção selecionada
                } else {
                    cout << "  " << options[i][j] << "\t"; // Exibe um espaço em branco antes das demais opções
                }
            }
            cout << endl;
        }

        // Lê a tecla pressionada
        int key = _getch();
        switch (key) {
            case KEY_UP:
                if (currentOption.x > 0) currentOption.x--;
                break;
            case KEY_DOWN:
                if (currentOption.x < 1) currentOption.x++;
                break;
            case KEY_ENTER:
                switch (currentOption.x) {
                    case 0:
                        switch (currentOption.y) {
                            case 0:
                                mage.attackEnemy(enemy);
                                break;
                            case 1:
                                mage.castFireball(enemy);
                                break;
                        }
                        break;
                    case 1:
                        switch (currentOption.y) {
                            case 0:
                                mage.castMagicMissile(enemy);
                                break;
                            case 1:
                                mage.castHeal();
                                break;
                        }
                        break;
                }
                break;
        }
        system("cls");
    }
}