#include <Enemy.h>
#include <Character.h>

#ifndef SKELETON_H
#define SKELETON_H

class Skeleton : public Enemy
{
    public:
        Skeleton();
        ~Skeleton();
        void attackCharacter(Character& character) override;
        void takeDamage(int damage) override;
};

#endif