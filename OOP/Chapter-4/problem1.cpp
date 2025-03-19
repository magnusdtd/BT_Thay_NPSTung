#include <iostream>
using namespace std;

class Student{
private:
    string ID;
    double math, literature;
public:
    Student();
    Student(string ID, double math, double literature);
    float GPA();
    string getID();
};

Student::Student(){
    ID = "";
    math = 0;
    literature = 0;
}

Student::Student(string ID, double math, double literature){
    this->ID = ID;
    this->math = math;
    this->literature = literature;
}

float Student::GPA(){
    return (math + literature) / 2;
}

string Student::getID(){
    return ID;
}

int main(){
    Student student1("23120115", 8, 9);
    cout << "Diem trung binh cua sinh vien " << student1.getID() << " la: " << student1.GPA() << "\n";
    return 0;
}