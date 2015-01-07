#ifndef KANIN_H
#define KANIN_H

using namespace std;

class Kanin {
public:
    Kanin(string n = "anonymous coward") : name(n) {
        distance = 0;
    };
    int getDistance() { return distance; };
    string getName() { return name; };
    void jump() {
        action = rand()%101; //0-100
        if(action < 20) { //20% chance of jumping backwards
            distance -= rand()%20 + 20;
        } else if(action >= 20 && action <= 60) { //40% chance of standing still
            //gör inget
        } else if(action > 60) { //40% chance of jumping forwards
            distance += rand()%20 + 20;
        }
    };
private:
    string name; //the name of the rabbit
    int distance; //the distance the rabbit has jumped from its initial position
    int action; //the action to be taken (backwards, nothing, forwards)
};

#endif
