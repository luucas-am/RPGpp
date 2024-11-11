#include <Enemy.h>
#include <Character.h>

#ifndef GOLEM_H
#define GOLEM_H

class Golem : public Enemy
{
    public:
        Golem();
        ~Golem();
        void attackCharacter(Character& character) override;
        void takeDamage(int damage) override;
};

#endif