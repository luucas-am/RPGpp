#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

class Enemy;

class Character 
{
    public:
        std::string name;
        int maxHP, hp, maxMana, mana, strength, defense, speed, intelligence, level, experience, experienceToNextLevel;
        virtual void attackEnemy(Enemy& enemy) = 0;
        virtual void takeDamage(int damage) = 0;
        virtual void levelUp() = 0;
};

#endif