#include <Game.h>
#include <iostream>
#include <conio.h>
#include <windows.h> // Para `system("cls")` no Windows
#include <Point.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

Game::Game()
{
    score = 0;
}

Game::~Game() { }

void Game::showMainMenu()
{
    string options[2] = { "Start Game", "Exit" };
    string arrow = ">";
    Point currentOption = { 0, 0 };  // Posição inicial (0, 0)

    while (true) {
        // Desenha o menu 2x1 no terminal
        for (int i = 0; i < 2; i++) {
            if (i == currentOption.x) {
                cout << arrow << " " << options[i] << "\t"; // Exibe a seta antes da opção selecionada
            } else {
                cout << "  " << options[i] << "\t"; // Exibe um espaço em branco antes das demais opções
            }
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
                //if (currentOption.x == 0) startGame();
                //else if (currentOption.x == 1) return;
                break;
            case KEY_ESC:
                cout << "Exiting..." << endl;
                return;
        }
        system("cls");
    }
}