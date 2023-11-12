#include <iostream>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "BattleScreen.h"

using namespace std;

// constructor
BattleScreen::BattleScreen(Monster toAttack_, Monster toDefend_)
{
    toAttack = toAttack_;
    toDefend = toDefend_;
}

// setters
Monster BattleScreen::getToAttack() const
{
    return toAttack;
}

Monster BattleScreen::getToDefend() const
{
    return toDefend;
}

// member functions
int BattleScreen::battleMenu()
{
    int userChoice_;
    cout << "[1] Attack\n";
    cout << "[2] Defend\n";
    cout << "[3] Special Attack\n";
    cout << "Select: ";
    cin >> userChoice_;

    return userChoice_;

}


void BattleScreen::dealDamage()
{
    toDefend.setMonsterHP(toDefend.getMonsterHP() - toAttack.getMonsterAttack());

}

/*
{
    if(toAttack -> getMonsterType() == "Water" && toDefend -> getMonsterType() == "Fire")
    {
        toDefend -> setMonsterHP((toAttack -> getMonsterAttack()*1.25));
    }
    else if(toAttack -> getMonsterType() == "Fire" && toDefend -> getMonsterType() == "Earth")
    {
        toDefend -> setMonsterHP((toAttack -> getMonsterAttack()*1.25));
    }
    else if(toAttack -> getMonsterType() == "Earth" && toDefend -> getMonsterType() == "Water")
    {
        toDefend -> setMonsterHP((toAttack -> getMonsterAttack()*1.25));
    }
    else
    {
        *toDefend.setMonsterHP((*toAttack.getMonsterAttack()*1));
    }

}
*/

void BattleScreen::battleUI()
{
    cout << "_______________________________________________________________________________\n";
    cout << "\n                               Monster Name: " << toDefend.getMonsterName() << "\n";
    cout << "                                   Monster HP: " << toDefend.getMonsterHP() << "\n";
    cout << "Monster Name: " << toAttack.getMonsterName() << "\n";
    cout << "  Monster HP: " << toAttack.getMonsterHP() << "\n";
    cout << "________________________________________________________________________________\n\n";
}

void dealDefense();
