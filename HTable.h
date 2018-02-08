//Header file for the hash table
//Benson Chu

#ifndef HTABLE_H
#define HTABLE_H

class HTable{
public:
//constructor
HTable(unsigned int size);
//other methods
unsigned int hash(std::string &value);
int search(std::string &value);
void insert(std::string &value);
bool remove(std::string &value);
void sort();
void rangeSearch(std::string &value1, std::string &value2);
//destructor
~HTable();

private:
struct Node{
    std::string word;
    int count;
};

Node* hTable;
bool* hadOccupied;
};


#endif
