#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;
        int size;
    public:
        Stack(){
            top = NULL;
            size = 0;
        }
        void push(int x){
            Node* temp = new Node();
            temp->data = x;
            temp->next = top;
            top = temp;
            size++;
        }
        void pop(){
            if(top == NULL) return;
            Node* temp = top;
            top = top->next;
            delete temp;
            temp = nullptr;
            size --;
        }
        int Top(){
            return top->data;
        }
        bool isEmpty(){
            return top == NULL;
        }
        int getSize(){
            return size;
        }
};

int main(){
    Stack s;
    while (true)
    {
        system("cls");
        cout << "== SIMULATE STACK USING LINKED LIST ==" << endl;
        cout << "1. Push an element into Stack" << endl;
        cout << "2. Pop an element from Stack" << endl;
        cout << "3. Get the top element of Stack" << endl;
        cout << "4. Check if Stack is empty" << endl;
        cout << "5. Get Stack size" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1){
            int x;
            cout << "Enter the element: ";
            cin >> x;
            s.push(x);
        }
        else if (choice == 2){
            s.pop();
        }
        else if (choice == 3){
            if(s.isEmpty()){
                cout << "Stack is empty" << endl;
            }
            else{
                cout << "The top element: " << s.Top() << endl;
            }
        }
        else if (choice == 4){
            if(s.isEmpty()){
                cout << "Stack is empty" << endl;
            }
            else{
                cout << "Stack is not empty" << endl;
            }
        }
        else if (choice == 5){
            cout << "Stack size: " << s.getSize() << endl;
        }
        else if (choice == 6){
            break;
        }

        system("pause");
    }
    
    
    return 0;
}