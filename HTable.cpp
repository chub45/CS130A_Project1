//Implementation of the hash table
//Benson Chu

#include "HTable.h"
#include <cassert>
using namespace std;

//default constructor for hash table
HTable::HTable(unsigned int size){
    tableSize = size;
    table = new Node*[size];
    hadOccupied = new bool[size];
    for(unsigned int i = 0; i < tableSize; i++){
        table[i] = NULL;
        hadOccupied[i] = false;
    }
}

//hash function that converts string to int key
unsigned int HTable::hash(string &value){
    int index;
//    for(int i = 0; i < value.length; i++){
        //find clever way to effectively hash
  //  }
  return 1;
}

//search returns location of object if successful
//otherwise returns 0
int HTable::search(string &value){
    unsigned int index = HTable::hash(value);
    bool objectFound = false;
    while(!objectFound){
        if(table[index] == NULL && 
           hadOccupied == false){
            return 0;
        }
        else if(table[index]->word == value){
            objectFound = true;
        }
        else{
            index++;
            if(index == tableSize){
                index = 0;
            }
        }
    }
    return index;
}


void HTable::insert(string &value){
    unsigned int index;
    bool foundSpace = false;
    if(HTable::search(value)){
        table[HTable::search(value)]->count++;
    }
    else{
        index = hash(value);
        while(!foundSpace){
            if(table[index] == NULL){
                table[index] = new Node();
                table[index]->word = value;
                table[index]->count = 1;
                hadOccupied[index] = true;
                foundSpace = true;
            }
            else{
                index++;
                if(index == tableSize){
                    index = 0;
                }
            }
        }
    }
}

bool HTable::remove(string &value){
    int index;
    if(HTable::search(value)){
        index = HTable::search(value);
        if(table[index]->count > 1){
            table[index]->count--;
            return true;
        }
        else{
            delete table[index];
            table[index] = NULL;
            return true;
        }
    }
    else{
        return false;
    }
}

void HTable::sort(){
//prints out words lexicographically as list    
}

void rangeSearch(string &value1, string &value2){
//prints out words between two strings
}

HTable::~HTable(){
    for(unsigned int i = 0; i < tableSize; i++){
        delete table[i];
    }
    delete[] table;
}



