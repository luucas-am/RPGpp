#include <Kobold.h>
#include <stdlib.h>

Kobold::Kobold()
{
    name = "Kobold";
    maxHP = 150;
    hp = 150;
    strength = 13;
    defense = 6;
    speed = 7;
    level = 5;
    experiencePoints = 130;
}

Kobold::~Kobold() { }

void Kobold::attackCharacter(Character& character)
{
    // Formula ataque
    int damage = strength + (rand() % 8) + (1 * level - character.level);
    character.takeDamage(damage);
}

void Kobold::takeDamage(int damage)
{
    // Formula defesa 
    int calculatedDmg = (damage - defense) >= 1 ? damage - defense : 1;
    hp -= calculatedDmg;
}