#include <Enemy.h>
#include <Character.h>

#ifndef KOBOLD_H
#define KOBOLD_H

class Kobold : public Enemy
{
    public:
        Kobold();
        ~Kobold();
        void attackCharacter(Character& character) override;
        void takeDamage(int damage) override;
};

#endif