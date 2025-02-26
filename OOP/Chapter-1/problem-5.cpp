#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Student{
    string name, id;
    double gpa;
public:
    Student(string name = "", string id = "", double gpa = 0.0) : name(name), id(id), gpa(gpa) {};
    double getGPA() const { return gpa; }
    string getName() const { return name; }
    string getID() const { return id; }
};

class ListOfStudents{
    vector<Student> list;
public:
    void addStudent(Student student){
        list.push_back(student);
    }
    void sortList() {
        if (list.empty()) return;
    
        int n = list.size();
        
        double maxGPA = list[0].getGPA();
        for (int i = 1; i < n; i++) 
            if (list[i].getGPA() > maxGPA) 
                maxGPA = list[i].getGPA();
        
        int range = static_cast<int>(maxGPA * 100) + 1;
        
        vector<int> count(range, 0);
        vector<Student> output(n);
        
        for (const auto& student : list) {
            int index = static_cast<int>(student.getGPA() * 100);
            count[index]++;
        }
        
        for (int i = 1; i < range; i++)
            count[i] += count[i - 1];
        
        for (int i = n - 1; i >= 0; i--) {
            int index = static_cast<int>(list[i].getGPA() * 100);
            output[count[index] - 1] = list[i];
            count[index]--;
        }
        
        list = move(output);
    }
    void printList() const {
        cout << left << setw(16) << "Name" << setw(16) << "ID" << "GPA\n";
        for (const auto& student : list) {
            cout << left << setw(16) << student.getName() 
                 << setw(16) << student.getID() 
                 << student.getGPA() << "\n";
        }
    }
};


int main(){
    cout << "== INPUT LIST OF STUDENTS, OUTPUT LIST THAT SORTED BY GPA ==" << endl;
    cout << "Enter number of students: ";
    int n;
    cin >> n; 

    ListOfStudents list;
    string name, id;
    double gpa;

    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter id of student " << i + 1 << ": ";
        cin >> id;
        cout << "Enter gpa of student " << i + 1 << ": ";
        cin >> gpa;
        list.addStudent({name, id, gpa});
    }

    list.sortList();
    list.printList();
}