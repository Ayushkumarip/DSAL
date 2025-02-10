#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    
    // Constructor to initialize node
    node() {
        left = nullptr;
        right = nullptr;
        data = 0;
    }

    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node into the binary tree
void insert(node*& root, int val) {
    node* p = new node(val);
    if (root == nullptr) {
        root = p;  // If tree is empty, set the root
    } else {
        node* temp = root;
        while (true) {
            cout << "1. For Left Insert of " << temp->data << endl;
            cout << "2. For Right Insert of " << temp->data << endl;
            int c;
            cout << "Enter your choice: ";
            cin >> c;

            if (c == 1) {
                if (temp->left == nullptr) {
                    temp->left = p;
                    break;
                } else {
                    temp = temp->left;  // Move to the left child
                }
            } else if (c == 2) {
                if (temp->right == nullptr) {
                    temp->right = p;
                    break;
                } else {
                    temp = temp->right;  // Move to the right child
                }
            } else {
                cout << "Invalid choice! Please choose either 1 or 2." << endl;
            }
        }
    }
}

// Inorder Traversal (Recursive)
void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder Traversal (Recursive)
void postorder(node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Preorder Traversal (Recursive)
void preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Level-order traversal using a queue (non-recursive)
void levelOrder(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// Function to clone a binary tree
node* clone(node* root) {
    if (root == nullptr) return nullptr;

    node* newNode = new node(root->data);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    
    return newNode;
}

// Function to check if two trees are equal
bool areEqual(node* root1, node* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;
    
    return (root1->data == root2->data) && 
           areEqual(root1->left, root2->left) && 
           areEqual(root1->right, root2->right);
}

// Function to create a mirror image of the tree
void mirror(node* root) {
    if (root == nullptr) return;

    swap(root->left, root->right);  // Swap left and right subtrees

    mirror(root->left);  // Recursively mirror left subtree
    mirror(root->right); // Recursively mirror right subtree
}

// Function to insert a node into a Binary Search Tree (BST)
node* insertBST(node* root, int val) {
    if (root == nullptr) return new node(val);
    
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Function to create a Binary Search Tree (BST)
node* createBST() {
    node* root = nullptr;
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 20);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 15);
    root = insertBST(root, 30);
    
    return root;
}

// Main function
int main() {
    node* root = nullptr;
    int n;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;
    while (true) {
        const char *str = "          Menu\n\
                    1.  Create Binary Tree\n\
                    2.  Preorder (Recursive)\n\
                    3.  Postorder (Recursive)\n\
                    4.  Inorder (Recursive)\n\
                    5.  Level Order\n\
                    6.  Make a clone\n\
                    7.  Check if two trees are equal\n\
                    8.  Create mirror image\n\
                    9.  Create Binary Search Tree\n\
                    10. Delete node from BST\n\
                    11. Construct BST from preorder & postorder\n\
                    12. Find height of tree";

        int ch;
        cout << str;
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter values to insert into the binary tree:" << endl;
                for (int i = 0; i < n; i++) {
                    int val;
                    cout << "Enter value " << (i + 1) << ": ";
                    cin >> val;
                    insert(root, val);
                }
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Level Order Traversal: ";
                levelOrder(root);
                cout << endl;
                break;
            case 6: {
                node* clonedRoot = clone(root);
                cout << "Cloned Tree Preorder Traversal: ";
                preorder(clonedRoot);
                cout << endl;
                break;
            }
            case 7: {
                node* clonedRoot = clone(root);
                cout << "Are the trees equal? " << (areEqual(root, clonedRoot) ? "Yes" : "No") << endl;
                break;
            }
            case 8:
                mirror(root);
                cout << "Mirror Image (Inorder Traversal): ";
                inorder(root);
                cout << endl;
                break;
            case 9: {
                node* bstRoot = createBST();
                cout << "BST Inorder Traversal: ";
                inorder(bstRoot);
                cout << endl;
                break;
            }
            case 10:
                cout << "Delete node functionality not yet implemented!" << endl;
                break;
            case 11:
                cout << "Construct BST from preorder & postorder not yet implemented!" << endl;
                break;
            case 12:
                cout << "Find height of tree functionality not yet implemented!" << endl;
                break;
            default:
                cout << "Invalid choice! Exiting program." << endl;
                return 0;
        }
    }
}
