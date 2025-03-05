#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node();
    Node(int data);
    friend class Queue;
};

Node::Node() { data = 0; next = nullptr; }
Node::Node(int data): data(data), next(nullptr) {}

class Queue{
private:
    Node* head;
    int size;
public:
    Queue();
    ~Queue();
    void push(int data);
    void pop();
    int front();
    int getSize();
    bool isEmpty();
};

Queue::Queue(): head(nullptr), size(0) {}
Queue::~Queue() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
    }
}
void Queue::push(int data){
    Node* temp = new Node(data);
    if(!head)
        head = temp;
    else {
        Node* current = head;
        while(current->next)
            current = current->next;
        current->next = temp;
    }
    size++;
}
void Queue::pop(){
    if(!head ){
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}
int Queue::front(){
    if(head == nullptr){
        cout << "Queue is empty\n";
        return -1;
    }
    return head->data;
}
int Queue::getSize(){ return size; }
bool Queue::isEmpty(){ return head == nullptr; }

int main(){
    Queue q;
    while (true)
    {
        system("clear");
        cout << "== SIMULATE QUEUE USING LINKED LIST ==\n";
        cout << "1. Push an element into Queue\n";
        cout << "2. Pop an element from Queue\n";
        cout << "3. Get the front element of Queue\n";
        cout << "4. Check if Queue is empty\n";
        cout << "5. Get Queue size\n";
        cout << "6. Exit\n";

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
                cout << "Stack is empty" << "\n";
            }
            else{
                cout << "The top element: " << q.front() << "\n";
            }
        }
        else if (choice == 4){
            if(q.isEmpty()){
                cout << "Stack is empty\n";
            }
            else{
                cout << "Stack is not empty\n";
            }
        }
        else if (choice == 5){
            cout << "Stack size: " << q.getSize() << "\n";
        }
        else if (choice == 6){
            break;
        }

        system("sleep 3");
    }
    
}