#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#define THIS_YEAR 2025

class Player {
private:
    string name;
    int day, month, year;
public:
    Player() {}
    Player(string n, int d, int m, int y): name(n), day(d), month(m), year(y) {}
    int getAge() { return THIS_YEAR - year; }
    friend class PlayerManager;
};

class PlayerManager {
private:
    vector<Player> players;
public:
    void loadDataFromFile(string fileName) {
        fstream in(fileName, ios::in);
        if (!in.is_open()) {
            cout << "Error opening file!\n";
            return;
        }

        string line;
        while (getline(in, line)) {
            if (line.empty())
                break;
            stringstream ss(line);
            string name, temp, dob;
            int day, month, year;

            while (ss >> temp) {
                if (isdigit(temp[0])) {
                    dob = temp;
                    break;
                }
                if (!name.empty()) name += " ";
                name += temp;
            }

            sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);
            players.push_back({name, day, month, year});
        }

        in.close();
    }

    void saveOldestPlayer(string fileName) {
        fstream out(fileName, ios::out);
        if (!out.is_open()) {
            cout << "Error opening file!\n";
            return;
        }
        Player oldestPlayer;
        int minYear, minDay = 100, minMonth = 100;
        for (auto& player : players) {
            if  (player.year <  minYear || 
                (player.year == minYear && player.month < minMonth) ||
                (player.year == minYear && player.month == minMonth && player.day < minDay)) {
                oldestPlayer = player;
                minYear = player.year;
                minMonth = player.month;
                minDay = player.day;
            }
        }

        out << oldestPlayer.name << " " << oldestPlayer.getAge() << "\n";

        out.close();
    }
};

int main() {
    PlayerManager manager;
    manager.loadDataFromFile("input.txt");
    manager.saveOldestPlayer("output.txt");
}