#ifndef BATTLESCREEN_H_INCLUDED
#define BATTLESCREEN_H_INCLUDED

class BattleScreen
{
private:
    Monster toAttack;
    Monster toDefend;
public:
    BattleScreen(Monster toAttack_, Monster toDefend_);

    Monster getToAttack() const;
    Monster getToDefend() const;

    int battleMenu();
    void dealDamage();

    void battleUI();
};

#endif // BATTLESCREEN_H_INCLUDED
