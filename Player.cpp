#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "BattleScreen.h"

/* Player */
// constructors
Player::Player()
{
    playerName = "NA";
    monsterOfInterest = 0;
}

Player::Player(std::string name_)
{
    playerName = name_;
    monsterOfInterest = 0;
}


// getters
std::string Player::getPlayerName() const
{
    return playerName;
}

Monster Player::getMonsterInventory()
{
    int userChoice_;

    for(int i = 0; i < 3; i++)
    {
        if(monsterInventory[i].getMonsterHP() > 0)
        {
            std::cout << "[" << i + 1 << "] Monster Name: " << monsterInventory[i].getMonsterName() << "\n";
        }
        else
        {
            std::cout << "Name: " << monsterInventory[i].getMonsterName() << " - OUT OF THE GAME\n";
        }
    }

    std::cout << "Monster selection: ";
    std::cin >> userChoice_;

    while(1)
    {
        if(monsterInventory[userChoice_ - 1].getMonsterHP() > 0)
        {
            monsterOfInterest = userChoice_ - 1;
            return monsterInventory[userChoice_ - 1];
        }
        else
        {
            std::cout << "Not an option!" << std::endl;
        }
    }
}

int Player::getMonsterofInterest() const
{
    return monsterOfInterest;
}

// setters
void Player::setPlayerName(std::string name_)
{
    playerName = name_;
}

void Player::setMonsterInventory(Monster object_)
{
    monsterInventory.push_back(object_);
}

void Player::setMonster(Monster object_)
{
    monsterInventory[monsterOfInterest] = object_;
}
