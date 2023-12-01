/* Opponent */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Monster.hpp"
#include "Player.hpp"
#include "Opponent.hpp"


using namespace std;

// cosntructor
Opponent::Opponent() : Player()
{

}

// member functions
Monster Opponent::selectMonster()
{
    srand(time(0));
    cout << monsterInventory[rand()%3];
    return monsterInventory[rand()%3];
}

int Opponent::randomChoice()
{
    srand(time(0));
    return rand() % 3 + 1;
}
