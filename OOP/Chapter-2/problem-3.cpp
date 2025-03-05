#include<iostream>
#include <climits>
using namespace std;

class List{
private:
    int* arr;
    int size;
public:
    List(int n);
    ~List();
    void input();
    void output();
    void findTheSecondLargest();
};

List::List(int n) {
    size = n;
    arr = new int[n];
}
List::~List() { delete[] arr; }
void List::input(){
    for(int i = 0; i < size; i++)
        cin >> arr[i];
}
void List::output(){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void List::findTheSecondLargest(){     
    if (size <= 1) {
        cout << "The second largest element doesn't exist!\n";
        return ;
    }   
    int largest = arr[0], secondLargest = INT_MIN;
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) 
            secondLargest = arr[i];
    }
    cout << "The second largest element: " << secondLargest << "\n";
}

int main(){
    cout << "== INPUT AN ARRAY, CALL THE FUNCTION ==\n";
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    List list(n);

    cout << "Enter the elements of the array: ";
    list.input();

    cout << "The array: ";
    list.output();
    
    list.findTheSecondLargest();


}