//Header file for the hash table
//Benson Chu

#ifndef HTABLE_H
#define HTABLE_H
#include <string>

class HTable{
private:
struct Node{
    std::string word;
    int count;
};
public:
//constructor
HTable(unsigned int size);
//other methods
unsigned int hash(std::string &value);
bool search(std::string &value);
void insert(std::string &value);
void remove(std::string &value);
void sort(std::string &filePath);
void rangeSearch(std::string &value1, std::string &value2);
//destructor
~HTable();

private:
Node** table;
bool* hadOccupied;
unsigned int tableSize;
unsigned int usedSize;
unsigned int locationStore;
};


#endif
