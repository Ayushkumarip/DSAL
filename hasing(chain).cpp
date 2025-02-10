#include <iostream>
using namespace std;

int main() {
    int a[10][2];
    for (int i = 0; i < 10; ++i) {
        a[i][0] = -1;
        a[i][1] = -1;
    }

    int cnt = 0;
    int op;

    while (true) {
        cout << "Operations to perform" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cin >> op;

        if (op == 1) {
            int num_to_insert;
            cout << "How many numbers do you want to insert? ";
            cin >> num_to_insert;

            while (num_to_insert > 0) {
                if (cnt >= 10) {
                    cout << "Hash table is full. Cannot insert more elements." << endl;
                    break;
                }

                cout << "Number> ";
                int a_val;
                cin >> a_val;

                int index = a_val % 10;

                if (a[index][0] == -1) {
                    a[index][0] = a_val;
                    a[index][1] = -1;
                } else {
                    int chain_end = index;
                    while (a[chain_end][1] != -1) {
                        chain_end = a[chain_end][1];
                    }
                    int new_index = (chain_end + 1) % 10;
                    while (a[new_index][0] != -1) {
                        new_index = (new_index + 1) % 10;
                    }
                    a[chain_end][1] = new_index;
                    a[new_index][0] = a_val;
                    a[new_index][1] = -1;
                }
                cnt++;
                num_to_insert--;
            }
        }
        else if (op == 2) {
            cout << "Enter the key to be found: ";
            int key;
            cin >> key;
            int index = key % 10;
            bool found = false;

            while (index != -1) {
                if (a[index][0] == key) {
                    cout << "Key found at index " << index << endl;
                    found = true;
                    break;
                }
                index = a[index][1];
            }

            if (!found) {
                cout << "Key not found" << endl;
            }
        }
        else if (op == 3) {
            cout << "\nHash Table Contents: " << endl;
            bool isEmpty = true;

            for (int i = 0; i < 10; ++i) {
                if (a[i][0] != -1) {
                    cout << "Index " << i << ": " << a[i][0];
                    int next = a[i][1];
                    while (next != -1) {
                        cout << " -> " << a[next][0];
                        next = a[next][1];
                    }
                    cout << endl;
                    isEmpty = false;
                }
            }

            if (isEmpty) {
                cout << "Hash table is empty!" << endl;
            }
            cout << endl;
        }
        else if (op == 4) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid operation. Please try again." << endl;
        }
    }

    return 0;
}
