#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int TABLE_SIZE = 10;

struct Node {
    string key;
    string value;
    Node* next;

    Node(const string& k, const string& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    vector<Node*> table;

    static long
    ComputeHashCode(const string& key) {
        long hash = 0;
        for (const char& c : key) {
            hash = hash * 31 + c;
        }
        return hash;
    }

    static int
    getIndex(const string& key) {
        const long hash = ComputeHashCode(key);
        return abs(hash) % TABLE_SIZE;
    }

public:
     HashTable() {
         table.resize(TABLE_SIZE, nullptr);
     }

    void
    insert(const string& key, const string& val) {
         const int index = getIndex(key);

         const auto newNode = new Node(key, val);

         if (!table[index]) {
             table[index] = newNode;
         } else {
             newNode->next = table[index];
             table[index] = newNode;
         }
     }


    void printTable() const {
         for (uint8_t i=0; i < TABLE_SIZE; ++i) {
             cout << "[" << i << "]:";
             auto* current = table[i];

             while (current) {
                 cout << current->key << ": " << current->value << ") ->";
                 current = current->next;
             }

             cout << "nullptr\n";

         }
     }


   ~HashTable() {
         for (uint8_t i=0; i < TABLE_SIZE; ++i) {
             auto* current = table[i];
             while (current) {
                 auto* temp = current;
                 current = current->next;
                 delete temp;

             }
         }
     }





};








int main() {
    HashTable ht;
    ht.insert("apple", "red");
    ht.insert("banana", "yellow");
    ht.insert("cherry", "red");
    ht.insert("grape", "purple");
    ht.insert("lemon", "yellow");
    ht.insert("plum", "purple");

    ht.printTable();
    return 0;
}
