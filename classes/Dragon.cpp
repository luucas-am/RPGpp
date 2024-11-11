#include <Dragon.h>
#include <stdlib.h>

Dragon::Dragon()
{
    name = "Teiu";
    maxHP = 450;
    hp = 450;
    strength = 20;
    defense = 15;
    speed = 9;
    level = 10;
    experiencePoints = 9999;
}

Dragon::~Dragon() { }

void Dragon::attackCharacter(Character& character)
{
    // Formula ataque
    int damage = strength * 1.5 + (rand() % 10) + (1 * level - character.level);
    character.takeDamage(damage);
}

void Dragon::takeDamage(int damage)
{
    // Formula defesa
    int calculatedDmg = (damage - defense) >= 1 ? damage - defense : 1;
    hp -= calculatedDmg;
}