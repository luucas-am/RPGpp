#include <Skeleton.h>
#include <stdlib.h>

Skeleton::Skeleton()
{
    name = "Skeleton";
    maxHP = 100;
    hp = 100;
    strength = 10;
    defense = 8;
    speed = 9;
    level = 3;
    experiencePoints = 200;
}

Skeleton::~Skeleton() { }

void Skeleton::attackCharacter(Character& character)
{
    int damage = strength + (rand() % 10) + (1 * level - character.level);
    character.takeDamage(damage);
}

void Skeleton::takeDamage(int damage)
{
    int calculatedDmg = ((damage - defense) / 2) >= 1 ? (damage - defense) / 2 : 1;
    hp -= calculatedDmg;
}