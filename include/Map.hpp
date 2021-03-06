#ifndef __MAP_HPP__
#define	__MAP_HPP__

#include "AObject.hpp"
#include "MapElement.hpp"
#include "Bomberman.h"

class Map {
private:
    std::list<AObject*> *objects_;
    char *name_;
    eMapTheme theme_;
    int nbPlayer_;
    int nbIA_;
    int posX_;
    int posZ_;
    int minX_;
    int maxX_;


public:
    Map(int size, int nbPlayer, int nbIA, std::list<AObject*> *);
    Map(char *name, eMapTheme, int nbPlayer, int nbIA, std::list<AObject*> *);
    Map(const Map &);
    virtual ~Map();

    int getMinX(void) const;
    int getMaxX(void) const;

    void posMap(void);
    void openMap(void);
    void randMap(int);
};

#endif

