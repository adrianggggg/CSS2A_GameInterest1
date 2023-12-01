#include <iostream>
#include <vector>
#include "Monster.hpp"
#include "Player.hpp"
#include "Battleground.hpp"
#include "Opponent.hpp"
#include "main.hpp"

using namespace std;

/* Battleground */

// constructors
Battleground::Battleground()
{

}

Battleground::Battleground(Player objectPlayer_, Opponent objectOpponent_)
{
    objectPlayerPtr = new Player(objectPlayer_);
    objectOpponentPtr = new Opponent(objectOpponent_);
}

Battleground::~Battleground()
{
    cout << "Yeet";
    delete objectPlayerPtr;
    delete objectOpponentPtr;
    delete objectPlayerMonsterPtr_;
    delete objectOpponentMonsterPtr_;
}
void Battleground::chooseMonsterToFight()
{
    objectPlayerPtr -> displayAllMonster();
    objectPlayerMonsterPtr_ = new Monster(objectPlayerPtr -> selectMonster(monsterSpecificSelection(*objectPlayerPtr)));
    objectOpponentMonsterPtr_ = new Monster(objectOpponentPtr -> Opponent::selectMonster());
}

void Battleground::battleInterface()
{
    cout << "***************************************************************" << endl;

    cout << "                                Monster: " << objectOpponentMonsterPtr_ -> getName() << endl;
    cout << "                                Type: " << objectOpponentMonsterPtr_ -> getType() << endl;
    cout << "                                HP: " << objectOpponentMonsterPtr_ -> getHP() << endl;

    cout << "Monster: " << objectPlayerMonsterPtr_ -> getName() << endl;
    cout << "Type: " << objectPlayerMonsterPtr_ -> getType() << endl;
    cout << "HP: " << objectPlayerMonsterPtr_ -> getHP() << endl;
    cout << "[1] Attack: " << objectPlayerMonsterPtr_ -> getAttack() << endl;
    cout << "[2] Special Attack: " << objectPlayerMonsterPtr_ -> getSpecialAttack() << endl;
    cout << "[3] Defend: " << objectPlayerMonsterPtr_ -> getDefend() << endl;
    cout << "************************************************" << endl;
}

void Battleground::battleLoop()
{
    bool userGate = 0;
    while(userGate == 0)
    {
        battleInterface();
        switch(battleSelection())
        {
        case 1:
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() - objectPlayerMonsterPtr_ -> getAttack());
            cout << objectPlayerPtr -> getName() << "'s" << objectPlayerMonsterPtr_-> getName() << " ATTACKS!" << endl;
            userGate = battleCheck();
            break;
        case 2:
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() - objectPlayerMonsterPtr_ -> getSpecialAttack());
            cout << objectPlayerPtr -> getName() << "'s" << " uses their SPECIAL ATTACK!" << endl;
            userGate = battleCheck();
            break;
        case 3:
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() + objectPlayerMonsterPtr_ -> getDefend());
            cout << objectPlayerPtr -> getName() << "'s" " REINFORCES their health!" << endl;
            userGate = battleCheck();
            break;
        default:
            cout << "Not possible!" << endl;
            break;
        }

        if(userGate == 1)
        {
            break;
        }

        battleInterface();

        switch(objectOpponentPtr -> randomChoice())
        {
        case 1:
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() - objectOpponentMonsterPtr_ -> getAttack());
            cout << objectOpponentPtr -> getName() << "'s " << objectOpponentMonsterPtr_-> getName() << " ATTACKS!" << endl;
            userGate = battleCheck();
            break;
        case 2:
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() - objectOpponentMonsterPtr_ -> getSpecialAttack());
            cout << objectOpponentPtr -> getName() << "'s" << " uses their SPECIAL ATTACK!" << endl;
            userGate = battleCheck();
            break;
        case 3:
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() + objectOpponentMonsterPtr_ -> getDefend());
            cout << objectOpponentPtr -> getName() << "'s" " REINFORCES their health!" << endl;
            userGate = battleCheck();
            break;
        default:
            cout << "Not possible!" << endl;
            break;
        }

    }
}

bool Battleground::battleCheck()
{
    if(objectPlayerMonsterPtr_ -> getHP() <= 0)
    {
        cout << "Oh, no " << objectPlayerPtr -> getName() << " is down!" << endl;
        objectPlayerPtr -> removeMonster(*objectPlayerMonsterPtr_);
        return 1;
    }
    else if(objectOpponentMonsterPtr_ -> getHP() <= 0)
    {
        cout << "Oh, no " << objectOpponentPtr -> getName() << "'s "<< objectOpponentMonsterPtr_ -> getName() <<" is down!" << endl;
        objectOpponentPtr -> removeMonster(*objectOpponentMonsterPtr_);
        return 1;
    }
    else
    {
        return 0;
    }
}

