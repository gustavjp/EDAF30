#include <iostream>
#include <vector>
#include <cstdlib>
#include "kanin.h"
#include "quicksort.h"

using namespace std;

vector<string> createNameVector(int kaniner);
string getRandName(vector<string> &nameVector);
int main()
{
    srand(time(0));
    int kaniner = 10;
    if(kaniner > 10) {
        kaniner = 10;
    }
    vector<string> nameVector (createNameVector(kaniner));
    vector<Kanin> kaninVector;
    Kanin kaninArray[10];

    for(int i = 0; i < kaniner; i++) {
        Kanin kanin = {getRandName(nameVector)};
        kaninVector.insert(kaninVector.begin()+i, kanin);
        kaninArray[i] = kanin;
    }
    for(int i = 0; i < kaniner; i++) {
        cout << "Rabbit " << kaninArray[i].getName() << " has agility " << kaninArray[i].getAgility() << endl;
    }
    cout << "Sorting..." << endl;
    quicksort(kaninArray, 0, 9);
    for(int i = 0; i < kaniner; i++) {
        cout << "Rabbit " << kaninArray[i].getName() << " has agility " << kaninArray[i].getAgility() << endl;
    }

    return 0;
}

/**
  * Creates a vector of strings with iconic names of Star Trek: The Next Generation characters.
  */
vector<string> createNameVector(int kaniner) {
    string names[10] = {"Jean-Luc Picard", "William Riker", "Beverly Crusher", "Deanna Troi",
    "Geordi La Forge", "Data", "Worf", "Wesley Crusher", "Guinan", "Tasha Yar"};
    vector<string> nameVector;
    nameVector.assign(names, names+kaniner);
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
