#ifndef __BOMB_HPP__
#define __BOMB_HPP__

#include "AObject.hpp"
#include "Player.hpp"
#include "Flamme.hpp"

#define TIMER_BOMB 4

class Bombe : public AObject {
public:
    Bombe(float const, float const, int const, std::list<AObject*> *);
    ~Bombe();
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
    bool stateOfBomb();
    void explose();

private:
    gdl::Model model_;
    gdl::Clock timer_;
    std::list<AObject*> *objects_;
    int power_;
};

#endif
