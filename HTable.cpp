//Implementation of the hash table
//Benson Chu

#include "HTable.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//default constructor for hash table
HTable::HTable(unsigned int size){
    usedSize = 0;
    tableSize = size;
    table = new Node*[size];
    hadOccupied = new bool[size];
    for(unsigned int i = 0; i < tableSize; i++){
        table[i] = NULL;
        hadOccupied[i] = false;
    }
}

//hash function that converts string to int
unsigned int HTable::hash(string &value){
    unsigned int index = 0;
    for(unsigned int i = 0; i < value.length(); i++){
        index += (unsigned int) value[i];
    }
    return index % tableSize;
}

//search returns location of object if successful
//otherwise returns false
bool HTable::search(string &value){
    unsigned int index = hash(value);
    while(true){
        if(table[index] == NULL && 
           hadOccupied[index] == false){
            return false;
        }
        else if(table[index] != NULL && table[index]->word == value){
            locationStore = index;
            return true;
        }
        else{
            index = (index + 1) % tableSize;
        }
    }
    return false;
}

void HTable::insert(string &value){
    unsigned int index = hash(value);
    bool foundSpace = false;
    //if word is already in table
    while(!foundSpace){
        if(table[index] != NULL && table[index]->word == value){
    table[index]->count++;
            foundSpace = true;
        }
        else if(table[index] == NULL){
            table[index] = new Node();
            table[index]->word = value;
            table[index]->count = 1;
            hadOccupied[index] = true;
            usedSize++;
            foundSpace = true;
        }
        else{
            index = (index + 1) % tableSize;
        }
    }
}

void HTable::remove(string &value){
    int index = hash(value);
    bool wordFound = false;
    //check first to see if word is in table
    while(!wordFound){
        if(table[index] != NULL && table[index]->word == value){
            if(table[index]->count > 1){
                table[index]->count--;
            }
            else{
                delete table[index];
                table[index] = NULL;
                usedSize--;
            }
            wordFound = true;
        }
        else if(table[index] == NULL){
            return;
        }
        else{
            index = (index + 1) % tableSize;
        }
    }
}

void HTable::sort(string &filePath){
//prints out words lexicographically as list and write them to a file
    vector<string> sortVector;
    for(unsigned int i = 0; i < tableSize; i++){
        if(table[i] != NULL){
            sortVector.push_back(table[i]->word);
        }
    }
    //need to use sort using O(log(n)) algorithm
    ofstream myfile;
    myfile.open(filePath, fstream::app);
    std::sort(sortVector.begin(), sortVector.end());
    for(unsigned int i = 0; i < sortVector.size(); i++){
        myfile << sortVector[i] << endl;
    }
    myfile.close();

}

void HTable::rangeSearch(string &value1, string &value2){
//prints out words between two strings
        for(unsigned int i = 0; i < tableSize; i++){
            if(table[i] != NULL && 
                table[i]->word > value1 && table[i]->word < value2){
        cout << table[i]->word << endl;
            }
        }
    
}

HTable::~HTable(){
    for(unsigned int i = 0; i < tableSize; i++){
        delete table[i];
    }
    delete[] hadOccupied;
    delete[] table;
}



