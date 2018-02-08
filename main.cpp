//File that reads input and compares the running times of BST and Hash Tables
//Benson Chu
#include "BST.h"
#include "HTable.h"
#include <iostream>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    string word;
    int counter;
};
int main(){
    string listNames[10] = {"ree", "eer", "a", 
                            "b", "c", "ree", 
                            "z", "b", "wow"};
    BST testBST;
    Node* root = new Node();
    HTable testHTable(10);
    for(int i = 0; i < 10; i++){
        testBST.insert(root, listNames[i]);
        testHTable.insert(listNames[i]);
    }

    
}
