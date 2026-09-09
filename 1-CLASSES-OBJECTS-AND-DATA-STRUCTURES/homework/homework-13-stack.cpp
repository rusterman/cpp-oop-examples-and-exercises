#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
protected:              
    Node* head;
public:
    LinkedList() { head = nullptr; }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    LinkedList& insert(int value) {
        Node* NewNode = new Node{value, head};
        head = NewNode;
        return *this;
    }

    LinkedList& append(int value) {
        Node* NewNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = NewNode;
            return *this;
        }
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = NewNode;
        return *this;
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    
    LinkedList& remove(int value) {
        if (head == nullptr) return *this;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return *this;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        return *this;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) { count++; current = current->next; }
        return count;
    }

    LinkedList& display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
        return *this;
    }
};
class Stack : public LinkedList{
    public:
    Stack& push(int value){
        insert(value);
        return*this;

    }
    Stack& pop(){
        if(head == nullptr){
            cout << "Nothing pop" <<endl;
            return *this;
        }
        else{
            remove(head->data);
            return *this;
        }

    }
    Stack& peek(){
        if(head == nullptr){
            cout << "Nothing peek" <<endl;
            return *this;
        }
        else{
            cout << "Peek element: " << head -> data <<endl;
            return *this;
        }

    }
    Stack& displayStack(){
        display();
        return *this;
    }

};

int main() {
    Stack stack;

    stack.peek();
    stack.push(1).push(2).push(3).push(4).push(5);

    cout << "Size: " << stack.size() << endl << endl;

    stack.displayStack();
    stack.pop();
    stack.displayStack();

    cout << endl;
    stack.peek();
    cout << endl;

    stack.pop().pop().pop().pop().pop();
    stack.displayStack();
}
