#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
};
class LinkedList{
    private:
    Node*head;
    public:
    LinkedList(){
        head = nullptr;
    }
    ~LinkedList(){
        Node*current = head;
        while(current != nullptr){
            Node*temp = current;
            current = current -> next;
            delete temp;
        }
    }
    LinkedList& insert(int value){
        Node*NewNode = new Node{value , head};
        head = NewNode;
        return *this;
    }
    LinkedList& append(int value){
        Node*NewNode = new Node{value , nullptr};
        if(head == nullptr){
            head = NewNode;
            return *this;
        }
        Node*current = head;
        while(current->next != nullptr){
            current = current -> next;
        }
        current->next = NewNode;
        return *this;
    }
    bool search(int value){
        Node*current = head;
        while(current != nullptr){
            if(current -> data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }
    LinkedList& remove(int value){
     //yaza bilmedim.    

    }
    LinkedList& display(){
        Node*current = head;
        while(current != nullptr){
            cout << current->data <<endl;
            current = current->next;
        }
        return *this;
    }

};

int main() {
    system("cls");

    /*      Example usage:     */
    LinkedList list = LinkedList();

    list.append(1).append(2).append(3).append(4);
    
    list.display();

    list.insert(5).display();

    bool isFound = list.search(4);

    cout << std::boolalpha << endl;
    cout << isFound;
    cout << endl << endl;

    list.remove(3).display().remove(4).display().remove(5).display();

    cout << endl;
}
