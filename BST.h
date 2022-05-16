#include <iostream>
#include <string>

struct Node;

class BST {
public:
    using KeyType = int;
    using ItemType = std::string;

    ItemType* lookup(KeyType);
    void insert(KeyType, ItemType);
    void displayEntries();
    void displayTree();
    void remove(KeyType);

    BST() = default; //BST constructor
    ///~BST(); //destructor

private:
    Node* root = leaf();

    static Node* leaf();
    static bool isLeaf(Node*);
    ItemType* lookupRec(KeyType, Node*);
    void insertRec(KeyType, ItemType, Node*&);
    void displayEntriesRec(Node*);
    void displayTreeRec(Node*, std::string);
    void removeRec(KeyType, Node*&);

    //Node* detachMinimumNode(Node*&);
    ///void deepDelete(Node*); //recursive worker performing deep delete
};

struct Node {
    BST::KeyType key;
    BST::ItemType item;
    Node* leftChild;
    Node* rightChild;

    Node(BST::KeyType, BST::ItemType);
};