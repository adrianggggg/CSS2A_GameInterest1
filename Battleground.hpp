#ifndef BATTLEGROUND_HPP_INCLUDED
#define BATTLEGROUND_HPP_INCLUDED

#include "Opponent.hpp"

class Battleground
{
private:
    Player* objectPlayerPtr;
    Opponent* objectOpponentPtr;

    Monster* objectPlayerMonsterPtr_;   // player's monster "on deck"
    Monster* objectOpponentMonsterPtr_;     // opponent's monster "on deck"
public:
    // constructors
    Battleground();
    Battleground(Player objectPlayer_, Opponent objectOpponent_);
    ~Battleground();

    // member functions
    double getBattleAttack(Monster* objectMonsterAttack_, Monster* objectMonsterDefend_);
    double getBattleSpecialAttack(Monster* objectMonsterAttack_, Monster* objectMonsterDefend_);

    void choosePlayerMonsterToFight();
    void chooseOpponentMonsterToFight();

    void battleLoop();
    void battleInterface();
    void battleCheck();
    bool battleResult();
    void battleInventory(int sizeMonster);

    bool battleCriticalHit();


};

#endif // BATTLEGROUND_HPP_INCLUDED
