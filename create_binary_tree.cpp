#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Find inorder successor (left-most node in right subtree)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// BST Insert
Node* BST_Insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = BST_Insert(root->left, val);
    else if (val > root->data)
        root->right = BST_Insert(root->right, val);
    // duplicate ignored

    return root;
}

// BST Search
Node* BST_Search(Node* root, int val) {
    while (root != NULL) {
        if (root->data == val)
            return root;
        else if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// BST Delete
Node* BST_Delete(Node* root, int val) {
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = BST_Delete(root->left, val);
    else if (val > root->data)
        root->right = BST_Delete(root->right, val);
    else {
        // Node found
        // CASE-A: Leaf node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // CASE-A: One child
        else if (root->left == NULL) { // only right child
            Node* tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
        else if (root->right == NULL) { // only left child
            Node* tmp = root;
            root = root->left;
            delete tmp;
            return root;
        }
        // CASE-B: Two children
        Node* succ = minValueNode(root->right); // inorder successor
        root->data = succ->data;                // replace value
        root->right = BST_Delete(root->right, succ->data); // delete successor
    }

    return root;
}

// Preorder Traversal: Root, Left, Right
void PreOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// Inorder Traversal: Left, Root, Right
void InOrder(Node* root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// Postorder Traversal: Left, Right, Root
void PostOrder(Node* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // BST Insert
    root = BST_Insert(root, 50);
    root = BST_Insert(root, 30);
    root = BST_Insert(root, 70);
    root = BST_Insert(root, 20);
    root = BST_Insert(root, 40);
    root = BST_Insert(root, 60);
    root = BST_Insert(root, 80);

    cout << "BST Inorder Traversal (sorted): ";
    InOrder(root);
    cout << endl;

    // BST Search
    int key = 30;
    Node* found = BST_Search(root, key);
    if (found != NULL)
        cout << "✅ Value " << key << " FOUND in BST\n";
    else
        cout << "❌ Value " << key << " NOT FOUND in BST\n";

    // BST Delete leaf
    root = BST_Delete(root, 20);
    cout << "After deleting leaf 20: ";
    InOrder(root);
    cout << endl;

    // BST Delete node with one child
    root = BST_Delete(root, 30);
    cout << "After deleting node 30 with one child: ";
    InOrder(root);
    cout << endl;

    // BST Delete node with two children (root)
    root = BST_Delete(root, 50);
    cout << "After deleting root 50 with two children: ";
    InOrder(root);
    cout << endl;

    // BST Insert new node
    root = BST_Insert(root, 100);
    cout << "After inserting 100: ";
    InOrder(root);
    cout << endl;

    // Traversals
    cout << "Preorder Traversal: ";
    PreOrder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    PostOrder(root);
    cout << endl;

    return 0;
}
