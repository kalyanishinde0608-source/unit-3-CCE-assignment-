#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
};

int height(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

Node* createNode(int key) {
    Node* n = new Node;
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int balanceFactor(Node* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert and balance the BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = balanceFactor(root);

    // LL Case
    if (bf > 1 && key < root->left->key)
        return rightRotate(root);

    // RR Case
    if (bf < -1 && key > root->right->key)
        return leftRotate(root);

    // LR Case
    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Display tree in sorted order
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Identify unbalanced nodes
void checkBalance(Node* root) {
    if (root == NULL)
        return;

    checkBalance(root->left);

    int bf = balanceFactor(root);

    if (bf > 1 || bf < -1)
        cout << "Unbalanced node: " << root->key
             << " (Balance Factor = " << bf << ")\n";

    checkBalance(root->right);
}

int main() {
    Node* root = NULL;
    int choice, key;

    do {
        cout << "\n\n--- DATABASE INDEX MAINTENANCE ---";
        cout << "\n1. Insert Key";
        cout << "\n2. Display Index (Inorder)";
        cout << "\n3. Check Unbalanced Nodes";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter database key: ";
            cin >> key;
            root = insert(root, key);
            cout << "Key inserted and tree balanced.\n";
            break;

        case 2:
            cout << "Database keys: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Checking tree balance...\n";
            checkBalance(root);
            cout << "Check completed.\n";
            break;

        case 4:
            cout << "Exiting application...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
