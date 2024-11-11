#include <Slime.h>
#include <stdlib.h>
#include <iostream>

Slime::Slime()
{
    name = "Slime";
    maxHP = 50;
    hp = 50;
    strength = 6;
    defense = 3;
    speed = 5;
    level = 1;
    experiencePoints = 50;
}

Slime::~Slime() { }

void Slime::attackCharacter(Character& character)
{
    int damage = strength + (rand() % 5) + (1 * level - character.level);
    character.takeDamage(damage);
}

void Slime::takeDamage(int damage)
{
    int calculatedDmg = (damage - defense) >= 1 ? damage - defense : 1;
    hp -= calculatedDmg;

    // Garante que o HP não fique abaixo de zero
    if (hp < 0) {
        hp = 0;
    }
}