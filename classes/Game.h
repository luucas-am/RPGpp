#include <Character.h>
#include <Enemy.h>
#include <vector>
#include <Stage.h>

#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        std::vector<Stage> stages;
        int score;
        Game();
        ~Game();
        void showMainMenu();
    private:
        void startGame();
        void showGameOver();
        bool isGameOver(Character& character);
};

#endif