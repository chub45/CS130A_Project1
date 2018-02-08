//Header file for the binary search tree
//Benson Chu

#ifndef BST_H
#define BST_H
#include <string>

class BST{
private:
struct Node{
    Node *left;
    Node *right;
    int counter;
    std::string word;
};
public:
//constructor
BST();
//Other methods
void insert(Node*& root, std::string &value);
bool search(Node*& root, std::string &value);
void remove(Node*& root, std::string &value);
void removeNode(Node*& root); //remove helper
void findMin(Node*& root, std::string &value);
void sort();
void rangeSearch(std::string &value1, std::string &value2);
//const Node* getRoot();
void Delete(Node*& root); //destructor helper
//destructor
~BST();



private:
Node* root;

};
#endif
