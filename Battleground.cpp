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
    // "Water vs. Fire:" indicates to the player that monster types is accounted for and matters
    cout << objectMonsterAttack_ -> getType() << " vs. " << objectMonsterDefend_ -> getType() << ":" << endl;

    // Calculate `critical hit` damage to add later
    int critDamage = 0;
    if(battleCriticalHit()) 
    {
        cout << " Critical hit!" << endl << endl;
        critDamage = objectMonsterAttack_ -> getAttack() * 0.35; // (* 0.35) is 35% base damage
    } 

    // Really effective +10% damage
    if
    (
        (objectMonsterAttack_ -> getType() == "Water" && objectMonsterDefend_ -> getType() == "Fire") ||
        (objectMonsterAttack_ -> getType() == "Fire" && objectMonsterDefend_ -> getType() == "Wind") ||
        (objectMonsterAttack_ -> getType() == "Wind" && objectMonsterDefend_ -> getType() == "Water")
    )
    {
        cout << " Really effective!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() * 1.10 + critDamage);
    }

    // Same type -70% damage
    else if
    (
        (objectMonsterAttack_ -> getType() == "Water" && objectMonsterDefend_ -> getType() == "Water") ||
        (objectMonsterAttack_ -> getType() == "Fire" && objectMonsterDefend_ -> getType() == "Fire") ||
        (objectMonsterAttack_ -> getType() == "Wind" && objectMonsterDefend_ -> getType() == "Wind")
    )
    {
        cout << " Same type!" << endl << endl;
        return (objectMonsterAttack_ -> getAttack() * 0.30 + critDamage);
    }

    // Not effective -60% damage
    else if
    (
        (objectMonsterAttack_ -> getType() == "Water" && objectMonsterDefend_ -> getType() == "Wind") ||
        (objectMonsterAttack_ -> getType() == "Fire" && objectMonsterDefend_ -> getType() == "Water") ||
        (objectMonsterAttack_ -> getType() == "Wind" && objectMonsterDefend_ -> getType() == "Fire")
    )
    {
        cout << " Not effective..." << endl << endl;
        return (objectMonsterAttack_ -> getAttack() * 0.40 + critDamage);
    }

    // error code
    else
    {
        cout << "DEBUG: Error with Battleground::getBattleAttack()" << endl;
        return 1;
    }
}

double Battleground::getBattleSpecialAttack(Monster* objectMonsterAttack_, Monster* objectMonsterDefend_)
{
    if(battleCriticalHit() == true)
    {
        cout << " Critical hit!" << endl << endl;
        //return (objectMonsterAttack_ -> getSpecialAttack())*1.3 + objectMonsterAttack_ -> getSpecialAttack(); // this is 230% damage. Was +30% the intent?
        return (objectMonsterAttack_ -> getSpecialAttack() * 1.35); // this is +35% damage matching damage above. we should abstract crit into a function maybe?
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
    cout << "***************************************************************" << endl << endl;
}

void Battleground::battleLoop()
{
    while(objectPlayerPtr -> getSize() > 0 && objectOpponentPtr -> getSize() > 0)
    {
        battleInterface();
        switch(battleSelection()) // battleSelection() defined in main, could it be moved battleground class for simplicity?
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
        // !check main branch I think this was updated!
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
    // is there any case where BOTH hp will be 0 on the same turn? If so you can fix this by removing the else. 
    // For now I don't see any issues unless we add delayed damage like poison/ranged attack or something.
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

/*
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
*/

bool Battleground::battleCriticalHit()
{
    srand(time(0));
    int critChance = rand() % 100 + 1;  // from 1 to 100.
    if(critChance <= 10) {return true;} // (<= 10) is 10%, (<= 20) is 20%
    else {return false;}
}
