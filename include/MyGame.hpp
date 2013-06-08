#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include "AObject.hpp"
#include "Camera.hpp"
#include "Map.hpp"
#include "MapElement.hpp"
#include "Display.hpp"

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    gdl::Clock timer_;
    sf::Music *bombSound_;
    sf::Music *deathSound_;
    sf::Music *powerupSound_;
    Camera camera_;
    float cameraY_;
    int idPlayerW_;


public:
    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void checkWin(void);
};

#endif
