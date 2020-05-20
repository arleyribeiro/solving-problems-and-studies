#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left = NULL;
    node *right = NULL;
};

class Tree {
    public:
    struct node *root;
    Tree() {
        root = NULL;
    }

    bool isEmpty() {
        return root == NULL;
    }
    void insert(int data);
    void inOrder(struct node *node);
    void preOrder(struct node *node);
    void posOrder(struct node *node);
};

void Tree::insert(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (isEmpty()) {
        root = newNode;
    } else {
        node *ptr = new node;
        ptr = root;
        node *parent;
        while(ptr != NULL) {
            parent = ptr;
            if (data < ptr->data) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

void Tree::inOrder(node *node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void Tree::posOrder(node *node) {
    if (node == NULL) {
        return;
    }
    posOrder(node->left);
    posOrder(node->right);
    cout << node->data << " ";
}

void Tree::preOrder(node *node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    Tree tree;
    tree.insert(6);
    tree.insert(3);
    tree.insert(10);
    tree.insert(2);
    tree.insert(5);
    cout << "inorder: "; 
    tree.inOrder(tree.root);
    cout << endl;
    cout << "preOrder: "; 
    tree.preOrder(tree.root);
    cout << endl;
    cout << "posOrder: "; 
    tree.posOrder(tree.root);
    cout << endl;
    return 0;
}