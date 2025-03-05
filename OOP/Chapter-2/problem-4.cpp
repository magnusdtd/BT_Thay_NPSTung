#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node();
    Node(int data);
    friend class Stack;
};

Node::Node() { data = 0; next = nullptr; }
Node::Node(int data): data(data), next(nullptr) {}

class Stack{
private:
    Node *head;
    int size;
public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    int top();
    bool isEmpty();
    int getSize();
};

Stack::Stack(): head(nullptr), size(0) {}
Stack::~Stack() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
    }
}
void Stack::push(int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    size++;
}
void Stack::pop() {
    if(!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    size --;
}
int Stack::top() { return head->data; }
bool Stack::isEmpty() { return head == nullptr; }
int Stack::getSize() { return size; }

int main(){
    Stack s;
    while (true)
    {
        system("clear"); // Clear for bash, ps and cls for cmd
        cout << "== SIMULATE STACK USING LINKED LIST ==\n";
        cout << "1. Push an element into Stack\n";
        cout << "2. Pop an element from Stack\n";
        cout << "3. Get the top element of Stack\n";
        cout << "4. Check if Stack is empty\n";
        cout << "5. Get Stack size\n";
        cout << "6. Exit\n";

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
                cout << "Stack is empty" << "\n";
            }
            else{
                cout << "The top element: " << s.top() << "\n";
            }
        }
        else if (choice == 4){
            if(s.isEmpty()){
                cout << "Stack is empty" << "\n";
            }
            else{
                cout << "Stack is not empty" << "\n";
            }
        }
        else if (choice == 5){
            cout << "Stack size: " << s.getSize() << "\n";
        }
        else if (choice == 6){
            break;
        }
        system("sleep 5");
    }
    
}