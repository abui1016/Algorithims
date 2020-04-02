#include <iostream>
#include <list>

using namespace std;

class Hash {
       private: 
              list<int> *hashTable;
       public:
              Hash() {
                     hashTable = NULL;
              };

              ~Hash() {
                     if(hashTable != NULL) {
                            delete[] hashTable;
                     }
              }

              void makeTable(int m) {
                     hashTable = new list<int>[m];
              }

              void insert(int k, int m) {
                     hashTable[k%m].push_front(k);
              }

              void search(int k, int m) {
                     list<int> newList = hashTable[k%m];
                     list<int>::iterator iter;
                     int index = 0;

                     if(newList.empty()) {
                            cout << k << ":NOT_FOUND;" << endl;
                     } else {
                            for(iter = newList.begin(); iter != newList.end(); iter++) { // beginning to end of list
                                   if(*iter == k) {
                                          cout << k << ":FOUND_AT" << (k%m) << "," << index << ";" << endl;
                                          return;
                                   }
                                   index++; 
                            }
                            cout << k << ":NOT_FOUND;" << endl; 
                     }
              }
              
              bool remove(int k, int m) {
                     list<int> newList = hashTable[k%m];
                     list<int>::iterator iter;
                     if(newList.empty()) {
                            return false;
                     } else {
                            for(iter = newList.begin(); iter != newList.end(); iter++) {
                                   if(*iter == k) {
                                          newList.erase(iter);
                                          hashTable[k%m] = newList;
                                          return true;
                                   }
                            }
                     }
                     return false;
              }
              void print(int m) {
                     list<int> newList;
                     list<int>::iterator iter;

                     for(int i = 0; i < m; i++) {
                            newList = hashTable[i];
                            if(newList.empty()) {
                                   cout << i << ":";
                            } else {
                                   cout << i << ":";
                                   for(iter = newList.begin(); iter != newList.end(); ++iter) {
                                          cout << *iter << "->";
                                   }
                            }
                            cout << ";" << endl;
                     }
              }
};

int main(int argc,char **argv) {

       int k, m; // k = key, m = size
       char op; // operation
       cin >> m;
       Hash hash;
       hash.makeTable(m); // make a table of size m
       cin >> op;

       while(op != 'e') {
              if(op == 'i') {
                     cin >> k;
                     hash.insert(k, m);
              } else if(op == 'd') {
                     cin >> k;
                     if(hash.remove(k, m)) {
                            cout << k << ":DELETED;" << endl;
                     } else {
                            cout << k << ":DELETE_FAILED;" << endl;
                     }
              } else if(op == 's') {
                     cin >> k;
                     hash.search(k, m);
              } else if(op == 'o') {
                     hash.print(m);
              }
              cin >> op;
       }
       return 0;
}