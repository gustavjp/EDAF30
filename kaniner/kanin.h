#ifndef KANIN_H
#define KANIN_H

using namespace std;

class Kanin {

public:
    Kanin(string n = "anonymous coward") : name(n) {
        agility = rand()%100 + 1;
        distance = 0;
    };
    int getAgility() { return agility; };
    string getName() { return name; };
    void jump() {
        action = rand()%100 + 1;
        if(action <= 40) {
            distance += rand()%20 + 20;
        } else if(action > 40 && action <= 60) {
            distance -= rand()%20 + 20;
        } else {
            //gör inget
        }
    };
private:
    int agility;
    string name;
    int distance;
    int action;
};

#endif
