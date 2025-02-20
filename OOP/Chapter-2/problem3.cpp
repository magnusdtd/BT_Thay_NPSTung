#include<iostream>
using namespace std;

class list{
    int* arr;
    int size;
    public:
    list(int n){
        size = n;
        arr = new int[size];
    }
    ~list(){
        delete[] arr;
    }
    void input(){
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
    }
    void output(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void sort(){
        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++){
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void find_second_max(){
        sort();
        cout << arr[size - 2] << endl;
    }
};

int main(){
    cout << "== INPUT AN ARRAY, CALL THE FUNCTION ==" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    list l(n);
    cout << "Enter the elements of the array: ";
    l.input();
    cout << "The array: ";
    l.output();
    cout << "Sopted array: ";
    l.sort();
    l.output();
    cout << "The second largest element: ";
    l.find_second_max();
    return 0;
}