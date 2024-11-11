#include <Character.h>
#include <Enemy.h>

#ifndef MAGE_H
#define MAGE_H

class Mage : public Character 
{
    public:
        Mage();
        ~Mage();
        void attackEnemy(Enemy& enemy) override;
        void takeDamage(int damage) override;
        void levelUp() override;
        void castFireball(Enemy& enemy);
        void castMagicMissile(Enemy& enemy);
        void castHeal();
};

#endif