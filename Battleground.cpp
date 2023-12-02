#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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

// getters/modifiers
double Battleground::getBattleAttack(Monster* objectMonsterAttack_, Monster* objectMonsterDefend_)
{
    if(objectMonsterAttack_ -> getType() == objectMonsterDefend_ -> getType())
    {
        cout << " Not very effective!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() - (objectMonsterAttack_ -> getAttack()* 0.70));
    }

    else if(objectMonsterAttack_ -> getType() == "Water" && objectMonsterDefend_ -> getType() == "Fire")
    {
        cout << " Really effective!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() + (objectMonsterAttack_ -> getAttack()* 0.10));
    }
    else if(objectMonsterAttack_ -> getType() == "Fire" && objectMonsterDefend_ -> getType() == "Water")
    {
        cout << " Not very effective!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() - (objectMonsterAttack_ -> getAttack()* 0.60));
    }

    else if(objectMonsterAttack_ -> getType() == "Fire" && objectMonsterDefend_ -> getType() == "Wind")
    {
        cout << " Really effective!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() + (objectMonsterAttack_ -> getAttack()* 0.10));
    }
    else if(objectMonsterAttack_ -> getType() == "Wind" && objectMonsterDefend_ -> getType() == "Fire")
    {
        cout << " Really effective!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() - (objectMonsterAttack_ -> getAttack()* 0.60));
    }

    else
    {
        if(battleCriticalHit() == true)
        {
            cout << " Critical Hit!" << endl << endl;
            return objectMonsterAttack_ -> getAttack() + (objectMonsterAttack_ -> getAttack())*1.35;
        }
        else
        {
            cout << endl << endl;
            return objectMonsterAttack_ -> getAttack();
        }
    }
}

double Battleground::getBattleSpecialAttack(Monster* objectMonsterAttack_, Monster* objectMonsterDefend_)
{
    if(battleCriticalHit() == true)
    {
        cout << " Critical hit!" << endl << endl;
        return (objectMonsterAttack_ -> getSpecialAttack())*1.3 + objectMonsterAttack_ -> getSpecialAttack();
    }
    else
    {
        cout << endl << endl;
        return objectMonsterAttack_ -> getSpecialAttack();
    }
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
    cout << "                                "; battleInventory(objectOpponentPtr -> getSize()); cout << endl;
    cout << "                                Monster: " << objectOpponentMonsterPtr_ -> getName() << endl;
    cout << "                                Type: " << objectOpponentMonsterPtr_ -> getType() << endl;
    cout << "                                HP: " << objectOpponentMonsterPtr_ -> getHP() << endl;

    battleInventory(objectPlayerPtr -> getSize()); cout << endl;
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
            cout << objectPlayerPtr -> getName() << "'s " << objectPlayerMonsterPtr_-> getName() << " ATTACKS!";
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() - getBattleAttack(objectPlayerMonsterPtr_, objectOpponentMonsterPtr_));
            battleCheck();
            break;
        case 2:
            cout << objectPlayerPtr -> getName() << "'s " << objectPlayerMonsterPtr_-> getName() << " uses their SPECIAL ATTACK!";
            objectOpponentMonsterPtr_ -> setHP(objectOpponentMonsterPtr_ -> getHP() - getBattleSpecialAttack(objectPlayerMonsterPtr_, objectOpponentMonsterPtr_));
            battleCheck();
            break;
        case 3:
                        cout << objectPlayerPtr -> getName() << "'s" " REINFORCES their health!" << endl << endl;
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() + objectPlayerMonsterPtr_ -> getDefend());
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
            cout << objectOpponentPtr -> getName() << "'s " << objectOpponentMonsterPtr_-> getName() << " ATTACKS!";
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() - getBattleAttack(objectOpponentMonsterPtr_, objectPlayerMonsterPtr_));
            battleCheck();
            break;
        case 2:
            cout << objectOpponentPtr -> getName() << "'s " << objectOpponentMonsterPtr_-> getName() << " uses their SPECIAL ATTACK!";
            objectPlayerMonsterPtr_ -> setHP(objectPlayerMonsterPtr_ -> getHP() - getBattleSpecialAttack(objectOpponentMonsterPtr_, objectPlayerMonsterPtr_));
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
        cout << "Victory against " << objectOpponentPtr -> getName() << "!" << endl << endl;
        return true;
    }
    else
    {
        cout << "Defeat by the hands " << objectOpponentPtr -> getName() << "!" << endl << endl;
        return false;
    }
}

void Battleground::battleInventory(int sizeMonster)
{
    for(int i = 0; i < sizeMonster; i++)
    {
        cout << "o ";
    }
}

bool Battleground::battleCriticalHit()
{
    srand(time(0));

    bool critChance_[10];

    for(int i = 0; i < 10; i++)
    {
        critChance_[i] = rand() % 2;
    }

    return critChance_[rand() % 10];
}

