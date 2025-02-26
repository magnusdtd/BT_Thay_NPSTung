#include<iostream>
using namespace std;

class List{
    int* arr;
    int size;
public:
    List(int n){
        size = n;
        arr = new int[size];
    }
    ~List(){
        delete[] arr;
    }
    void input(){
        for(int i = 0; i < size; i++)
            cin >> arr[i];
    }
    void output(){
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    void findTheSecondLargest(){     
        if (size <= 1) {
            cout << "The second largest element doesn't exist!\n";
            return;
        }   
        for (int i = 0; i < min(2, size); i++) {
            int maxIdx = i;
            for (int j = i + 1; j < size; j++)
                if (arr[j] > arr[maxIdx])
                    maxIdx = j;
            
            if (maxIdx != i)
                swap(arr[i], arr[maxIdx]);

            if (i == 1) {
                cout << arr[i] << "\n";
                return;
            }
        }

    }
};

int main(){
    cout << "== INPUT AN ARRAY, CALL THE FUNCTION ==" << "\n";
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