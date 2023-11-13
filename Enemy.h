#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

class Enemy
{
private:
    std::string enemyName;
    std::vector<Monster> monsterInventory;
    int monsterOfInterest;
    
public:
    Enemy();
    Enemy(std::string name_);

    int getMonsterofInterest() const;
    std::string getEnemyName() const;
    Monster getMonsterInventory();

    void setEnemyName(std::string name_);
    void setMonsterInventory(Monster object_);
    void setMonster(Monster object_);

};

#endif // ENEMY_H_INCLUDED
