#include <iostream>

// Node structure (as defined above)
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node into a Binary Search Tree (BST)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // Create a new node if the tree is empty
    }

    if (val < root->data) {
        root->left = insert(root->left, val); // Insert in the left subtree
    } else if (val > root->data) {
        root->right = insert(root->right, val); // Insert in the right subtree
    }
    return root;
}

// Function for in-order traversal (Left -> Root -> Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr; // Initialize an empty tree

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    std::cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // (Further operations like search, deletion, other traversals can be added)

    return 0;
}
