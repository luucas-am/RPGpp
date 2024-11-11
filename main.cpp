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

int main() {
    string options[2][2] = { { "Option 1", "Option 2" }, { "Option 3", "Option 4" } };
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
            case KEY_LEFT:
                if (currentOption.y > 0) currentOption.y--;
                break;
            case KEY_RIGHT:
                if (currentOption.y < 1) currentOption.y++;
                break;
            case KEY_ENTER:
                cout << "Selected option: " << options[currentOption.x][currentOption.y] << endl;
                system("pause");
                break;
            case KEY_ESC:
                cout << "Exiting..." << endl;
                return 0;
        }

        // Limpa a tela
        system("cls");
    }

    return 0;
}
