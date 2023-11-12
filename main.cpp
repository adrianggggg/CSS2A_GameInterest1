#include <iostream>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "BattleScreen.h"

using namespace std;

void titleScreen();
string nameSelection();
void monsterSelection(Player& object_);
void monsterList();
void battleEncounter(Player& object1_, Monster& object2_);

int main()
{
    titleScreen();

    Player player1(nameSelection());

    monsterSelection(player1);

    cout << endl;

    Monster trial2("Amogus", "Fire", 12, 24, 12);

    battleEncounter(player1, trial2);

    cout << trial2.getMonsterHP();

    return 0;
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

        cout << "Enter choice "<< i + 1 <<": ";
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

void battleEncounter(Player& object1_, Monster& object2_)
{
    cout << "Encounter!\n";
    Monster trial1 = object1_.getMonsterInventory();

    BattleScreen battleObject(trial1, object2_);

    while(trial1.getMonsterHP() > 0 && object2_.getMonsterHP() > 0)
    {
        battleObject.battleUI();
        switch(battleObject.battleMenu())
        {
        case(1):
            battleObject.dealDamage();
            trial1 = battleObject.getToAttack();
            object1_.setMonster(battleObject.getToAttack());
            object2_ = battleObject.getToDefend();
            break;
        case(2):
            break;
        case(3):
            break;
        default:
            battleObject.battleUI();
            break;
        }
    }
}
