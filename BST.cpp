//Implementation of the binary search tree
//Benson Chu

#include "BST.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

BST::BST(){
    root = NULL;
}

void BST::insertHelper(Node*& root, string &value){
    if(root == NULL){
        root = new Node();
        root->left = NULL;
        root->right = NULL;
        root->word = value;
        root->counter = 1;
    }
    else if(value == root->word){
        root->counter++;
        return;
    }
    else if(value < root->word) {
        insertHelper(root->left, value);
    }
    else{
        insertHelper(root->right, value);
    }
}

bool BST::searchHelper(Node*& root, string &value){
    if(root == NULL){
        return false;
    }
    else if(root->word == value){
        return true;
    }
    else if(value <= root->word){
        return searchHelper(root->left, value);
    }
    else{
        return searchHelper(root->right, value);
    }
}

void BST::removeHelper(Node*& root, string &value){
    if(root->word > value){
        removeHelper(root->left, value);
    }
    else if(root->word < value){
        removeHelper(root->right, value);
    }
    else{
        if(root->counter > 1){
            root->counter--;
        }
        else{
            removeNode(root);
        }
    }
}
void BST::removeNode(Node*& root){
    string value;
    Node* temp = root;
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
        findMinHelper(root->right, value);
        root->word = value;
        removeHelper(root->right, value);
    }
}

void BST::findMinHelper(Node* root, string &value){
    while(root->left != NULL){
        root = root->left;
    }
        value = root->word;
}

void BST::sort(string &filePath){
    ofstream myfile;
    myfile.open(filePath);
    sorter(root, myfile);
    myfile.close();
}

void BST::sorter(Node* root, ofstream& myfile){
    if(root != NULL){
    sorter(root->left, myfile);
    myfile << root->word << "ree" << endl;
    sorter(root->right, myfile);
    }
}

void BST::rangeSearchHelper(Node* root, string &value1, string &value2){
    if(root == NULL){
        return;
    }
    if(value1 < root->word){
        rangeSearchHelper(root->left, value1, value2);
    }
    if(value1 < root->word && value2 > root->word){
        cout << root->word << endl;
    }
    if(value2 > root->word){
        rangeSearchHelper(root->right, value1, value2);
    }

    
}

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
