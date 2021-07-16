//
// Created by Muhammad Masum Miah on 10/12/2020.
//

#ifndef IN2029COURSEWORK_ROBOT_H
#define IN2029COURSEWORK_ROBOT_H
#include "map.h"
#include <list>
#include <vector>
#include <string>
#include <ostream>
//robot class.
class robot {
    int id , team, steps;
    map _map;
    char direction;
public:
    robot(int id, int team, const map &m);
    const int getId() const {
        return id;
    }
    const int getTeam() const {
        return team;
    }
    const int getSteps() const {
        return steps;
    }
    void setDirection(char d) {
        robot::direction = d;
    }
    const map &getMap() const {
        return _map;
    }
    void turnLeft();
    void turnRight();
    void move(std::list<robot> &r);

//    ~robot(){} // destructor
};
bool ascending(const robot &x, const robot &y);
void show(std::ostream &out, std::list<robot> &robots);
std::list<robot>::iterator findRobot( std::list<robot> &r, int robotId);
bool moreSteps(const robot &x, const robot &y);
void travelled(std::ostream &out, std::list<robot> &robots);
void within(std::ostream &out,std::list<robot> &r, int n);
bool space(char c);
std::vector<std::string> split_words(const std::string &s);

#endif //IN2029COURSEWORK_ROBOT_H
