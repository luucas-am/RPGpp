#include <Enemy.h>
#include <Character.h>

#ifndef SLIME_H
#define SLIME_H

class Slime : public Enemy
{
    public:
        Slime();
        ~Slime();
        void attackCharacter(Character& character) override;
        void takeDamage(int damage) override;
};

#endif