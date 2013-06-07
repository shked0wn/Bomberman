#include "Map.hpp"

Map::Map(int size, std::list<AObject*> *objects) {
    this->objects_ = objects;
    this->posX_ = 0;
    this->posZ_ = 0;
    this->maxX_ = 0;
    this->randMap(size);
}

Map::Map(const char *name, eMapTheme theme, std::list<AObject*> *objects) {
    this->objects_ = objects;
    this->name_ = name;
    this->theme_ = theme;
    this->posX_ = 0;
    this->posZ_ = 0;
    this->maxX_ = 0;
    this->openMap();
}

Map::Map(const Map &old) {
    this->objects_ = old.objects_;
    this->name_ = old.name_;
    this->posX_ = old.posX_;
    this->posZ_ = old.posZ_;
    this->maxX_ = old.maxX_;
}

Map::~Map() {
}

int Map::getMaxX(void) const {
    return this->maxX_;
}

void Map::posMap(void) {
    std::ifstream file(name_, std::ios::in);
    std::string str;
    int x = 0;
    int z = 0;
    while (getline(file, str)) {
        std::string::iterator it = str.begin();
        while (it != str.end()) {
            it++;
            x++;
        }
        posX_ = x;
        x = 0;
        z++;
    }
    posX_ = (posX_ - posX_ - posX_) / 2;
    posZ_ = (z - z - z) / 2;
    maxX_ = posX_;
    file.close();
}

void Map::openMap(void) {
    std::ifstream file(name_, std::ios::in);
    std::string str;
    int id = 2;

    this->posMap();
    this->objects_->push_back(new MapElement::Background(0, 0, this->theme_, this->objects_));
    while (getline(file, str)) {
        std::string::iterator it = str.begin();
        while (it != str.end()) {
            if (*it == '1') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->theme_, this->objects_));
            } else if (*it == '2') {
                this->objects_->push_back(new MapElement::Wall(posX_, posZ_, this->theme_, this->objects_));
            } else if (*it == '3') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->theme_, this->objects_));
                this->objects_->push_back(new MapElement::Crate(posX_, posZ_, this->theme_, this->objects_));
            } else if (*it == '7' && id < 3) {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->theme_, this->objects_));
                this->objects_->push_back(new Bomberman(posX_, posZ_, id--, this->objects_));
            } else if (*it == '8') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->theme_, this->objects_));
                this->objects_->push_back(new Bomberman(posX_, posZ_, 3, this->objects_));
            }
            it++;
            posX_++;
        }
        posX_ = maxX_;
        posZ_++;
    }
    file.close();
}

void Map::randMap(int size) {
    int x = (size - size - size) / 2;
    int z = (size - size - size) / 2;
    this->maxX_ = z;
    int value;

    //this->objects_->push_back(new MapElement::Background(0, 0, this->theme_, this->objects_));
    while (x != size + 1) {
        z = maxX_;
        while (z != size + 1) {
            if ((z == (size - size - size) / 2 || x == (size - size - size) / 2 || x == size || z == size) ||
                    ((z % 2) == 0 && (x % 2) == 0))
                this->objects_->push_back(new MapElement::Wall(x, z, this->theme_, this->objects_));
            else {
                value = rand() % 2;
                    this->objects_->push_back(new MapElement::Ground(x, z, this->theme_, this->objects_));
                    if (value == 1)
                        this->objects_->push_back(new MapElement::Crate(x, z, this->theme_, this->objects_));
            }
            z++;
        }
        x++;
    }
}

