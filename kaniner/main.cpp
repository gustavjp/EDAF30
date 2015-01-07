#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <limits>
#include "kanin.h"

using namespace std;

int getInput();
vector<Kanin> raceSetup(int kaniner);
void race(vector<Kanin> kaninVector);
vector<string> createNameVector();
string getRandName(vector<string> &nameVector);
vector<Kanin> sortByDistance(vector<Kanin> unsortedVector);
int main()
{
    srand(time(0));
    int kaniner = 0;
    cout << "============" << endl;
    cout << "Rabbit Race!" << endl;
    cout << "============" << endl << endl;
    while(true) {
        cout << "How many rabbits (1 to 23) shall compete?";
        kaniner = getInput();
        if(kaniner < 24 && kaniner > 0) {
            cout << kaniner << " rabbits are to compete." << endl << "Let's start the race!" << endl;
            race(raceSetup(kaniner));
            cout << "Input 1 to play again or any other character to exit.";
            if(getInput() != 1) {
                break;
            }
        } else {
            cout << "Rabbits out of range. Please chose 1 to 23 rabbits." << endl;
        }
    }
    return 0;
}

/**
  * Handles input.
  */
int getInput() {
    int input;
    cout << endl << "$ ";
    if(!(cin >> input)) { //checks that the input is an integer
        cout << "Please only use integers as input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return 0; //returns 0 if input is not an integer
        }
    return input;
}

/**
  * Creates a vector of rabbits.
  * Setups the race.
  */
vector<Kanin> raceSetup(int kaniner) {
    vector<string> nameVector (createNameVector());
    vector<Kanin> kaninVector;
    for(int i = 0; i < kaniner; i++) {
        Kanin kanin = {getRandName(nameVector)};
        kaninVector.insert(kaninVector.begin()+i, kanin);
    }
    return kaninVector;
}

/**
  * This is the race.
  */
void race(vector<Kanin> kaninVector) {
    int track = 1000; //1000 cm = 10 m
    bool win = false;
    while(!win) { //loops until a rabbit has won
        for(int i = 0; i < (int) kaninVector.size(); i++) {
            kaninVector.at(i).jump();
            if(kaninVector.at(i).getDistance() >= track) {
                win = true;
                cout << endl << "We have a winner!" << endl;
                cout << kaninVector.at(i).getName() << " won!" << endl;
                break;
            }
        }
    }
    kaninVector = sortByDistance(kaninVector);
    cout << "Here are the results!" << endl;
    for(int i = 0; i < (int) kaninVector.size(); i++) {
        cout << kaninVector.at(i).getName() << ": " << kaninVector.at(i).getDistance() << endl;
    }
}

/**
  * Creates a vector of strings with iconic names of Star Trek: The Next Generation characters.
  */
vector<string> createNameVector() {
    string names[23] = {"Jean-Luc Picard", "William Riker", "Beverly Crusher", "Deanna Troi",
    "Geordi La Forge", "Data", "Worf", "Wesley Crusher", "Guinan", "Tasha Yar", "Miles O'Brien",
    "Katherine Pulaski", "Reginald \"Broccoli\" Barclay", "Alyssa Ogawa", "Mr. Homm", "Gowron",
    "Alexander Rozhenko", "Q", "Lore", "The Traveler", "Hugh of Borg", "Locutus", "Zefram Cochrane"};
    vector<string> nameVector;
    nameVector.assign(names, names+23);
    return nameVector;
}

/**
  * Pops a random string from a vector.
  */
string getRandName(vector<string> &nameVector) {
    int i = rand() % nameVector.size();
    string name = nameVector.at(i);
    nameVector.erase(nameVector.begin()+i);
    return name;
}

/**
  * A simple selection sorting mechanism.
  * Sorts a vector of rabbits in descending order of distance.
  */
vector<Kanin> sortByDistance(vector<Kanin> unsortedVector) {
    vector<Kanin> sortedVector;
    int maximum = INT_MIN;
    int index = 0;
    while(!unsortedVector.empty()) {
        for(int i = 0; i < (int) unsortedVector.size(); i++) {
            if(unsortedVector.at(i).getDistance() > maximum) {
                maximum = unsortedVector.at(i).getDistance();
                index = i;
            }
        }
        sortedVector.push_back(unsortedVector.at(index));
        unsortedVector.erase(unsortedVector.begin()+index);
        maximum = INT_MIN;
        index = 0;
    }
    return sortedVector;
}
