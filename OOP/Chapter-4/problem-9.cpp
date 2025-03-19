#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class Staff {
private:
    string roomID, name;
public:
    Staff() {}
    Staff(string roomID, string name): roomID(roomID), name(name) {}
    string getName() {return name;}
    string getRoomID() {return roomID;}
    friend ifstream& operator >> (ifstream& in, Staff& s) {
        string roomID, name;
        in >> roomID;
        getline(in >> ws, name);
        s.roomID = roomID;
        s.name = name;
        return in;
    }
};

int main() {
    ifstream in("input.txt", ios::in);
    ofstream out("output.txt", ios::out);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening file!\n";
        return 1;
    }

    vector<Staff> staffs;
    Staff staff;
    while (in >> staff) 
        staffs.push_back(staff);
    
    map<string, vector<Staff>> roomStaff;
    for (Staff& s : staffs)
        roomStaff[s.getRoomID()].push_back(s);

    // Find room with maximum staff
    string maxRoom;
    size_t maxCount = 0;
    for (const auto& pair : roomStaff) {
        if (pair.second.size() > maxCount) {
            maxCount = pair.second.size();
            maxRoom = pair.first;
        }
    }

    out << maxRoom << "\n";
    for (Staff& s : roomStaff[maxRoom]) {
        out << s.getName() << "\n";
    }

    in.close();
    out.close();

}