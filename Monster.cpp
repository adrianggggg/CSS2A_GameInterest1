#include <iostream>
#include <vector>
#include "Monster.hpp"


using namespace std;
/* Monster */

// constructor
Monster::Monster()
{
    name = "NA";
    type = "NA";
    attack = 0;
    special_attack = 0;
    defend = 0;
    hp = 0;
}

Monster::Monster(string name_, string type_, double attack_, double special_attack_, double defend_)
{
    name = name_;
    type = type_;
    attack = attack_;
    special_attack = special_attack_;
    defend = defend_;
    hp = 100;
}

// getters
string Monster::getName() const
{
    return name;
}
string Monster::getType() const
{
    return type;
}
double Monster::getAttack() const
{
    return attack;
}
double Monster::getSpecialAttack() const
{
    return special_attack;
}
double Monster::getDefend() const
{
    return defend;
}
double Monster::getHP() const
{
    return hp;
}

// setters
void Monster::setName(string name_)
{
    name = name_;
}
void Monster::setType(string type_)
{
    type = type_;
}
void Monster::setAttack(double attack_)
{
    attack = attack_;
}
void Monster::setSpecialAttack(double special_attack_)
{
    special_attack = special_attack_;
}
void Monster::setDefend(double defend_)
{
    defend = defend_;
}
void Monster::setHP(double hp_)
{
    hp = hp_;
}

// iostream overload
bool Monster::operator ==(const Monster& objectMonster_)
{
    return (this -> name == objectMonster_.getName());
}
ostream& operator <<(ostream& out, const Monster& objectMonster_)
{

    out << objectMonster_.getName() << " - ";

    if(objectMonster_.getHP() > 0)
    {
        out << "Ready to FIGHT!\n";
    }
    else
    {
        out << "Cannot FIGHT!\n";
    }
    out << objectMonster_.getType() << "\n";
    out << objectMonster_.getHP() << "\n";
    out << objectMonster_.getAttack() << "\n";
    out << objectMonster_.getSpecialAttack() << "\n";
    out << objectMonster_.getDefend() << "\n";

    return out;
}
