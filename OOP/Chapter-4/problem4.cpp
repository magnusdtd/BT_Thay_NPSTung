#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Fraction{
private:
    int num, den;
public:
    Fraction();
    Fraction(int n, int d);
    Fraction operator+(Fraction b);
    void display();
    void simplify();
    void input(string filename);
    void output(string filename);
};
Fraction::Fraction(){
    num = 0;
    den = 1;
}

Fraction::Fraction(int n, int d){
    num = n;
    den = d;
}

Fraction Fraction::operator+(Fraction b){
    Fraction temp;
    temp.num = num * b.den + den * b.num;
    temp.den = den * b.den;
    temp.simplify();
    return temp;
}

void Fraction::display(){
    cout << num << "/" << den << endl;
}

void Fraction::simplify(){
    int gcd = 1;
    for(int i = 1; i <= num && i <= den; i++){
        if(num % i == 0 && den % i == 0){
            gcd = i;
        }
    }
    num /= gcd;
    den /= gcd;
}

void Fraction::input(string filename){
    ifstream in;
    in.open(filename);
    if(!in){
        cout << "Error opening file" << endl;
        exit(1);
    }
    in >> num >> den;
    in.close();
}

void Fraction::output(string filename){
    ofstream out;
    out.open(filename);
    if(!out){
        cout << "Error opening file" << endl;
        exit(1);
    }
    out << num << " " << den;
    out.close();
}



class List{
private:
    vector<Fraction> list;
    int size;
public:
    List();
    List(int s);
    void add(Fraction f);
    void display();
    void input(string filename);
    void output(string filename);
};

List::List(){
    size = 0;
}

List::List(int s){
    size = s;
}

void List::add(Fraction f){
    list.push_back(f);
    size++;
}

void List::display(){
    for(int i = 0; i < list.size(); i++){
        list[i].display();
    }
}

void List::input(string filename){
    ifstream in;
    in.open(filename);
    if(!in.is_open()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    int n, d;
    int temp;
    in >> temp;
    for (int i = 0; i < temp; i++)
    {
        in >> n >> d;
        Fraction f(n, d);
        add(f);
    }
    in.close();
}
void List::output(string filename){
    Fraction sum(0, 1);
    for (int i = 0; i < list.size(); i++)
    {
        sum = sum + list[i];
    }
    sum.output(filename);
}
    
int main(){
    List l;
    l.input("input.txt");
    l.output("output.txt");
    return 0;  
}