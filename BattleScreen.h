#ifndef BATTLESCREEN_H_INCLUDED
#define BATTLESCREEN_H_INCLUDED

class BattleScreen
{
private:
    Monster attackerObject;
    Monster defenderObject;
public:
    BattleScreen(Monster toAttack_, Monster toDefend_);

    Monster getAttacker() const;
    Monster getDefender() const;

    int battleMenu();
    void dealAttack();
    void dealSpecialAttack();
    void dealDefense();

    void battleUI();
};

#endif // BATTLESCREEN_H_INCLUDED
