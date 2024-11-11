#include <iostream>
#include <conio.h>
#include <windows.h> // Para `system("cls")` no Windows

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Character {
public:
    string name;
    int hp;
    int attack;
    int defense;

    Character(string name, int hp, int attack, int defense)
        : name(name), hp(hp), attack(attack), defense(defense) {}

    void displayStatus() const {
        cout << name << " - HP: " << hp << ", Ataque: " << attack << ", Defesa: " << defense << endl;
    }
    
    void takeDamage(int damage) {
        hp -= (damage > 0) ? damage : 0;
    }

    int attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        enemy.takeDamage(damage);
        return damage;
    }
};

class Menu {
public:
    string options[2][2];
    Point currentOption;
    string arrow;

    Menu() : options{{"Atacar", "Defender"}, {"Magia", "Fugir"}}, currentOption(0, 0), arrow(">") {}

    void displayMenu() {
        system("cls");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == currentOption.x && j == currentOption.y) {
                    cout << arrow << " " << options[i][j] << "\t";
                } else {
                    cout << "  " << options[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }

    void navigateMenu(int key) {
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
        }
    }

    string selectOption() const {
        return options[currentOption.x][currentOption.y];
    }
};

class Game {
private:
    Character player;
    Character enemy;
    Menu menu;

public:
    Game() : player("Jogador", 100, 20, 5), enemy("Inimigo", 80, 15, 3) {}

    void start() {
        while (player.hp > 0 && enemy.hp > 0) {
            player.displayStatus();
            enemy.displayStatus();
            menu.displayMenu();

            int key = _getch();
            if (key == KEY_ESC) {
                cout << "Saindo do jogo..." << endl;
                break;
            } else if (key == KEY_ENTER) {
                executeTurn();
            } else {
                menu.navigateMenu(key);
            }
        }
    }

    void executeTurn() {
        string action = menu.selectOption();

        if (action == "Atacar") {
            int damage = player.attackEnemy(enemy);
            cout << player.name << " atacou e causou " << damage << " de dano!" << endl;
        } else if (action == "Defender") {
            cout << player.name << " se defendeu!" << endl;
            player.defense += 3;
        } else if (action == "Magia") {
            int damage = player.attack * 2 - enemy.defense;
            enemy.takeDamage(damage);
            cout << player.name << " lançou uma magia e causou " << damage << " de dano!" << endl;
        } else if (action == "Fugir") {
            cout << player.name << " fugiu da batalha!" << endl;
            return;
        }

        // Turno do inimigo
        if (enemy.hp > 0) {
            int damage = enemy.attackEnemy(player);
            cout << enemy.name << " atacou e causou " << damage << " de dano!" << endl;
        }

        // Resetar defesa do jogador caso ele tenha defendido no turno anterior
        if (action == "Defender") {
            player.defense -= 3;
        }

        system("pause");
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}