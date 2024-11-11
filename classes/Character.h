#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

class Enemy;

class Character 
{
    public:
        std::string name;
        int maxHP, hp, maxMana, mana, strength, defense, speed, intelligence, level, experience, experienceToNextLevel;
        virtual void attackEnemy(Enemy& enemy) {};
        virtual void takeDamage(int damage) {};
        virtual void levelUp() {};
};

#endif