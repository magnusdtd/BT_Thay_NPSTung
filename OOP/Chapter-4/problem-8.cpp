#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

class Time {
private:
    int hour, minute;
public:
    Time(): hour(0), minute(0) {}
    Time(string timeStr) {
        sscanf(timeStr.c_str(), "%d:%d", &hour, &minute);
    }
    bool isValid(Time start, Time end) {
        if (hour < start.hour || hour > end.hour) return false;
        if (hour == start.hour && minute < start.minute) return false;
        if (hour == end.hour && minute > end.minute) return false;
        return true;
    }
    friend class VotingSystem;
};

class Vote {
    string code;
    string singer;
    Time time;
public:
    Vote(): time() {}
    Vote(string c, string s, string t) : code(c), singer(s), time(t) {}
    friend class VotingSystem;
};

class VotingSystem {
private:
    map<string, int> voteCount;
    Time startTime, endTime;
    
    void processVote(Vote vote) {
        if (vote.time.isValid(startTime, endTime)) 
            voteCount[vote.singer]++;
    }
    
public:
    VotingSystem(string start, string end) : startTime(start), endTime(end) {}
    
    void readInput(string inputFile) {
        ifstream in(inputFile);
        string line;
        
        getline(in, line);
        
        while (getline(in, line)) {
            stringstream ss(line);
            string code, singer, time;
            
            ss >> code;
            
            // Read the time (last part)
            size_t lastSpace = line.rfind(' ');
            time = line.substr(lastSpace + 1);
            
            // Get the singer name (everything between code and time)
            size_t firstSpace = line.find(' ');
            singer = line.substr(firstSpace + 1, lastSpace - firstSpace - 1);
            
            Vote vote(code, singer, time);
            processVote(vote);
        }
        in.close();
    }
    
    void writeResult(string outputFile) {
        ofstream out(outputFile);
        string maxSinger;
        int maxVotes = 0;
        
        for (auto& pair : voteCount) {
            if (pair.second > maxVotes) {
                maxVotes = pair.second;
                maxSinger = pair.first;
            }
        }
        
        out << maxSinger << " " << maxVotes;
        out.close();
    }
};

int main() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Error opening input file!\n";
        return 1;
    }

    string start, end;
    in >> start >> end;
    in.close();
    
    VotingSystem system(start, end);
    system.readInput("input.txt");
    system.writeResult("output.txt");
    
    return 0;
}