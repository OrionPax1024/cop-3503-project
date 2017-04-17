/*
Project Team 18 Presents:
Final Project Spring 2017
Team Members:
Alex deQuevedo
Andres Hernandez
Alisa Watson
Brendan Cohen
Janine Faith Penaflorida
Maxwell Nolan
Yi Lin
*/
#include <iostream>
#include <string>


using namespace std;

string title[] = {"Elf","Orc","Nord","Goblin","Human"};
/******************
//Player Class//
******************/
class Player {
private:
    string name;
    bool hasSword;
    int strength;
    int stealth;
public:
    Player(int, int, string);
    
    void setName(string);
    void setHasSword();
    void setStrength(int);
    void setStealth(int);
    
   
    
    void printStats(int);
    
    bool attack(Player);
    
    void addStrength();
    void addStealth();
    void addStrength(int);
    void addStealth(int);
    
    string getName();
    bool getHasSword();
    int getStrength();
    int getStealth();
};

int Player::getStrength(){
    return strength;
}
int Player::getStealth(){
    return stealth;
}

void Player::setStrength(int str){
    this->strength = str;
}
void Player::setStealth(int sth){
    this->stealth = sth;
}

Player::Player(int str, int sth, string name) {
    this->name = name;
    this->hasSword = false;
    this->strength = str;
    this->stealth = sth;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setHasSword() {
    this->hasSword = true;
}

string Player::getName() {
    return name;
}

bool Player::getHasSword() {
    return hasSword;
}

void Player::printStats(int race) {
    cout << name << ", the "<< title[race-1] << endl;
    cout << "Strength: " << strength << endl;
    cout << "Stealth: " << stealth << "\n"<< endl;
}

void Player::addStrength(){
    int i = rand() % 10;
    cout << "You gained " << i << " Strength points\n" << "\n";
    Player::addStrength(i);
}

void Player::addStealth(){
    int i = rand() % 10;
    cout << "You gained " << i << " Stealth points\n" << "\n";
    Player::addStealth(i);
}

void Player::addStrength(int i){
    this->strength = strength + i;
}
void Player::addStealth(int i){
    this->stealth = stealth + i;
}
/******************
//Sphinx Subclass//
******************/
class Sphinx {
private:
    string riddle;
    string riddleAns;
    int riddleNum;
public:
    Sphinx();
    int remainingAttempts;
    string getRiddle(int);
    int getRemainingAttempts();
    string getRiddleAns(int);
};

Sphinx::Sphinx(){
    remainingAttempts = 3;
}

string Sphinx::getRiddle(int randNum) {
    switch(randNum){
    case 1:
        riddleNum = 1;
        return "What is 2+2?";
        break;
    case 2:
        riddleNum = 2;
        return "What is zero factorial?";
        break;
    case 3:
        riddleNum = 3;
        return "What year is it?";
        break;
    default:
        return "";
    }
}

string Sphinx::getRiddleAns(int riddleNum) {
    switch(riddleNum) {
    case 1:
        return "4";
        break;
    case 2:
        return "1";
        break;
    case 3:
        return "2017";
        break;
    default:
        return "";
    }
}

int Sphinx::getRemainingAttempts() {
    return remainingAttempts;
}

