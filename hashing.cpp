#include <iostream>
using namespace std;

int main() {
    int hashtab[10];  
    for (int i = 0; i < 10; ++i) {
        hashtab[i] = -1;  // Initialize the hash table with -1 (indicating empty slots)
    }
 
    int cnt = 0;  // Counter to track the number of elements inserted
    int op;  // Variable to store the user's choice of operation
 
    while (true) {
        // Menu for the user to choose an operation
        cout << "Operations to perform" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cin >> op;
 
        if (op == 1) {  // Insert operation
            int num_to_insert;
            cout << "How many numbers do you want to insert? ";
            cin >> num_to_insert;

            bool insert_more = true;
            while (num_to_insert > 0) {
                if (cnt >= 10) {
                    cout << "Hash table is full. Cannot insert more elements." << endl;
                    break;
                }
 
                cout << "Number> ";
                int a;
                cin >> a;
 
                int ind = a % 10;  // Hash function (modulo 10 to fit in array of size 10)
                if (hashtab[ind] == -1) {
                    hashtab[ind] = a;  // Directly insert if the slot is empty
                } else {
                    int original_ind = ind;
                    // Collision resolution via linear probing
                    while (hashtab[ind] != -1) {  
                        ind = (ind + 1) % 10;
                        if (ind == original_ind) {
                            cout << "Hash table is full. Cannot insert." << endl;
                            break;
                        }
                    }
                    if (hashtab[ind] == -1) {
                        hashtab[ind] = a;  // Insert at the empty slot found by probing
                    }
                }
                cnt++;
                num_to_insert--;  // Decrease the number of remaining numbers to insert
            }
        }
        else if (op == 2) {  // Find operation
            cout << "Enter the key to be found: ";
            int key;
            cin >> key;
            int idx = key % 10;  // Hash the key using modulo 10
 
            if (hashtab[idx] == key) {
                cout << "Key found at index " << idx << endl;
            } else {
                int original_idx = idx;
                while (hashtab[idx] != -1) {
                    if (hashtab[idx] == key) {
                        cout << "Key found at index " << idx << endl;
                        break;
                    }
                    idx = (idx + 1) % 10;  // Linear probing
                    if (idx == original_idx) {
                        break;
                    }
                }
                if (hashtab[idx] != key) {
                    cout << "Key not found" << endl;
                }
            }
        }
        else if (op == 3) {  // Display operation
            cout << "\nHash Table Contents: " << endl;
            bool isEmpty = true;  // To check if the table is completely empty

            // Loop over the table and only display the indices that have been filled
            for (int i = 0; i < 10; ++i) {
                if (hashtab[i] != -1) {  // Only display non-empty indices
                    cout << "Index " << i << ": " << hashtab[i] << endl;
                    isEmpty = false;
                }
            }

            // If no element has been inserted, show a message indicating the table is empty
            if (isEmpty) {
                cout << "Hash table is empty!" << endl;
            }
            cout << endl;
        }
        else if (op == 4) {  // Exit operation
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid operation. Please try again." << endl;
        }
    }
 
    return 0;
}
