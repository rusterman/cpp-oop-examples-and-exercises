#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
class Queue{
    private:
    Node*front;
    Node*rear;
    public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    ~Queue(){
        while(front != nullptr){
            Node*current = front;
            front = front -> next;
            delete current;
        }
    }
    int isEmpty(){
        if(front == nullptr){
            return 1;
        }
        else{
            return 0;
        }
    }
    int peek(){
        if(front == nullptr){
            cout << "Queue is empt: " <<endl;
            return -1;
        }
        return front -> data;
    }
    Queue& enqueue(int value){
        Node*NewNode = new Node{value , nullptr};
        if(rear == nullptr){
            rear = NewNode;
            front = NewNode;
            return *this;
        }
        else{
            rear->next = NewNode;
            rear = NewNode;
            return *this;
        }
    }
    int dequeue(){
        if(front == nullptr){
            cout << "nothing" <<endl;
            return -1;
        }
        Node*temp = front;
        int value = temp->data;
        front = front -> next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        return value;


    }
    int size(){
        Node*current = front;
        int size1 = 0;
        while(current != nullptr){
            size1++;
            current = current->next;
        }
        return size1;
    }

};
int main(){
    Queue queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Size: " << queue.size() << endl;   // Output: Size: 3
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 10
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 10
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 0 (false)
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 20
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 20
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 0 (false)
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 30
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 30
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 1 (true)


}
