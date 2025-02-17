#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
 

class HashTable {
private:
    vector<list<string>> table;  
 
    
    int hashFunction(const string& word) {
        int hash = 0;
        int i =0;
        int n = word.size();
        for (char c : word) {
            hash = hash + int(c)*(pow(10,n-i-1));
            i++;
        }
        
        return hash%10;
    }
 
public:
    
    HashTable(int size) {
        table.resize(size);
    }
 
    
    void insert(const string& word) {
        int index = hashFunction(word);
        table[index].push_back(word);  
    }
 
    
    bool search(const string& word) {
        int index = hashFunction(word);
        for (const string& w : table[index]) {
            if (w == word) {
                return true;  
            }
        }
        return false;  
    }
 
    
    void display() {
        for (int i = 0; i < table.size(); ++i) {
            cout << "Bucket " << i << ": ";
            for (const string& word : table[i]) {
                cout << word << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};
 
int main() {
    HashTable hashTable(10);  
    string menu ="Enter your choice: \n1. Add\n2. Display\n3. Exit";
    int opt;
    string key;
    do
    {
        cout<<menu<<endl;
        cout<<"Your choice: ";
        cin>>opt;
        switch (opt)
        {
            case 1:
                cout<<"\nEnter the element: ";
                cin>>key;
                hashTable.insert(key);
                break;
            case 2:
                hashTable.display();
                break;
            case 3:
                exit(0);
            default:
                cout<<"\n Please enter a correct option"<< endl;
                break;
        }
    } while (true);
    return 0;
}