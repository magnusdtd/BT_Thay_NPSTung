#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream in("input.txt", ios::in), out("output.txt", ios::out);

    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening file!\n";
        return 1;
    }

    string name, longestName;
    while (getline(in, name))
        if (name.size() > longestName.size())
            longestName = name;
    in.close();

    if (!longestName.empty()) 
        out << longestName << " " << longestName.size() << "\n";
    out.close();

}