#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Time{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int, int);
    bool operator<(Time);
    bool operator>(Time);
};

Time::Time(){
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
}

bool Time::operator<(Time t){
    if(hours < t.hours){
        return true;
    }else if(hours == t.hours){
        if(minutes < t.minutes){
            return true;
        }
    }
    return false;
}

bool Time::operator>(Time t){
    if(hours > t.hours){
        return true;
    }else if(hours == t.hours){
        if(minutes > t.minutes){
            return true;
        }
    }
    return false;
}

class Singer{
private:
    string ID, name;
    int vote;
public:
    Singer();
    Singer(string, string);
    void voteFor();
    string getID();
    int getVote();
    string getName();
};

Singer::Singer(){
    ID = "";
    name = "";
    vote = 0;
}

Singer::Singer(string i, string n){
    ID = i;
    name = n;
    vote = 0;
}

void Singer::voteFor(){
    vote++;
}

string Singer::getID(){
    return ID;
}

int Singer::getVote(){
    return vote;
}

string Singer::getName(){
    return name;
}

class List{
private:
    vector<Singer> singers;
    int size;
    Time time;
public:
    List();
    void addSinger(Singer);
    void voteFor(string);
    void input(string filename);
    void output(string filename);
    bool checkIfExist(string);
    Singer getWinner();
};

List::List(){
    size = 0;
    time = Time(0, 0);
}

void List::addSinger(Singer s){
    singers.push_back(s);
    size++;
}

void List::voteFor(string ID){
    for(int i = 0; i < size; i++){
        if(singers[i].getID() == ID){
            singers[i].voteFor();
            break;
        }
    }
}

bool List::checkIfExist(string ID){
    for(int i = 0; i < size; i++){
        if(singers[i].getID() == ID){
            return true;
        }
    }
    return false;
}

void List::input(string filename){
    ifstream in(filename);
    if(!in.is_open()){
        cout << "File not found!" << endl;
        return;
    }
    string line;
    string start_time, end_time, dump;
    in >> start_time >> end_time;

    Time start(stoi(start_time.substr(0, 2)), stoi(start_time.substr(3, 2)));
    Time end(stoi(end_time.substr(0, 2)), stoi(end_time.substr(3, 2)));
    getline(in, dump);
    while(getline(in, line)){
        if (line == "") break;
        stringstream ss(line);
        string ID, name = "", time, namepart;
        ss >> ID;
        while(ss >> namepart){
            if(isdigit(namepart[0])){
                time = namepart;
                break;
            }
            name = name + namepart + " ";
        }
        name.pop_back(); // Loai bo khoang trang cuoi cung trong ten
        Time temp(stoi(time.substr(0, 2)), stoi(time.substr(3, 2)));
        if(temp < start || temp > end){
            continue;
        }
        if (checkIfExist(ID)){
            voteFor(ID);
        }
        else{
            addSinger(Singer(ID, name));
            voteFor(ID);
        }
    }
    in.close();
}

Singer List::getWinner(){
    int max = 0;
    int index = 0;
    for(int i = 0; i < size; i++){
        if(singers[i].getVote() > max){
            max = singers[i].getVote();
            index = i;
        }
    }
    return singers[index];
}

void List::output(string filename){
    ofstream out(filename);
    if(!out.is_open()){
        cout << "File not found!" << endl;
        return;
    }
    Singer winner = getWinner();
    out << winner.getName() << " " << winner.getVote() << endl;
    out.close();
}

int main(){
    List l;
    l.input("input.txt");
    l.output("output.txt");
    return 0;
}