#include <iostream>
#include <vector>

using namespace std;

class Monster
{
private:
    string monsterName;
    string monsterType;
    double monsterAttack;
    double monsterAttackSpecial;
    double monsterDefense;
    double monsterHP;
public:
    Monster();
    Monster(string name_);

    string getMonsterName() const;

    void setMonsterHP(double hp_);
    void setMonsterType(double type_);
    void setMonsterAttack(double attack_);
    void setMonsterSpecialAttack(double special_attack_);
    void setMonsterDefense(double defense_);
};

class Player
{
private:
    string playerName;
    vector<Monster> monsterInventory;
public:
    Player();
    Player(string name_);

    string getPlayerName() const;
    vector<Monster> getMonsterInventory() const;

    void setPlayerName(string name_);
    void setMonsterInventory(Monster object_);

};

void titleScreen();
string nameSelection();
void monsterSelection();

int main()
{
    Monster* ptrMonster = new Monster("Rat");
    Monster* ptrMonster;
    titleScreen();
    Player player1(nameSelection());



    cout << player1.getPlayerName();
    cout << ptrMonster -> getMonsterName();
    return 0;
}

/* Player */
// constructors
Player::Player()
{
    playerName = "NA";
}

Player::Player(string name_)
{
    playerName = name_;
}

// getters
string Player::getPlayerName() const
{
    return playerName;
}

vector<Monster> Player::getMonsterInventory() const
{
    return monsterInventory;
}

// setters
void Player::setPlayerName(string name_)
{
    playerName = name_;
}

void Player::setMonsterInventory(Monster object_)
{
    monsterInventory.push_back(object_);
}

/* Monster */
//constructors
Monster::Monster()
{
    monsterName = "NA";
    monsterType = "NA";
    monsterHP = 0;
    monsterAttack = 0;
    monsterAttackSpecial = 0;
    monsterDefense = 0;
}
Monster::Monster(string name_)
{
    monsterName = name_;
    monsterType = "NA";
    monsterHP = 0;
    monsterAttack = 0;
    monsterAttackSpecial = 0;
    monsterDefense = 0;
}

// getters
string Monster::getMonsterName() const
{
    return monsterName;
}

// setters
void Monster::setMonsterType(double type_)
{
    monsterType = type_;
}

void Monster::setMonsterAttack(double attack_)
{
    monsterAttack = attack_;
}

void Monster::setMonsterSpecialAttack(double special_attack_)
{
    monsterAttackSpecial = special_attack_;
}

void Monster::setMonsterDefense(double defense_)
{
    monsterDefense = defense_
}

void Monster::setMonsterHP(double hp_)
{
    monsterHP = hp_;
}

/* functions */
void titleScreen()
{
    cout << "MONSTERS" << endl;
}

string nameSelection()
{
    string userName;

    cout << "Enter your character's name: ";
    cin >> userName;

    return userName;
}

void monsterSelection()
{
    switch(userChoice_)
    {
    case(1):
    case(2):
    case(3):
    case(4):
    }
}

void monsterList()
{
    cout << "1. Monster Name: Rat\n";
    cout <<
}
