#ifndef __BONUS_HPP__
#define	__BONUS_HPP__

#include "AObject.hpp"
#include "Camera.hpp"


#define BONUS_SIZE (BLOCK_SIZE - 100)
#define TIMER_BONUS 15

enum eBonusType {
    AMMO = 1,
    SPEED,
    POWER,
    MPOWER
};

class Player;

class Bonus : public AObject {
private:
    std::list<AObject*> *objects_;
    gdl::Image texture_;
    gdl::Clock timer_;
    eBonusType bonusType_;
    int dirAnim_;
    Player *pl_;

public:
    Bonus(float const, float const, eBonusType const, std::list<AObject*> *);
    virtual ~Bonus();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    eBonusType getBonusType(void) const;
};

#endif	/* BONUS_HPP */

