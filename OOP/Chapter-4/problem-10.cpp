#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

class Meterorite {
private:
    string name;
    double x, y, r, v;
public:
    Meterorite() {}
    Meterorite(double x, double y, double r, double v): x(x), y(y), r(r), v(v) {}
    double getTime() {
        return (sqrt(x * x + y * y) - r) / v;
    }
    string getName() {return name; }
    friend ifstream& operator >> (ifstream& in, Meterorite& m) {
        string line;
        if (getline(in, line)) {
            size_t pos = line.find('(');
            m.name = line.substr(0, pos);
    
            // Extract x and y from inside the parentheses
            size_t comma_pos = line.find(',');
            size_t end_paren_pos = line.find(')');
            string x_str = line.substr(pos + 1, comma_pos - pos - 1);
            string y_str = line.substr(comma_pos + 1, end_paren_pos - comma_pos - 1);
            m.x = stod(x_str);
            m.y = stod(y_str);
    
            // Extract r and v (after the closing parenthesis)
            size_t space_pos = line.find(' ', end_paren_pos);
            size_t last_space_pos = line.find(' ', space_pos + 1);
            string r_str = line.substr(space_pos + 1, last_space_pos - space_pos - 1);
            string v_str = line.substr(last_space_pos + 1);
            m.r = stod(r_str);
            m.v = stod(v_str);
        }
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

    vector<Meterorite> v;
    Meterorite m;

    while (in >> m)
        v.push_back(m);

    if (v.empty()) {
        out << "No meteorites found!\n";
    } else {
        Meterorite earliest = v[0];
        double min_time = earliest.getTime();

        for (int i = 1; i < v.size(); i++) {
            double time = v[i].getTime();
            if (time < min_time) {
                min_time = time;
                earliest = v[i];
            }
        }

        out << earliest.getName() << " " << min_time;
    }


    in.close();
    out.close();

}