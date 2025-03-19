#include <iostream>
using namespace std;

class Student{
private:
    string ID;
    double math, literature;
public:
    Student();
    Student(string ID, double math, double literature);
    double GPA();
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

double Student::GPA(){
    return (math + literature) / 2;
}

string Student::getID(){
    return ID;
}

class ListStudent{
private:
    Student *list;
    int n;
public:
    ListStudent();
    ListStudent(int n);
    ~ListStudent();
    void input();
    void output();
    double avgListGPA();
    void sort();
    void rank();
};

ListStudent::ListStudent(){
    n = 0;
    list = NULL;
}

ListStudent::ListStudent(int n){
    this->n = n;
    list = new Student[n];
}

ListStudent::~ListStudent(){
    delete[] list;
}

void ListStudent::input(){
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    list = new Student[n];
    for(int i = 0; i < n; i++){
        string ID;
        double math, literature;
        cout << "Nhap ID hoc sinh thu " << i + 1 << ": ";
        cin >> ID;
        cout << "Nhap diem toan cua hoc sinh thu " << i + 1 << ": ";
        cin >> math;
        cout << "Nhap diem van cua hoc sinh thu " << i + 1 << ": ";
        cin >> literature;
        list[i] = Student(ID, math, literature);
    }
}

void ListStudent::output(){
    for(int i = 0; i < n; i++){
        cout << "Diem trung binh cua hoc sinh " << list[i].getID() << " la: " << list[i].GPA() << "\n";
    }
}

double ListStudent::avgListGPA(){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += list[i].GPA();
    }
    return sum / n;
}

void ListStudent::sort(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(list[i].GPA() < list[j].GPA()){
                Student temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void ListStudent::rank(){
    sort();
    int rank = 1;
    for (size_t i = 0; i < n; i++)
    {
        cout << "Hoc sinh " << list[i].getID() << " xep hang " << rank << "\n";
        if(i < n - 1 && list[i].GPA() != list[i + 1].GPA()){
            rank++;
        }
    }
    
}

/*
5
23120115 8 9
23120011 7 5
23120099 9 8
23120055 6 7
23120101 8 8
*/

int main(){
    ListStudent listStudent;
    listStudent.input();
    listStudent.output();
    cout << "Diem trung binh cua tat ca hoc sinh la: " << listStudent.avgListGPA() << "\n";
    listStudent.rank();
    cout << "Danh sach hoc sinh sau khi sap xep theo diem trung binh giam dan:\n";
    listStudent.rank();
    return 0;
}