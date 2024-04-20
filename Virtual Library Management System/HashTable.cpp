//Name: Samuel Etzkorn  
//Description:  CSCI Group Project
//Date:  20APR24
//book.cpp: Hash Table 20 users

#include <iostream>
#include <string>
#include <list>
using namespace std;

// Hash table to store users to access faster

class HashTable{
  private:
    static const int hashGroups = 20;
    list<pair<string, string>> table[hashGroups]; // List 1, Index 0, List 2, Index 1, etc.
  public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const {
  int sum{};
  for(int i{}; i < hashGroups; i++)
    sum += table[i].size();

    if(!sum){
      return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
  return key % hashGroups;
}

void HashTable::insertItem(int key, string value){
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == to_string(key)){
            keyExists = true;
            bItr->second = value;
            cout << "Key exists. Value replaced." << endl;
            break;
        }
    }

    if(!keyExists){
        cell.emplace_back(to_string(key), value);
    }

    return;
}


void HashTable:: removeItem(int key){
  int hashvalue = hashFunction(key);
   auto& cell = table[hashvalue];
  auto bItr = begin(cell);
  bool keyExists = false;
  for(; bItr != end(cell); bItr++){
    if(bItr -> first == to_string(key)){
      keyExists = true;
      bItr = cell.erase(bItr);
      cout << "User removed." << endl;
      break;
    }
  }

  if (!keyExists){
    cout << "User not found." << endl;
  }
  return;
}

void HashTable::printTable(){
  for (int (i)=0; i < hashGroups; i++){
    if(table[i].size() == 0) continue;

    auto bItr = table[i].begin();
    for ( ; bItr != table[i].end(); bItr++){
      cout << "Key: " << bItr -> first << " Value: " << bItr -> second << endl;
    }
  }

  return;
}
int main() {
   HashTable ht;

  if(ht.isEmpty()){
    cout << "Hash table is empty." << endl;
  } else {
    cout << "Hash table is not empty." << endl;
  }

  ht.insertItem(401, "David");
  ht.insertItem(502, "Luct");
  ht.insertItem(803, "Alex");
  ht.insertItem(404, "Jackson");
  ht.insertItem(605, "Emily");
  ht.insertItem(706, "Emma");
  ht.insertItem(807, "Riley");
  ht.insertItem(908, "Sam");
  ht.insertItem(909, "Sammy");
  ht.insertItem(510, "Christine");
  ht.insertItem(411, "Penelope");
  ht.insertItem(312, "Julian");
  ht.insertItem(613, "Oakley");
  ht.insertItem(514, "JJ");
  ht.insertItem(715, "Fredrick");
  ht.insertItem(816, "Marcel");
  ht.insertItem(217, "Nami");
  ht.insertItem(118, "Jack");
  ht.insertItem(319, "Jackie");
  ht.insertItem(420, "Ryan");

  ht. printTable();

  if(ht.isEmpty()){
    cout << "Hash table is not empty." << endl;
  } else {
    cout << "Hash table is full." << endl;
  }    
  return 0;

}