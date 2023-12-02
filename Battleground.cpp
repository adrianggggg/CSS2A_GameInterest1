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
    delete objectPlayerPtr;
    delete objectOpponentPtr;
    delete objectPlayerMonsterPtr_;
    delete objectOpponentMonsterPtr_;
}
void Battleground::choosePlayerMonsterToFight()
{
    objectPlayerPtr -> displayAllMonster();
    objectPlayerMonsterPtr_ = new Monster(objectPlayerPtr -> selectMonster(monsterSpecificSelection(*objectPlayerPtr)));

    cout << objectPlayerPtr -> getName() << " chooses " << objectPlayerMonsterPtr_ -> getName() << "!" << endl << endl;
}
void Battleground::chooseOpponentMonsterToFight()
{
    objectOpponentMonsterPtr_ = new Monster(objectOpponentPtr -> Opponent::selectMonster());

    cout << objectOpponentPtr -> getName() << " chooses " << objectOpponentMonsterPtr_ -> getName() << "!" << endl << endl;
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
    cout << "************************************************" << endl << endl;
}

void Battleground::battleLoop()
{
    while(objectPlayerPtr -> getSize() > 0 && objectOpponentPtr -> getSize() > 0)
    {
        battleInterface();
        switch(battleSelection())
        {
        case 1:
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() - objectPlayerMonsterPtr_ -> getAttack());
            cout << objectPlayerPtr -> getName() << "'s " << objectPlayerMonsterPtr_-> getName() << " ATTACKS!" << endl << endl;
            battleCheck();
            break;
        case 2:
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() - objectPlayerMonsterPtr_ -> getSpecialAttack());
            cout << objectPlayerPtr -> getName() << "'s" << " uses their SPECIAL ATTACK!" << endl << endl;
            battleCheck();
            break;
        case 3:
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() + objectPlayerMonsterPtr_ -> getDefend());
            cout << objectPlayerPtr -> getName() << "'s" " REINFORCES their health!" << endl << endl;
            battleCheck();
            break;
        default:
            cout << "Not possible!" << endl;
            break;
        }

        if(objectPlayerPtr -> getSize() == 0 || objectOpponentPtr -> getSize() == 0)
        {
            break;
        }

        //battleInterface();

        switch(objectOpponentPtr -> randomChoice())
        {
        case 1:
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() - objectOpponentMonsterPtr_ -> getAttack());
            cout << objectOpponentPtr -> getName() << "'s " << objectOpponentMonsterPtr_-> getName() << " ATTACKS!" << endl << endl;
            battleCheck();
            break;
        case 2:
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() - objectOpponentMonsterPtr_ -> getSpecialAttack());
            cout << objectOpponentPtr -> getName() << "'s" << " uses their SPECIAL ATTACK!" << endl << endl;
            battleCheck();
            break;
        case 3:
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() + objectOpponentMonsterPtr_ -> getDefend());
            cout << objectOpponentPtr -> getName() << "'s" " REINFORCES their health!" << endl << endl;
            battleCheck();
            break;
        default:
            cout << "Not possible!" << endl << endl;
            break;
        }
    }
}

void Battleground::battleCheck()
{
    if(objectPlayerMonsterPtr_ -> getHP() <= 0)
    {
        cout << "Oh! " << objectPlayerPtr -> getName() << "'s "<< objectPlayerMonsterPtr_ -> getName() << " is down!" << endl << endl;

        objectPlayerPtr -> removeMonster(*objectPlayerMonsterPtr_);

        if(objectPlayerPtr -> getSize() > 0)
        {
            choosePlayerMonsterToFight();
        }
    }
    else if(objectOpponentMonsterPtr_ -> getHP() <= 0)
    {
        cout << "Oh! " << objectOpponentPtr -> getName() << "'s "<< objectOpponentMonsterPtr_ -> getName() <<" is down!" << endl << endl;

        objectOpponentPtr -> removeMonster(*objectOpponentMonsterPtr_);

        if(objectOpponentPtr -> getSize() > 0)
        {
            chooseOpponentMonsterToFight();
        }
    }
}

bool Battleground::battleResult()
{
    if(objectPlayerPtr -> getSize() > 0 )
    {
        cout << "Victory against " << objectOpponentPtr -> getName() << endl << endl;
        return true;
    }
    else
    {
        cout << "Defeat by the hands " << objectOpponentPtr -> getName() << endl << endl;
        return false;
    }
}

