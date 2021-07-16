//
// Created by Muhammad Masum Miah on 11/12/2020.
//

#ifndef IN2029COURSEWORK_MAP_H
#define IN2029COURSEWORK_MAP_H

// class holds the coordinates for the robots.
class map {
    int x,y;
public:
    map(int x, int y) : x(x), y(y) {}
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    void setX(int x) {
        map::x = x;
    }
    void setY(int y) {
       map::y = y;
    }
//    ~map(){}// destructor
};


#endif //IN2029COURSEWORK_MAP_H
