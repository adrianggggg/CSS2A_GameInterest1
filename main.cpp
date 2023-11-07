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
    Monster(string name_, string type_, int attack_, int special_attack_, double defense_);

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
void monsterSelection(Player& object_);
void monsterList();

int main()
{
    titleScreen();

    Player player1(nameSelection());

    monsterSelection(player1);

    cout << player1.getPlayerName() << endl;

    vector<Monster> objectTrial;

    objectTrial = player1.getMonsterInventory();

    for(int i = 0; i < 3; i++)
    {
        cout << objectTrial[i].getMonsterName();
    }

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

Monster::Monster(string name_, string type_, int attack_, int special_attack_, double defense_)
{
    monsterName = name_;
    monsterType = type_;
    monsterAttack = attack_;
    monsterAttackSpecial = special_attack_;
    monsterDefense = defense_;
    monsterHP = 100;
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
    monsterDefense = defense_;
}

void Monster::setMonsterHP(double hp_)
{
    monsterHP = hp_;
}

/* functions */
void titleScreen()
{
    cout << "**********\n";
    cout << "*MONSTERS*\n";
    cout << "**********\n\n";
}

string nameSelection()
{
    string userName;

    cout << "Enter your character's name: ";
    cin >> userName;

    cout << "\n";

    return userName;
}

void monsterSelection(Player& object_)
{
    monsterList();

    for(int i = 0; i < 3; i++)
    {
        int* ptrChoice1_ = new int();

        cout << "[" << i + 1 << "] Enter your choice: ";
        cin >> *ptrChoice1_;

        switch(*ptrChoice1_)
        {
        case(1):
            {
                delete ptrChoice1_;

                Monster* ptrChoice2_ = new Monster("Fish", "Earth", 20, 35, 20);

                object_.setMonsterInventory(*ptrChoice2_);

                delete ptrChoice2_;

                break;
            }
        case(2):
            {
                delete ptrChoice1_;

                Monster* ptrChoice2_ = new Monster("Worm", "Earth", 15, 45, 35);

                object_.setMonsterInventory(*ptrChoice2_);

                delete ptrChoice2_;

                break;
            }
        case(3):
            {
                delete ptrChoice1_;

                Monster* ptrChoice2_ = new Monster("Bird", "Fire", 30, 35, 10);

                object_.setMonsterInventory(*ptrChoice2_);

                delete ptrChoice2_;
        break;
            }
        default:
            break;
        }
    }

}

void monsterList()
{
    cout << "1. Monster Name: Fish\n";
    cout << "           Type: Earth\n";
    cout << "         Attack: 20\n";
    cout << " Special Attack: 35\n";
    cout << "        Defense: 20\n\n";

    cout << "2. Monster Name: Worm\n";
    cout << "           Type: Earth\n";
    cout << "         Attack: 15\n";
    cout << " Special Attack: 45\n";
    cout << "        Defense: 35\n\n";

    cout << "3. Monster Name: Bird\n";
    cout << "           Type: Fire\n";
    cout << "         Attack: 30\n";
    cout << " Special Attack: 35\n";
    cout << "        Defense: 10\n\n";
}
