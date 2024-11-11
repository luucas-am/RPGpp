#include <Golem.h>
#include <stdlib.h>

Golem::Golem()
{
    name = "Golem";
    maxHP = 300;
    hp = 300;
    strength = 7;
    defense = 20;
    speed = 3;
    level = 7;
    experiencePoints = 170;
}

Golem::~Golem() { }

void Golem::attackCharacter(Character& character)
{
    int damage = strength + (rand() % 3) + (1 * level - character.level);
    character.takeDamage(damage);
}

void Golem::takeDamage(int damage)
{
    int calculatedDmg = (damage - defense) >= 1 ? damage - defense : 1;
    hp -= calculatedDmg;
}