#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

class Monster
{
private:
    std::string monsterName;
    std::string monsterType;
    double monsterAttack;
    double monsterAttackSpecial;
    double monsterDefense;
    double monsterHP;
public:
    Monster();
    Monster(std::string name_, std::string type_, int attack_, int special_attack_, double defense_);

    std::string getMonsterName() const;
    double getMonsterAttack() const;
    double getMonsterSpecialAttack() const;
    double getMonsterDefense() const;
    double getMonsterHP() const;
    std::string getMonsterType() const;


    void setMonsterHP(double hp_);
    void setMonsterType(std::string type_);
    void setMonsterAttack(double attack_);
    void setMonsterSpecialAttack(double special_attack_);
    void setMonsterDefense(double defense_);


};

#endif // MONSTER_H_INCLUDED
