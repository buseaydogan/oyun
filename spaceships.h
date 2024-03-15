#ifndef COSMIC_VOYAGER_CAPTAIN_H
#define COSMIC_VOYAGER_CAPTAIN_H
#include "Spaceships.h"

class Spaceships {
public:
    explicit Spaceships(double _damageCoef) : damageCoef{_damageCoef} {}

    virtual int updateHealthDamage10(int& _health)=0;
    virtual int updateHealthDamage30(int&  _health)=0;

    int earnMoney(int _money);
    int loseMoney(int _money);
    int updateFuel(int& _fuel);

    virtual void asteroid()=0;
    void abandonedPlanet();
    void pirates();

    virtual void run()=0;
    virtual void fight()=0;

    void debate();

    void displayStatus() const;

    void puan_hesabi();
    int fuel{100};

protected:
    //ATTRIBUTIONS
    int money{0};
    int health{100};
    double damageCoef{0};////

    //CONSTANTS
    const int prize{10};
    const int spentFuel{33};
    const int damage{10};
    const int damage_{30};
};


#endif //COSMIC_VOYAGER_CAPTAIN_H