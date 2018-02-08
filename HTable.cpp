//Implementation of the hash table
//Benson Chu

#include "HTable.h"
using namespace std;

//default constructor for hash table
HTable::Htable(unsigned int size){
    hTable = new HTable[size];
    isOccupized = new isOccupied[size];
    for(unsigned int i = 0; i < size; i++){
        hTable[i] = null;
        isOccupied[i] = false;
    }
}

//hash function that converts string to int key
unsigned int HTable::hash(string &value){
    int index;
    for(int i = 0; i < value.length; i++){
        //find clever way to effectively hash
    }
}

//search returns location of object if successful
//otherwise returns 0
int HTable::search(string &value){
    int index = HTable::hash(value);
    bool objectFound = false;
    while(!objectFound){
        if(hTable[index] == null && 
           hadOccupied == false){
            return 0;
        }
        else if(hTable[index]->word == value){
            objectFound = true;
        }
        else{
            if(index == hTable.length - 1){
                index = 0;
            }
            index++;
        }
    }
    return index;
}


void HTable::insert(string &value){
    int index;
    bool foundSpace = false;
    if(HTable::search(value)){
        hTable[HTable::search(value)]->count++;
    }
    else{
        index = hash(value);
        while(!foundSpace){
            if(hTable[index] == null){
                hTable[index] = new Node();
                hTable[index]->word = value;
                hTable[index]->count = 1;
                hadOccupied[index] = true;
                foundSpace = true;
            }
            else{
                if(index == hTable.length - 1){
                    index = 0;
                }
                index++;
            }
        }
    }
}

bool HTable::remove(string &value){
    int index;
    bool foundString = false;
    if(HTable::search(value)){
        index = HTable::search(value);
        if(hTable[index]->count > 1){
            count--;
            return true;
        }
        else{
            delete hTable[index];
            hTable[index] = null;
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

}
