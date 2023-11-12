#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
private:
    std::string playerName;
    std::vector<Monster> monsterInventory;
    int monsterOfInterest;
public:
    Player();
    Player(std::string name_);

    int getMonsterofInterest() const;
    std::string getPlayerName() const;
    Monster getMonsterInventory();

    void setPlayerName(std::string name_);
    void setMonsterInventory(Monster object_);
    void setMonster(Monster object_);

};

#endif // PLAYER_H_INCLUDED
