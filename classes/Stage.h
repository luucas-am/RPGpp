#include <Enemy.h>
#include <Mage.h>
#include <vector>

#ifndef STAGE_H
#define STAGE_H

class Stage
{
    public:
        Enemy enemy;
        Mage mage;
        Stage(Enemy& enemy, Mage& mage);
        ~Stage();
        void showBattleMenu();
};

#endif