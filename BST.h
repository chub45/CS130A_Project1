//Header file for the binary search tree
//Benson Chu

#ifndef BST_H
#define BST_H
#include <string>
#include <fstream>
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
void insert(std::string &value){insertHelper(root, value);}
bool search(std::string &value){return searchHelper(root, value);}
void remove(std::string &value){removeHelper(root, value);}
void sort();
void rangeSearch(std::string &value1, std::string &value2){rangeSearchHelper(root, value1, value2);}
//destructor
~BST();



private:
Node* root;
//Helper methods for traversing recursively
void insertHelper(Node*& root, std::string &value);
bool searchHelper(Node*& root, std::string &value);
void removeHelper(Node*& root, std::string &value);
void removeNode(Node*& root);
void findMinHelper(Node* root, std::string &value);
void sorter(Node* root, std::ofstream &myfile);
void rangeSearchHelper(Node* root, std::string &value1, std::string &value2);
void Delete(Node*& root);
};
#endif
