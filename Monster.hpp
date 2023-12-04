#ifndef MONSTER_HPP_INCLUDED
#define MONSTER_HPP_INCLUDED

class Monster
{
private:
    std::string name;
    std::string type;
    double attack;
    double special_attack;
    double defend;
    double health;
    double MAX_HEALTH; // cant use const in a constructor I guess but we should pretend it is

public:
    Monster();
    Monster(std::string name_, std::string type_, double attack_, double special_attack_, double defend);

    std::string getName() const;
    std::string getType() const;
    double getAttack() const;
    double getSpecialAttack() const;
    double getDefend() const;
    double getHealth() const;
    double getMAX_HEALTH() const;

    void setName(std::string name_);
    void setType(std::string type_);
    void setAttack(double attack_);
    void setSpecialAttack(double special_attack_);
    void setDefend(double defend_);
    void setHealth(double health_);

    bool operator ==(const Monster& objectMonster_);

    friend std::ostream& operator <<(std::ostream& out, const Monster& objectMonster_);
};

#endif // MONSTER_HPP_INCLUDED
