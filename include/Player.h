#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AObject.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"
#include "MyClock.hpp"

class Player : public AObject {
protected:
    std::list<AObject*> *objects_;
    gdl::Model model_;
    int ammo_;
    int ammoStock_;
    int power_;
    int speed_;


    sf::Music	*powerup;
    sf::Music	*death;

public:
    Player(float const, float const, std::list<AObject*> *);
    virtual ~Player(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    bool checkMove(gdl::Input &input, float, int);
    void move(gdl::Input &);
    void putBomb(gdl::Input &);
    bool getBonus(Bonus *);
    //    void isDead(gdl::Input &);

    int getAmmo() const;
    void isDead(gdl::Input &);

    int getPower() const;
    int getSpeed() const;

    void recupBomb();
    bool ammoUp();
    bool powerUp();
    bool speedUp();
};

#endif