#include <Game.h>
#include <iostream>
#include <conio.h>
#include <windows.h> // Para `system("cls")` no Windows
#include <Point.h>
#include <Slime.h>
#include <Skeleton.h>
#include <Dragon.h>
#include <Kobold.h>
#include <Golem.h>

using namespace std;

// Define as teclas de controle
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
    // Limpa a tela
    system("cls");

    // Opções do menu
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
            case KEY_LEFT:
                if (currentOption.x > 0) currentOption.x--;
                break;
            case KEY_RIGHT:
                if (currentOption.x < 1) currentOption.x++;
                break;
            case KEY_ENTER:
                if (currentOption.x == 0) startGame();
                else if (currentOption.x == 1) return;
                break;
            case KEY_ESC:
                cout << "Exiting..." << endl;
                return;
        }
        system("cls");
    }
}

void Game::startGame()
{
    system("cls");
    cout << "Starting game..." << endl;
    Sleep(1000);
    system("cls");

    // Inicializa o jogo
    Mage hero = Mage();
    Slime slime = Slime();
    Skeleton skeleton = Skeleton();
    Kobold kobold = Kobold();
    Golem golem = Golem();
    Dragon dragon = Dragon();

    stages.push_back(Stage(&slime, &hero));
    stages.push_back(Stage(&skeleton, &hero));
    stages.push_back(Stage(&kobold, &hero));
    stages.push_back(Stage(&golem, &hero));
    stages.push_back(Stage(&dragon, &hero));

    // Inicia o primeiro estágio
    for (int i = 0; i < stages.size(); i++) {
        stages[i].showBattleMenu();

        // Verifica se o herói ainda está vivo
        if (isGameOver(hero)) {
            showGameOver();
            return;
        } else {
            score += hero.level * 100 + hero.hp * 10 + hero.mana * 5;
            cout << "Stage " << i + 1 << " cleared!" << endl;
            std::cin.ignore();

            // Exibe a mensagem de vitória
            if (i == stages.size() - 1) {
                system("cls");
                cout << "Congratulations! You have completed all stages!" << endl;
                cout << "Score: " << score << endl;
                system("pause");
            }
        }
    }
}

void Game::showGameOver()
{
    cout << "Game Over!" << endl;
    cout << "Score: " << score << endl;
    system("pause");
}

bool Game::isGameOver(Character& character)
{
    if (character.hp <= 0) return true;
    else return false;
}