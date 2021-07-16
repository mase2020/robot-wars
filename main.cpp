#include "robot.h"
#include <iostream>
#include <fstream>


using namespace std;
int main() {
    //read the start.txt file.
    ifstream start("start.txt");
    list <robot> robots;
    int id;
    int team;
    int xPos;
    int yPos;
    while(start >> id >> team >> xPos >> yPos){
        robots.emplace_back(robot(id,team,map(xPos,yPos)));
    }
    //close the start.txt file.
    start.close();
    // read from the commands.txt file.
    ifstream commands("commands.txt");
    string line;
    string command;
    // Robot number or distance from the commands list.
    int robotId;
    while(getline(commands,line)) {
        vector<string> text =split_words(line);
        command = text[0];
        if(text.size()>1)
            robotId = stoi(text[1]);
        if (command == "show"){
            show(cout,robots);
        }
        else if(command == "travelled") {
            travelled(cout,robots);
        }
        else if(command == "within") {
            within(cout,robots, robotId);
        }
        else if (command == "turnleft") {
            auto foundRobot = findRobot(robots, robotId);
            //if robot is found, then turn left.
            if (foundRobot != robots.end())
            foundRobot->turnLeft();
        }
        else if (command == "turnright") {
            auto foundRobot = findRobot(robots, robotId);
            //if robot is found, then turn right.
            if (foundRobot != robots.end())
            foundRobot->turnRight();
        }
        else if (command == "move") {
            auto foundRobot = findRobot(robots, robotId);
            //if robot is found, then turn move.
            if (foundRobot != robots.end())
            foundRobot->move(robots);
        }
    }
    //closes the command.txt file.
    commands.close();
    return 0;
}
