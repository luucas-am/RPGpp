#include <string>

#ifndef ENEMY_H
#define ENEMY_H

class Character;

class Enemy
{
    public:
        std::string name;
        int maxHP, hp, strength, defense, speed, level, experiencePoints;
        virtual void attackCharacter(Character& character) {};
        virtual void takeDamage(int damage) {};
};

#endif