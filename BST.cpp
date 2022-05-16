#include "BST.h"

Node *BST::leaf() {
    return nullptr;
}

bool BST::isLeaf(Node *n) {
    return (n == nullptr);
}

Node::Node(BST::KeyType newKey, BST::ItemType newItem) {
    this->key = newKey;
    this->item = newItem;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};

BST::ItemType *BST::lookup(KeyType soughtKey) {
    return lookupRec(soughtKey, root);
}

BST::ItemType *BST::lookupRec(KeyType soughtKey, Node *currentNode) {
    if (isLeaf(currentNode)) {
        return nullptr;
    }
    else {
        if (soughtKey < currentNode->key) {
            ItemType* foundItem = lookupRec(soughtKey, currentNode->leftChild);
            return foundItem;
        }
        else if (soughtKey > currentNode->key) {
            ItemType* foundItem = lookupRec(soughtKey, currentNode->rightChild);
            return foundItem;
        }
        else {
            ItemType* foundItem = &currentNode->item;
            return foundItem;
        }
    }
}

void BST::insert(KeyType newKey, ItemType item) {
    insertRec(newKey, item, root);
}



void BST::insertRec(KeyType k, ItemType i, Node *&current) {
    if (isLeaf(current)) {
        current = new Node(k, i);
    }
    else {
        if (k < current->key) {
            insertRec(k, i, current->leftChild);
        }
        else if (k > current->key) {
            insertRec(k, i, current->rightChild);
        }
        else {
            //Replace Item here
            current->item = i;
        }
    }
}

void BST::displayEntries() {
    displayEntriesRec(root);

}

void BST::displayEntriesRec(Node *currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    else {
        std::cout << currentNode->key << ", " << currentNode->item << std::endl;
        displayEntriesRec(currentNode->leftChild);
        displayEntriesRec(currentNode->rightChild);
    }



    //in-order traversal code

    //post-order traversal code
}

void BST::displayTree() {
    std::string tabs = std::string();
    displayTreeRec(root, tabs);
}

void BST::displayTreeRec(Node *currentNode, std::string spaces) {
    if (currentNode == nullptr) {
        std::cout << spaces << " *" << std::endl;
        return;
    }
    else {
        spaces += " ";
        std::cout << spaces << currentNode->key << ", " << currentNode->item << std::endl;
        displayTreeRec(currentNode->leftChild, spaces);
        displayTreeRec(currentNode->rightChild, spaces);
    }
}

void BST::remove(KeyType removeKey) {
    removeRec(removeKey, root);
}

void BST::removeRec(KeyType removeNode, Node *&currentNode) {
    if (isLeaf(currentNode)) {
        return;
    }
    else if (removeNode < currentNode->key) {
        removeRec(removeNode, currentNode->leftChild);
    }
    else if (removeNode > currentNode->key) {
        removeRec(removeNode, currentNode->rightChild);
    }
    else {
        //Both children are leaves
        if (isLeaf(currentNode->leftChild) && isLeaf(currentNode->rightChild)) {
            //delete currentNode;
            currentNode = nullptr;
        }
        //One child is a leaf
        else if (isLeaf(currentNode->leftChild) || isLeaf(currentNode->rightChild)) {
        ///adjust pointer to current Node child and delete the node
            if (isLeaf(currentNode->leftChild)) {
                //*currentNode = *currentNode->rightChild;
                *currentNode->rightChild = *currentNode;
                currentNode = nullptr;
            }
            else if (isLeaf(currentNode->rightChild)) {
                //*currentNode = *currentNode->leftChild;
                *currentNode->leftChild = *currentNode;
                currentNode = nullptr;
            }
        }
        //Neither child is a leaf
        else {

        }
    }
}