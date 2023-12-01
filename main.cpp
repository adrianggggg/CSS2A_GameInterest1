#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Monster.hpp"
#include "Player.hpp"
#include "Battleground.hpp"
#include "Opponent.hpp"
#include "main.hpp"

using namespace std;

void opponentRandomizer(Opponent objectOpponent_[]);

void titleScreen();
void nameSelection(Player& objectPlayer_);
void monsterSelection(Player& objectPlayer_);
int monsterSpecificSelection(Player& objectPlayer_);

void battleScreen();
int battleSelection();
void battleScreen();

int main()
{
    Opponent opponents[5];
    Player player1;

    opponentRandomizer(opponents);  // randomizes a group of 5 opponents along with 3 random monsters

    titleScreen();

    nameSelection(player1);
    monsterSelection(player1);

    Battleground battle1(player1, opponents[0]);
    battleScreen();
    battle1.chooseMonsterToFight();
    battle1.battleLoop();




    return 0;
}

// functions
void opponentRandomizer(Opponent objectOpponent_[])
{
    Monster arrayMonster[6] =
    {
        Monster("Cat", "Fire", 10, 20, 10),
        Monster("Mouse", "Fire", 10, 40, 10),
        Monster("Bird", "Earth", 15, 20, 10),
        Monster("Dog", "Earth", 30, 10, 10),
        Monster("Fish", "Water", 5, 20, 60),
        Monster("Worm", "Earth", 10, 30, 5)
    };

    string name[5] = { "Jerry", "Rick", "Morty", "Summer", "Beth" };

    srand(time(0));

    for(int i = 0; i < 5; i++)
    {
        objectOpponent_[i].setName(name[rand()% 6]);
        for(int j = 0; j < 3; j++)
        {
            objectOpponent_[i].addMonster(arrayMonster[rand() % 6]);
        }
    }
}

void titleScreen()
{
    cout << "MONSTERS" << endl;
}

void nameSelection(Player& objectPlayer_)
{
    string userName_;


    cout << "Enter your character's name: ";
    getline(cin, userName_);

    objectPlayer_.setName(userName_);
}

void monsterSelection(Player& objectPlayer_)
{
    int userChoice_;
    string numberLetter[3] = { "first", "second", "third" };

    Monster arrayMonster[6] =
    {
        Monster("Cat", "Fire", 10, 20, 10),
        Monster("Mouse", "Fire", 10, 40, 10),
        Monster("Bird", "Earth", 15, 20, 10),
        Monster("Dog", "Earth", 30, 10, 10),
        Monster("Fish", "Water", 5, 20, 60),
        Monster("Worm", "Earth", 10, 30, 5)
    };

    Monster* objectMonsterPtr_ = new Monster();

    for(int i = 0; i < 6; i++)
    {
        cout << "[" << i + 1 << "]" << endl;
        cout << arrayMonster[i] << endl;
    }

    int userGate_ = 0;
    while(userGate_ < 3)
    {
        cout << "Enter the # of your " << numberLetter[userGate_] << " monster: ";
        cin >> userChoice_;

        if(userChoice_ > 0 && userChoice_ <= 6)
        {
            *objectMonsterPtr_ = arrayMonster[userChoice_ - 1];
            objectPlayer_.addMonster(*objectMonsterPtr_);

            userGate_++;
        }
        else
        {
            cout << "Not possible!" << endl;
        }
    }

    delete objectMonsterPtr_;
}

int monsterSpecificSelection(Player& objectPlayer_)
{
    int userChoice_ = 0;

    while(1)
    {
        cout << "Enter the # of the monster: ";
        cin >> userChoice_;

        if(userChoice_ > 0 && userChoice_ <= objectPlayer_.getSize())
        {
            return userChoice_ - 1;
        }
        else
        {
            cout << "Not possible!" << endl;
        }
    }
}

void battleScreen()
{
    cout << "An opponent is approaching!" << endl;
}

int battleSelection()
{
    int userChoice_;
    cin >> userChoice_;

    return userChoice_;
}
