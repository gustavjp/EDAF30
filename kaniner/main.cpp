#include <iostream>
#include <vector>
#include <cstdlib>
#include "kanin.h"

using namespace std;

vector<string> createNameVector(int kaniner);
string getRandName(vector<string> &nameVector);
int main()
{
    int kaniner = 10;
    if(kaniner > 10) {
        kaniner = 10;
    }
    vector<string> nameVector (createNameVector(kaniner));
    vector<Kanin> kaninVector;

    for(int i = 0; i < kaniner; i++) {
        Kanin kanin = {getRandName(nameVector), rand()%10 + 1};
        kaninVector.insert(kaninVector.begin()+i, kanin);
        cout << "Rabbit: " << kanin.name << endl;
        cout << "Same: " << kaninVector.at(i).name << endl;
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
    srand(time(0));
    int i = rand() % nameVector.size();
    string name = nameVector.at(i);
    nameVector.erase(nameVector.begin()+i);
    return name;
}
