#include <iostream>
#include <vector>
using namespace std;

class Field{
    double x, y;
public:
    Field(int x, int y) : x(x), y(y) {}
    double Area(){
        return x * y;
    }
};

int main(){
    cout << "== INPUT LIST OF FIELDS, OUTPUT SUM OF AREA AND FIND 3 MIN AREA ==\n";
    int n;
    cout << "Enter number of fields: ";
    cin >> n;
    vector<Field> fields;
    for (int i = 0; i < n; i++){
        double x, y;
        cout << "Enter x, y of field " << i + 1 << ": ";
        cin >> x >> y;
        fields.push_back(Field(x, y));
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += fields[i].Area();
    }
    cout << "Sum of area: " << sum << "\n";
    cout << "3 fields have minimum area: ";
    for (int i = 0; i < fields.size(); i++){
        for (int j = 0; j < fields.size() - 1; j++)
        {
            if (fields[j].Area() > fields[j + 1].Area()){
                Field temp = fields[j];
                fields[j] = fields[j + 1];
                fields[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 3 && i < fields.size(); i++)
    {
        cout << fields[i].Area() << " ";
    }
    
    return 0;
}