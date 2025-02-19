#include <iostream>
#include <vector>
using namespace std;

class Student{
    string name, id;
    double gpa;
public:
    Student(string name, string id, double gpa) : name(name), id(id), gpa(gpa) {};
    double getGPA(){
        return gpa;
    }
    string getName(){
        return name;
    }
    string getID(){
        return id;
    }
};

class ListOfStudents{
    vector<Student> list;
public:
    void addStudent(Student student){
        list.push_back(student);
    }
    void sortList(){
        for (int i = 0; i < list.size(); i++)
        {
            for (int j = i + 1; j < list.size(); j++)
            {
                if (list[i].getGPA() > list[j].getGPA())
                {
                    swap(list[i], list[j]);
                }
            }
        }
    }
    void printList(){
        cout << "Name\tID\tGPA" << endl;
        for (int i = 0; i < list.size(); i++)
        {
            cout << list[i].getName() << "\t" << list[i].getID() << "\t" << list[i].getGPA() << endl;
        }
    }
};


int main(){
    cout << "== INPUT LIST OF STUDENTS, OUTPUT LIST THAT SORTED BY GPA ==" << endl;
    cout << "Enter number of students: ";
    int n;
    cin >> n; 
    ListOfStudents list;
    for (int i = 0; i < n; i++)
    {
        string name, id;
        double gpa;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter id of student " << i + 1 << ": ";
        cin >> id;
        cout << "Enter gpa of student " << i + 1 << ": ";
        cin >> gpa;
        list.addStudent(Student(name, id, gpa));
    }
    list.sortList();
    list.printList();
}