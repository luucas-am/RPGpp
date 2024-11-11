#include <Enemy.h>
#include <Character.h>

#ifndef DRAGON_H
#define DRAGON_H

class Dragon : public Enemy
{
    public:
        Dragon();
        ~Dragon();
        void attackCharacter(Character& character) override;
        void takeDamage(int damage) override;
};

#endif