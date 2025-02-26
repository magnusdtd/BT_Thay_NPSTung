#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Field{
    double x, y;
public:
    Field(double x, double y) : x(x), y(y) {}
    double getArea() const { return x * y; }
};

class FieldList {
    vector<Field> fields;
    void sort() {
        std::sort(fields.begin(), fields.end(), [](const Field& a, const Field &b) {
            return a.getArea() > b.getArea();
        });
    }
public:
    void addField(Field field) {
        fields.push_back(field);
    }
    double getSumArea() {
        int n = fields.size();
        double sum = 0;

        for (const auto& field : fields)
            sum += field.getArea();

        return sum;
    }
    void getTheThreeSmallestArea() {
        int n = fields.size();
        
        if (n == 0) {
            cout << "No fields available\n";
            return;
        }

        vector<double> areas;
        for (const auto& field : fields)
            areas.push_back(field.getArea());

        // Find the 3 smallest using selection approach
        for (int i = 0; i < min(3, n); i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
                if (areas[j] < areas[minIdx])
                    minIdx = j;

            if (minIdx != i)
                swap(areas[i], areas[minIdx]);

            cout << areas[i] << " ";
        }
        cout << "\n";
    }
};

int main(){
    cout << "== INPUT LIST OF FIELDS, OUTPUT SUM OF AREA AND FIND 3 MIN AREA ==\n";
    int n;
    cout << "Enter number of fields: ";
    cin >> n;
    if (n < 0) {
        cout << "Number of fields cannot be negative\n";
        return 1;
    }

    FieldList fields;
    double x, y;

    for (int i = 0; i < n; i++){
        cout << "Enter x, y of field " << i + 1 << ": ";
        cin >> x >> y;
        fields.addField({x, y});
    }

    cout << "Sum of area: " << fields.getSumArea()  << "\n";
    
    cout << "3 fields have minimum area: ";
    fields.getTheThreeSmallestArea();

}