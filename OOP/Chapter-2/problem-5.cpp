#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
private:
    Node* front;
    int size;
public:
    Queue(){
        front = NULL;
        size = 0;
    }
    void push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if(front == NULL){
            front = temp;
        }else{
            Node* temp1 = front;
            while(temp1->next != NULL){
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
        size++;
    }
    void pop(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    int getFront(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return front == NULL;
    }
};

int main(){
    Queue q;
    while (true)
    {
        system("cls");
        cout << "== SIMULATE QUEUE USING LINKED LIST ==" << endl;
        cout << "1. Push an element into Queue" << endl;
        cout << "2. Pop an element from Queue" << endl;
        cout << "3. Get the front element of Queue" << endl;
        cout << "4. Check if Queue is empty" << endl;
        cout << "5. Get Queue size" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1){
            int x;
            cout << "Enter the element: ";
            cin >> x;
            q.push(x);
        }
        else if (choice == 2){
            q.pop();
        }
        else if (choice == 3){
            if(q.isEmpty()){
                cout << "Stack is empty" << endl;
            }
            else{
                cout << "The top element: " << q.getFront() << endl;
            }
        }
        else if (choice == 4){
            if(q.isEmpty()){
                cout << "Stack is empty" << endl;
            }
            else{
                cout << "Stack is not empty" << endl;
            }
        }
        else if (choice == 5){
            cout << "Stack size: " << q.getSize() << endl;
        }
        else if (choice == 6){
            break;
        }

        system("pause");
    }
    
    
    return 0;
}