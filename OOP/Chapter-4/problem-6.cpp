#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Character{
private:
    string name;
public:
    Character();
    Character(string name);
    void setName(string name);
    string getName();
};

Character::Character(){
    name = "";
}

Character::Character(string name){
    this->name = name;
}

void Character::setName(string name){
    this->name = name;
}

string Character::getName(){
    return name;
}

class List{
private:
    vector<Character> characters;
    int size;
public:
    List();
    string getMaxLengthName();
    void add(Character character);
    void input(string filename);
    void output(string filename);
};

List::List() {
    size = 0;
}

void List::add(Character character){
    characters.push_back(character);
    size++;
}

void List::input(string filename){
    ifstream in;
    in.open(filename);
    if(!in.is_open()){
        cerr << "Error opening file" << "\n";
        exit(1);
    }
    string name;
    while(getline(in, name)){
        Character character(name);
        add(character);
    }
    in.close();
}


string List::getMaxLengthName(){
    string maxLengthName = "";
    for(int i = 0; i < size; i++)
        if(characters[i].getName().length() > maxLengthName.length())
            maxLengthName = characters[i].getName();
    return maxLengthName;
}

void List::output(string filename){
    ofstream out;
    out.open(filename);
    if(!out.is_open()){
        cerr << "Error opening file" << "\n";
        exit(1);
    }
    string maxLengthName = getMaxLengthName();
    out << maxLengthName << " " << maxLengthName.length() << "\n";
    out.close();
}

int main(){
    List l;
    l.input("input.txt");
    l.output("output.txt");
    return 0;
}