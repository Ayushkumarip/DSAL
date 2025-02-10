#include<iostream>
#include<math.h>
using namespace std;

class node {
public:
    string word;
    string meaning;
    node *next;
    node(string w, string m) {
        word = w;
        meaning = m;
        next = nullptr;
    }
};

int has(string s) {
    int outp = 0;
    for(int i = 0; i < s.length(); i++) {
        int ascii = s[i];
        outp += ascii * pow(10, i);
    }
    return outp % 7;
}

class dictionary {
    node **dict = new node*[10];
public:
    dictionary() {
        for(int i = 0; i < 10; i++) {
            dict[i] = nullptr;
        }
    }

    void put(string wrd, string mean, int i) {
        node *n = new node(wrd, mean);
        if(dict[i] == nullptr) {
            dict[i] = n;
            return;
        } else {
            n->next = dict[i];
            dict[i] = n;
        }
    }

    void insert() {
        string w, m;
        cout << "Enter word: ";
        cin >> w;
        cout << "Enter meaning: ";
        cin >> m;
        int in = has(w);
        put(w, m, in);
    }

    void search() {
        string w;
        cout << "Enter Word: ";
        cin >> w;
        int in = has(w);
        node *temp = dict[in];
        while(temp != nullptr) {
            if(temp->word == w) {
                cout << "The meaning is: " << temp->meaning << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Word not found" << endl;
    }

    void display() {
        cout << "Dictionary is: " << endl;
        for(int i = 0; i < 10; i++) {
            node *temp = dict[i];
            if(temp==nullptr){
                cout<<"--"<<endl;
            }
            while(temp != nullptr) {
                cout << temp->word << "--" << temp->meaning << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    dictionary dict;
    int ch;
    while(true) {
        cout << "Enter your choice:\n1.Insert word\n2.Search Meaning\n3.Display Dictionary\n4.Exit" << endl;
        cin >> ch;
        if(ch == 1) {
            dict.insert();
        } else if(ch == 2) {
            dict.search();
        } else if(ch == 3) {
            dict.display();
        } else {
            return 0;
        }
    }
    return 0;
}