//
// Created by Muhammad Masum Miah on 10/12/2020.
//
#include "robot.h"
#include <algorithm>
#include <iostream>
using namespace std;
robot::robot(int id, int team, const map &m) : id(id), team(team), _map(m),direction('n'), steps(0) {
}
//Turns the robots direction to the left.
void robot::turnLeft() {
    if(direction == 'n'){
        robot::setDirection('w');
    }
    else if(direction == 'w'){
        robot::setDirection('s');
    }
    else if(direction == 's'){
        robot::setDirection('e');
    }
    else {
        robot::setDirection('n');
    }
}
// Turns the robots direction to the right.
void robot::turnRight(){
    if(direction == 'n'){
        robot::setDirection('e');
    }
    else if(direction == 'e'){
        robot::setDirection('s');
    }
    else if(direction == 's'){
        robot::setDirection('w');
    }
    else {
        robot::setDirection('n');
    }
}
//will validate and move the robot.
void robot::move( list<robot> &r){
    auto p = r.cbegin();
    //this will check if the move is valid.
    bool flag = true;
    //if enemy is destroyed, then it will turn true and move will be valid.
    bool destroy =false;
    if(direction  == 'n') {
        while (p != r.cend() && flag && !destroy) {
            //Check if the coordinates are occupied. If occupied and in different teams, then destroy the robot.
            //Otherwise the move is invalid.
            if (p->getMap().getY() == _map.getY()+1 && p->getMap().getX() == _map.getX()) {
                if (p->getTeam() != team) {
                    p = r.erase(p);
                    destroy = true;
                }
                else {
                    //if the robots are on the same team.
                    //flag will change to false and no move will be recorded at the end.
                    flag = false;
                }
            }
            else {
                ++p;
            }
        }
        //If the coordinates are not occupied or enemy was destroyed, then increase the steps and change coordinates appropriately.
        if(flag || destroy) {
            _map.setY(_map.getY() + 1);
            ++steps;
        }
    }
    else if(direction == 'e'){
        while (p != r.cend() && flag && !destroy) {
            //Check if the coordinates are occupied. If occupied and in different teams, then destroy the robot.
            //Otherwise the move is invalid.
            if (p->getMap().getX() == _map.getX()+1 && p->getMap().getY() == _map.getY()) {
                if (p->getTeam() != team) {
                    p = r.erase(p);
                    destroy = true;
                }
                else {
                    //if the robots are on the same team.
                    //no change will occur
                    flag = false;
                }
            }
            else {
                ++p;
            }
        }
        //If the coordinates are not occupied or enemy was destroyed, then increase the steps and change coordinates appropriately.
        if(flag || destroy) {
            _map.setX(_map.getX() + 1);
            ++steps;
        }
    }
    else if(direction ==  's'){
        while (p != r.cend() && flag && !destroy) {
            //Check if the coordinates are occupied. If occupied and in different teams, then destroy the robot.
            //Otherwise the move is invalid.
            if (p->getMap().getY() == _map.getY()-1 && p->getMap().getX() == _map.getX()) {
                if (p->getTeam() != team) {
                    p = r.erase(p);
                    destroy = true;
                }
                else {
                    //if the robots are on the same team.
                    //no change will occur
                    flag = false;
                }
            }
            else {
                ++p;
            }
        }
        //If the coordinates are not occupied or enemy was destroyed, then increase the steps and change coordinates appropriately.
        if(flag || destroy) {
            _map.setY(_map.getY() - 1);
            ++steps;
        }
    }
    else{
        while (p != r.cend() && flag && !destroy) {
            //Check if the coordinates are occupied. If occupied and in different teams, then destroy the robot.
            //Otherwise the move is invalid.
            if (p->getMap().getX() == _map.getX()-1 && p->getMap().getY() == _map.getY()) {
                if (p->getTeam() != team) {
                    p = r.erase(p);
                    destroy = true;
                }
                else {
                    //if the robots are on the same team.
                    //no change will occur
                    flag = false;
                }
            }
            else {
                ++p;
            }
        }
        //If the coordinates are not occupied or enemy was destroyed, then increase the steps and change coordinates appropriately.
        if(flag || destroy) {
            _map.setX(_map.getX() - 1);
            ++steps;
        }
    }
}
//Order robots in ascending robot numbers.
bool ascending(const robot &x, const robot &y){
    return x.getId()<y.getId();
}
//Display the robots. Will print out to an output stream.
void show(ostream &out, list<robot> &robots){
    robots.sort(ascending);
    for(const auto &r: robots){
        out  << r.getId()<< " ";
        out << r.getTeam() << " ";
        out << r.getMap().getX() << " ";
        out << r.getMap().getY() << "\n";
    }
}
//Find a robot in a container by using a robot number.
list<robot>::iterator findRobot( list<robot> &r, int robotId){
    return find_if(r.begin(),r.end(),[robotId](robot &rr){return rr.getId() == robotId;});
}
// If the robots have completed the same amount of steps, then organise them according tho the robot number.
bool moreSteps(const robot &x, const robot &y){
    if(x.getSteps() == y.getSteps()) {
        return x.getId() < y.getId();
    }
    else{
        return x.getSteps()<y.getSteps();}
}
//Display robot number alongside steps taken in ascending order of steps.
void travelled(ostream &out,list<robot> &r){
    r.sort(moreSteps);
    for(const auto &robot:r){
        out << robot.getId() << " " << robot.getSteps()<<"\n";
    }
}
// Returns how many robots are within a certain distance from the origin.

//print the number of robots within a certain distance from the origin.
void within(ostream &out,list<robot> &r, int n){
    int checkWithin = count_if(r.begin(),r.end(),[n](robot &r) {return (abs(r.getMap().getX()))+abs(r.getMap().getY()) <= n;});
    out << checkWithin <<"\n";
}
//checks for a 'space'.
bool space(char c) {
    return isspace(c);
}
//Split the lines into words which are entered through the text files.
vector<string> split_words(const string& s) {
    vector<string> v;
    auto start = find_if_not(s.cbegin(), s.cend(),space);
    while (start != s.cend()) {
        auto end = find_if(start, s.cend(), space);
        v.emplace_back(start, end);
        start = find_if_not(end, s.cend(), space);
    }
    return v;
}


