#include <iostream>

using namespace std;

/*
    A linked list is a linear data structure that includes a series of connected nodes. 
    Here, each node stores the data and the address of the next node. 
    Examples: 
    https://media.geeksforgeeks.org/wp-content/uploads/20220712172013/Singlelinkedlist.png
    https://media.geeksforgeeks.org/wp-content/uploads/20220901153812/LLdrawio.png


    Linked list Pros and Cons with comparing Arrays:

    Linked List Pros:
        1. Dynamic Size: Linked lists have a dynamic size, 
        meaning they can easily grow or shrink as elements are added or removed. 
        2. This flexibility allows for efficient memory utilization and avoids the need for resizing operations.
        3. Efficient Insertions and Deletions: Insertions and deletions at the beginning or middle of a linked list 
        can be performed in constant time (O(1)) by updating the references, 
        without the need for shifting elements like in an array.
        4. No Memory Wastage: Linked lists do not suffer from the memory wastage that can occur in arrays. 
        They use exactly the amount of memory required for the elements and the node references.

    Linked List Cons:
        1. Sequential Access: Unlike arrays, linked lists do not provide direct or random access to elements. 
        To access a specific element, you need to traverse the list from the beginning,
        which can be less efficient when searching for elements or accessing elements by index.
        2. Additional Memory Overhead: Linked lists require extra memory to store the references 
        (pointers) to the next node, resulting in increased memory overhead compared to arrays.
        3. No Constant-Time Element Access: Finding an element in a linked list requires traversing the list sequentially, 
        potentially leading to slower search operations compared to arrays with direct access by index.   

    Array Pros:
        1. Random Access: Arrays provide direct and constant-time access to elements by their index, 
        allowing for efficient element retrieval.
        2. Cache Friendliness: Arrays have better cache locality since elements are stored contiguously in memory. 
        This can lead to faster access times when accessing adjacent elements.
        3. Compact Memory Representation: Arrays use a compact memory representation, 
        requiring less memory compared to linked lists for storing the same number of elements.
    
    Array Cons:
        1. Fixed Size: Arrays have a fixed size, 
        which means they require resizing or allocation of a new array when the number of elements changes, l
        eading to overhead in terms of time and memory.
        2. Costly Insertions and Deletions: Insertions and deletions in the middle or beginning of an array require shifting elements, 
        resulting in less efficient operations and potentially affecting performance.
        3. Wasted Memory: If the array size is initially larger than needed, 
        memory can be wasted since it is allocated for all elements, regardless of their presence or absence.

    In summary, linked lists are advantageous when frequent insertions and deletions are required, 
    while arrays are more suitable for scenarios where random access and cache efficiency are important. 
    The choice between linked lists and arrays depends on the specific requirements and trade-offs of the application at hand.


    Linked list use cases:
        1. Implementation of Stacks and Queues: Linked lists are commonly used to implement stack and queue data 
        structures due to their efficient insertion and deletion operations at the beginning or end of the list. 
        Each node in the list represents an element in the stack or queue, 
        and the references allow for easy manipulation of the data.

        2. Dynamic Memory Allocation: Linked lists are useful when dynamic memory allocation is required. 
        Since linked lists don't require contiguous memory,
        they can efficiently allocate and deallocate memory as needed, 
        making them suitable for scenarios where the size of the data structure may change frequently.

        3. File Systems: Linked lists can be used to represent file systems.
        Each node in the linked list represents a file or directory, 
        and the references between nodes allow for easy navigation and organization of the file structure.
        4. Music and Video Playlists: Linked lists are often used to implement playlists in music or video players. 
        Each node in the list represents a song or video, 
        and the references between nodes allow for easy traversal and manipulation of the playlist, 
        such as adding, removing, and reordering items.

        5. Symbol Tables: Linked lists can be used in symbol table implementations. 
        Each node contains a key-value pair, and the references allow for efficient lookup, 
        insertion, and deletion of elements in the symbol table.

        6. Polynomial Representation: Linked lists can be used to represent polynomials in mathematics. 
        Each node represents a term in the polynomial, with the data storing the coefficient and exponent of each term.
        
        7. Graph Algorithms: Linked lists are often used in graph algorithms, 
        such as representing adjacency lists for graph traversal. 
        Each node in the linked list represents a neighboring vertex, 
        and the references allow for efficient representation and traversal of the graph.
*/

/*
    Exercise:

    1. Define a struct called Node that represents a single node in the linked list. 
    The struct should have two members: a data member to store the value of the node 
    and a pointer member to point to the next node in the list.

    2. Define a class called LinkedList that represents the linked list itself. 
    The class should have a private member to store the head node pointer.

    3. Implement a constructor for the LinkedList class that initializes the head pointer to nullptr, 
    indicating an empty list.

    4. Implement a member function in the LinkedList class called insert, 
    which takes a value as a parameter and inserts a new node with that value at the beginning of the list.

    5. Implement a member function in the LinkedList class called display, 
    which traverses the linked list and prints the values of all the nodes.

    6. Implement a member function in the LinkedList class called search, 
    which takes a value as a parameter and searches for a node with that value in the list. 
    If found, it should return true; otherwise, it should return false.

    7. Implement a member function in the LinkedList class called remove, 
    which takes a value as a parameter and removes the first occurrence of a node with that value from the list. 
    If the value is not found, it should do nothing.

    8. Implement a member function in the LinkedList class called append, 
    which takes a value as a parameter and adds a new node with that value to the end of the list.

    9. Implement a destructor for the LinkedList class that deletes all the nodes in the list.

    10. Test your implementation by creating an instance of the LinkedList class, inserting several nodes, 
    and then calling the display function to verify that the nodes are correctly inserted and displayed. 
    Test the search, remove, and append functions as well.

    Remember to use the appropriate access specifiers (private, public) to encapsulate the members of the classes properly. 
    This exercise will help you understand how to implement a linked list using OOP principles in C++.
*/


/* Solution */

struct Node{
    int data;       
    Node* next;     

    Node(int val) : data(val), next(nullptr){}
};


class LinkedList{
private:
    Node* head;
    Node* tail;   
    int count;    
public:
    LinkedList() : head(nullptr), tail(nullptr), count(0){}
 
    Node* getHead() {return head;}
    Node* getTail() {return tail;}
 
    LinkedList& insert(int val){
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        if(tail==nullptr){    
            tail=newNode;
        }
        count++;
        return *this;

    }

    LinkedList& display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<"["<<temp->data<<" | "<<temp->next<<"]";
            if (temp->next!=nullptr){
                cout<<" ---> ";
            }
            temp=temp->next;
        }
        cout<<endl;
        return *this;
    }


    bool search(int val){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data == val){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    LinkedList& remove(int val){
        Node* prev=nullptr;
        Node* current=head;

        while(current!=nullptr){
            if(current->data == val){
                if(prev==nullptr){
                    head = current->next;
                if(head==nullptr){
                    tail = nullptr;
                }
            } 
            else{
                prev->next = current->next;
                if(current==tail){
                    tail=prev;
                }
            }
            cout<<"delete on "<<current->data<<endl;
            delete current;
            count--;
            return *this;
        }
        prev=current;
        current=current->next;
    }
    return *this;
}

    LinkedList& append(int val){
        Node* newNode=new Node(val);
        if(!head){
            head=tail=newNode;
        } else {
            tail->next=newNode;
            tail=newNode;
        }
        count++;
        return *this;
    }
 
    bool isEmpty() { return head == nullptr; }


    int size() { return count; }
 
    ~LinkedList(){
        cout<<"\nDestructor: "<<endl;
        Node* temp=head;
        while(temp!=nullptr){
            Node* toDelete = temp;
            cout<<"    delete on "<<toDelete->data<<endl;
            temp=temp->next;
            delete toDelete;
        }
    }
};

int main() {

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

    /*  
        Example Output: 
        
        [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05c90] ---> [3 | 0x7f9092f05ca0] ---> [4 | 0x0] 
        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05c90] ---> [3 | 0x7f9092f05ca0] ---> [4 | 0x0] 

        true

        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05ca0] ---> [4 | 0x0] 
        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x0] 
        [1 | 0x7f9092f05c80] ---> [2 | 0x0] 

        Destructor: 
            delete on 0
            delete on 1
            delete on 2
    */

    return 0;
}