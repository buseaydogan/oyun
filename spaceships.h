#ifndef COSMIC_VOYAGER_CAPTAIN_H
#define COSMIC_VOYAGER_CAPTAIN_H
#include "spaceships.h"
#include <random>
#include <iostream>

class Spaceships {
public:
    explicit Spaceships(double _damageCoef) : damageCoef{_damageCoef} {}

    //UPDATES
    int GetDemage(int demage_);

    void earnMoney(int prize_);
    void loseMoney(void);
    void updateFuel(void);

    //EVENTS
    void asteroid(void);

    void abandonedPlanet(void);
    void pirates(void);

    //ACTIONS
    void run(void);

    void fight(void);
    void debate(void);

    void displayStatus(void) const;

    void puan_hesabi(void);
    int fuel{100};

protected:
    //ATTRIBUTIONS
    int money{0};
    int health{100};
    double damageCoef{0};////

    //CONSTANTS
    const int prize{10};
    const int spentFuel{1};
    const int damage{10};
    const int damage_{30};
};


#endif //COSMIC_VOYAGER_CAPTAIN_H