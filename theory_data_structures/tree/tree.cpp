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
    void remove(int data);
    void inOrder(node *root);
    void preOrder(node *root);
    void posOrder(node *root);
    void transversalOrder(node *root);

    private:
        node* removeNode(int data, node * root);
        node* minNodeValue(node * root);
};

void Tree::insert(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (isEmpty()) {
        root = newNode;
    } else {
        node *ptr = root;
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

void Tree::remove(int data) {  
    removeNode(data, root);
}

node * Tree::minNodeValue(node *root) {
    node *current = root;
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

node* Tree::removeNode(int data, node* root) {  
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = removeNode(data, root->left);
    } else if (data > root->data) {
        root->right = removeNode(data, root->right);
    } else {
        node *tmp;
        if (root->left == NULL) {
            tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            tmp = root->left;
            free(root);
            return tmp;
        }

        tmp = minNodeValue(root->right);
        root->data = tmp->data;

        root->right = removeNode(data, root->right);    
    }
    return root;
}

void Tree::inOrder(node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void Tree::posOrder(node *root) {
    if (root == NULL) {
        return;
    }
    posOrder(root->left);
    posOrder(root->right);
    cout << root->data << " ";
}

void Tree::preOrder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void Tree::transversalOrder(node *root) {
    if (root == NULL) {
        return;
    }
    vector<node*> searchNodes;
    searchNodes.push_back(root);
    while(searchNodes.size()) {
        node *ptr = searchNodes[0];
        searchNodes.erase(searchNodes.begin());
        cout << ptr->data << " ";
        if (ptr->left != NULL) {
            searchNodes.push_back(ptr->left);
        }
        if (ptr->right != NULL) {
            searchNodes.push_back(ptr->right);
        }
    } 
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
    tree.remove(5);   
    cout << "transversalOrder: "; 
    tree.transversalOrder(tree.root);
    cout << endl;
    return 0;
}