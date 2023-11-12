#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "BattleScreen.h"

/* Monster */
//constructors
Monster::Monster()
{
    monsterName = "NA";
    monsterType = "NA";
    monsterHP = 0;
    monsterAttack = 0;
    monsterAttackSpecial = 0;
    monsterDefense = 0;
}

Monster::Monster(std::string name_, std::string type_, int attack_, int special_attack_, double defense_)
{
    monsterName = name_;
    monsterType = type_;
    monsterAttack = attack_;
    monsterAttackSpecial = special_attack_;
    monsterDefense = defense_;
    monsterHP = 100;
}


// getters
std::string Monster::getMonsterName() const
{
    return monsterName;
}

double Monster::getMonsterAttack() const
{
    return monsterAttack;
}

double Monster::getMonsterSpecialAttack() const
{
    return monsterAttackSpecial;
}

double Monster::getMonsterDefense() const
{
    return monsterDefense;
}

double Monster::getMonsterHP() const
{
    return monsterHP;
}

std::string Monster::getMonsterType() const
{
    return monsterType;
}

// setters
void Monster::setMonsterType(std::string type_)
{
    monsterType = type_;
}

void Monster::setMonsterAttack(double attack_)
{
    monsterAttack = attack_;
}

void Monster::setMonsterSpecialAttack(double special_attack_)
{
    monsterAttackSpecial = special_attack_;
}

void Monster::setMonsterDefense(double defense_)
{
    monsterDefense = defense_;
}

void Monster::setMonsterHP(double hp_)
{
    monsterHP = hp_;
}
