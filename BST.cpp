//Implementation of the binary search tree
//Benson Chu

#include "BST.h"
#include <cassert>
#include <iostream>
using namespace std;

BST::BST(){
    root = NULL;
}

void BST::insert(Node*& root, string &value){
    if(root == NULL){
        root = new Node();
        root->left = NULL;
        root->right = NULL;
        root->word = value;
        root->counter = 1;
    }
    else if(value == root->word){
        root->counter++;
    }
    else if(value < root->word) {
        root->left = insert(value);
    }
    else{
        root->right = insert(value);
    }
}

bool BST::search(Node*& root, string &value){
    if(root == NULL){
        return false;
    }
    else if(root->word == value){
        return true;
    }
    else if(value <= root->word){
        search(root->left, value);
    }
    else{
        search(root->right, value);
    }
}

void BST::remove(Node*& root, string &value){
    if(root->word < value){
        remove(root->left, value);
    }
    else if(root->word > value){
        remove(root->right, value);
    }
    else{
        if(root->counter > 1){
            counter--;
        }
        else{
            removeNode(root);
        }
    }
}
void BST::removeNode(Node*& root){
    Node* temp = root;
    string value;
    if(root->left == NULL){
        root = root->right;
        delete temp;
    }
    else if(root->right == NULL){
        root = root->left;
        delete temp;
    }
    else{
        //find minimum of right subtree
        BST::findMin(root->right, value);
        root->word = value;
        BST::remove(root->right, value);
    }
}

void BST::findMin(Node*& root, string &value){
    while(root->left != NULL){
        root = root->left;
        value = root->value;
    }
}

void sort(){
    while(root != NULL){
        sort(root->left);
        cout << root->word << " ";
        sort(root->right);
    }
}
void BST::rangeSearch(string &value1, string &value2){
    if(root == null){
        return;
    }
    if(value1 <= root->word){
        rangeSearch(root->left, value1, value2);
    }
    if(value1 <= root->word && value2 >= root->word){
        cout << root->word << " ";
    }
    if(value2 >= root->word){
        rangeSearch(root->right, value1, value2);
    }
}
/*const Node* BST::getRoot(){
    return root;
}*/
void BST::Delete(Node*& root){
    if(root != NULL){
        Delete(root->left);
        Delete(root->right);
        delete root;
    }
}
BST::~BST(){
    Delete(root);
}
