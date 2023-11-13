#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
#include "Enemy.h"
#include "BattleScreen.h"

/* Enemy */
// constructors
Enemy::Enemy()
{
    enemyName = "NA";
    monsterOfInterest = 0;
}

Enemy::Enemy(std::string name_)
{
    enemyName = name_;
    monsterOfInterest = 0;
}


// getters
std::string Enemy::getEnemyName() const
{
    return enemyName;
}

Monster Enemy::getMonsterInventory()
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

int Enemy::getMonsterofInterest() const
{
    return monsterOfInterest;
}

// setters
void Enemy::setEnemyName(std::string name_)
{
    enemyName = name_;
}

void Enemy::setMonsterInventory(Monster object_)
{
    monsterInventory.push_back(object_);
}

void Enemy::setMonster(Monster object_)
{
    monsterInventory[monsterOfInterest] = object_;
}
