#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int d, int m, int y): day(d), month(m), year(y){}
    int getYear();
};

Date::Date(){
    day = 0;
    month = 0;
    year = 0;
}

int Date::getYear(){
    return year;
}

class Player{
private:
    string name;
    Date dob;
public:
    Player();
    Player(string n, Date d);
    string getName();
    int getAge();
};

Player::Player(){
    name = "";
    Date dob(0, 0, 0);
}

Player::Player(string n, Date d){
    name = n;
    dob = d;
}

string Player::getName(){
    return name;
}

int Player::getAge(){
    return 2025 - dob.getYear();
}

class List{
private:
    vector<Player> players;
    int size;
public:
    List();
    void addPlayer(Player p);
    void input(string filename);
    void output(string filename);
    Player getOldest();
};

List::List(){
    size = 0;
}

void List::addPlayer(Player p){
    players.push_back(p);
    size++;
}

void List::input(string filename){
    string name;
    int day, month, year;
    ifstream in;
    in.open(filename);
    if (!in.is_open()){
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    while(getline(in, line)){
        if (line == "") break;;
        stringstream ss(line);
        string namePart, name = "", date;
        while (ss >> namePart){
            if (isdigit(namePart[0])){
                date = namePart;
                string temp;
                ss >> temp;
                string day = date.substr(0, 2);
                string month = date.substr(3, 2);
                string year = date.substr(6, 4);
                int d = stoi(day);
                int m = stoi(month);
                int y = stoi(year);
                Date dob(d, m, y);
                Player p(name, dob);
                addPlayer(p);
            }
            name = name + namePart + " ";
        }
    }
    in.close();
}

Player List::getOldest(){
    int oldest = 0;
    int index = 0;
    for (int i = 0; i < size; i++){
        if (players[i].getAge() > oldest){
            oldest = players[i].getAge();
            index = i;
        }
    }
    return players[index];
}

void List::output(string filename){
    ofstream out;
    out.open(filename);
    if (!out.is_open()){
        cout << "Error opening file" << endl;
        return;
    } 
    Player oldest = getOldest();
    out << oldest.getName() << " " << oldest.getAge() << endl;
    out.close();
}

int main(){
    List l;
    l.input("input.txt");
    l.output("output.txt");
    return 0;
}