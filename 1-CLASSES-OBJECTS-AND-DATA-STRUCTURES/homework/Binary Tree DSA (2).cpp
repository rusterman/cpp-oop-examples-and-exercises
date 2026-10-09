#include <iostream>
#include <iomanip>
#include <math.h>
 
using namespace std;

/*
    1. Preorder, Inorder, Postorder traversals using numbers
    2. Tree common operations (insert, search, traverse, delete node)
    3. Tree traversals (preorder, inorder, postorder, level order)
    4. Identify mistakes in using recursion where it can be avoided (no need for insertion, no need for node deletion).
    5. Tree Complexity
    6. Applications
    7. What about Heap Data Structure (DSA)?

    Tree Traversal Source:    https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
    Insert Node Source:       https://www.javatpoint.com/insertion-in-binary-search-tree
    Delete Node Source:       https://www.interviewbit.com/blog/delete-node-from-binary-search-tree/
    Binary Tree Applications: https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-binary-tree/

*/
class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        else return search(node->right, val);
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) { root = insert(root, val); }
    bool search(int val) { return search(root, val); }
    void deleteNode(int val) { root = deleteNode(root, val); }

    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }

    void levelorder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};

struct Node {
    int data;
    Node *left;
    Node *right;
};


class BinaryTree {
    private:
        int height;
        Node *root;

        // method utilities
        void printTree(const vector<const Node *const> &) const;
        void destroyTree(const Node *const);

    public:
        BinaryTree();
        ~BinaryTree();

        BinaryTree& insert(const int &);

        void display() const;

        void preorder(const Node *) const;    // Root -> Left -> Right 
        void inorder(const Node *) const;     // Left -> Root -> Right
        void postorder(const Node *) const;   // Left -> Right -> Root

        void levelorder() const;

        bool search(const int &) const;
        void deleteNode(const int &);
};

/* Your Solution */



int main() {

    BinaryTree tree = BinaryTree();

    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(12);
    tree.insert(30);
    tree.insert(60);
    tree.insert(85);

    cout << "Search 30: " << (tree.search(30) ? "Found" : "Not Found") << endl;

    tree.deleteNode(30);

    cout << endl;
    tree.display();  

    // Ex-1: tree.insert(5).insert(3).insert(8).insert(6).insert(2).insert(4).insert(9).insert(7);
    // Ex-2: https://www.javatpoint.com/insertion-in-binary-search-tree
    tree.insert(50).insert(25).insert(75).insert(12).insert(30).insert(60).insert(85).insert(52).insert(70);
    // Ex-3: tree.insert(2).insert(1).insert(33).insert(0).insert(25).insert(40).insert(11).insert(34).insert(7).insert(12).insert(36).insert(13);

    cout << endl;
    tree.display();  
    cout << endl;

    cout << (tree.search(13) ? "[13 found]" : "[13 not found]") << endl << endl;

    tree.deleteNode(52);
    tree.deleteNode(70);

    cout << endl;
    tree.display();  
    cout << endl;

    // Tree traversals (preorder, inorder, postorder, levelorder)
    cout << "Preorder:   ";
    tree.preorder();
    cout << endl;

    cout << "Inorder:    ";
    tree.inorder();
    cout << endl;

    cout << "Postorder:  ";
    tree.postorder();
    cout << endl;

    cout << "Levelorder: " << endl;
    tree.levelorder();
    cout << endl;
  
  
  	/*
    	------------------------ Output	------------------------
        
        Tree is empty

        Tree height: 3

                            50

                     25             75

               12       30       60       85

                               52   70          

        [13 not found]

        Leaf Node: 52
        Leaf Node: 70

        Tree height: 2

                       50

                 25         75

             12     30     60     85

        Preorder:   50 -> 25 -> 12 -> 30 -> 75 -> 60 -> 85
        Inorder:    12 -> 25 -> 30 -> 50 -> 60 -> 75 -> 85
        Postorder:  12 -> 30 -> 25 -> 60 -> 85 -> 75 -> 50
        Levelorder: 
        Tree height: 2

                       50

                 25         75

             12     30     60     85

        [call of destructor]
         Delete: 12
         Delete: 30
         Delete: 25
         Delete: 60
         Delete: 85
         Delete: 75
         Delete: 50
    */

    return 0;
}