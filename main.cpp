//File that reads input and compares the running times of BST and Hash Tables
//Benson Chu
#include "BST.h"
#include "HTable.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;
int main(){
    string listNames[10] = {"ree", "eer", "a", 
                            "b", "c", "ee", 
                            "z", "b", "wow", "reee"};
    /*for(auto& p: fs::recursive_directory_iterator("hotels")){
        cout << p.path();
    }*/

    BST testBST;
    unsigned int x = 10;
    string input = "";
    HTable testHTable(x);
   // cout << "This passed" << endl;
    for(int i = 0; i < 10; i++){
        testBST.insert(listNames[i]);
        testHTable.insert(listNames[i]);
    }

    do{
        getline(cin, input);
        stringstream store(input);
        int command = 0;
        store >> command;
        switch(command){
            //perform search function
    case 1: 
    {        string input = "";
            cin >> input;
            int start_b = clock();
            testBST.search(input);
            int stop_b = clock();
            int start_h = clock();
            testHTable.search(input);
            int stop_h = clock();
            if(testHTable.search(input) == testBST.search(input)){
            cout << boolalpha <<testHTable.search(input) << endl;
            cout << "BST: " << (stop_b - start_b)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << "Hash: " << (stop_h - start_h)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << endl;
            }
    }
            break;
            //perform insert function
    case 2: 
    {       string input2;
            cin >> input2;
            int start2_b = clock();
            testBST.insert(input2);
            int stop2_b = clock();
            int start2_h = clock();
            testHTable.insert(input2);
            int stop2_h = clock();
            cout << "BST: " << (stop2_b - start2_b)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << "Hash: " << (stop2_h - start2_h)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << endl;
            break;
    }
            //perform delete function
    case 3: 
    {       string input3 = "";
            cin >> input3;
            int start3_b = clock();
            testBST.remove(input3);
            int stop3_b = clock();
            cout << "BST runs" << endl;
            int start3_h = clock();
            testHTable.remove(input3);
            int stop3_h = clock();
            cout << "BST: " << (stop3_b - start3_b)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << "Hash: " << (stop3_h - start3_h)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << endl;
            break;
    }
            //perform sort function, reads in file to be written to
    case 4: 
    {       string input4 = "";
            cin >> input4;
            int start4_b = clock();
            testBST.sort(input4);
            int stop4_b = clock();
            int start4_h = clock();
            testHTable.sort(input4);
            int stop4_h = clock();

            cout << "BST: " << (stop4_b - start4_b)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << "Hash: " << (stop4_h - start4_h)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << endl;
            break;
    }
            //perform range search function, requires 2 integer inputs
    case 5: 
    {       string rangeMin = "", rangeMax = "";
            cin >> rangeMin >> rangeMax;
            int start5_b = clock();
            testBST.rangeSearch(rangeMin, rangeMax);
            int stop5_b = clock();
            cout << endl;
            int start5_h = clock();
            testHTable.rangeSearch(rangeMin, rangeMax);
            int stop5_h = clock();

            cout << "BST: " << (stop5_b - start5_b)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << "Hash: " << (stop5_h - start5_h)/double(CLOCKS_PER_SEC)*1000 << "s" << endl;
            cout << endl;
            break;
    }
        }
    }
    while(true);
    
}
