#include <Mage.h>
#include <stdlib.h>

Mage::Mage()
{
    name = "Mage";
    maxHP = 80;
    hp = 80;
    maxMana = 100;
    mana = 100;
    strength = 5;
    defense = 4;
    speed = 10;
    intelligence = 15;
    level = 1;
    experience = 0;
    experienceToNextLevel = 50;
}

Mage::~Mage() { }

void Mage::attackEnemy(Enemy& enemy)
{
    int damage = strength + (rand() % 5) + (1 * level - enemy.level);
    enemy.takeDamage(damage);
}

void Mage::takeDamage(int damage)
{
    int calculatedDmg = ((damage - defense) / 2) >= 1 ? (damage - defense) / 2 : 1;
    hp -= calculatedDmg;
}

void Mage::levelUp()
{
    maxHP += 10;
    hp = maxHP;
    maxMana += 10;
    mana = maxMana;
    strength += 1;
    defense += 2;
    speed += 2;
    intelligence += 3;
    level++;
    experience = 0;
    experienceToNextLevel += level * 50 + 100;
}

void Mage::castFireball(Enemy& enemy)
{
    if (mana >= 10) {
        int damage = intelligence * 2 + (rand() % 10) + (1 * level - enemy.level);
        enemy.takeDamage(damage);
        mana -= 10;
    }
}

void Mage::castMagicMissile(Enemy& enemy)
{
    if (mana >= 5) {
        int damage = intelligence + (rand() % 5) + (1 * level - enemy.level);
        enemy.takeDamage(damage);
        mana -= 5;
    }
}

void Mage::castHeal()
{
    if (mana >= 10) {
        int heal = intelligence * 2 + (rand() % 10);
        hp += heal;  // Aplica a cura
        if (hp > maxHP) {
            hp = maxHP;  // Garante que a vida não exceda o máximo
        }
        mana -= 10;
    }
}