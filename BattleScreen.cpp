#include <iostream>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "BattleScreen.h"

using namespace std;

// constructor
BattleScreen::BattleScreen(Monster toAttack_, Monster toDefend_)
{
    attackerObject = toAttack_;
    defenderObject = toDefend_;
}

// setters
Monster BattleScreen::getAttacker() const
{
    return attackerObject;
}

Monster BattleScreen::getDefender() const
{
    return defenderObject;
}

// member functions
int BattleScreen::battleMenu()
{
    int userChoice_;
    cout << "[1] Attack\n";
    cout << "[2] Special Attack\n";
    cout << "[3] Defend\n";
    cout << "Select: ";
    cin >> userChoice_;

    return userChoice_;

}

void BattleScreen::dealAttack()
{
    defenderObject.setMonsterHP(defenderObject.getMonsterHP() - attackerObject.getMonsterAttack());

}

void BattleScreen::dealSpecialAttack()
{
    defenderObject.setMonsterHP(defenderObject.getMonsterHP() - attackerObject.getMonsterSpecialAttack());
}

void BattleScreen::dealDefense()
{
    attackerObject.setMonsterHP(attackerObject.getMonsterHP() + attackerObject.getMonsterDefense());
}

void BattleScreen::battleUI()
{
    cout << "_______________________________________________________________________________\n";
    cout << "\n                               Monster Name: " << defenderObject.getMonsterName() << "\n";
    cout << "                                   Monster HP: " << defenderObject.getMonsterHP() << "\n";
    cout << "Monster Name: " << attackerObject.getMonsterName() << "\n";
    cout << "  Monster HP: " << attackerObject.getMonsterHP() << "\n";
    cout << "_______________________________________________________________\n\n";
}

void dealDefense();
