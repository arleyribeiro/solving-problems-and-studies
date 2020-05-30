#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left = nullptr;
    node *right = nullptr;
};

class Tree {
    public:
    struct node *root;
    Tree() {
        root = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
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
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (isEmpty()) {
        root = newNode;
    } else {
        node *ptr = root;
        node *parent;
        while(ptr != nullptr) {
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
    while(current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

node* Tree::removeNode(int data, node* root) {  
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = removeNode(data, root->left);
    } else if (data > root->data) {
        root->right = removeNode(data, root->right);
    } else {
        node *tmp;
        if(root->left != nullptr && root->right != nullptr) {
            tmp = minNodeValue(root->right);
            cout << tmp->data << endl;
            root->data = tmp->data;
            root->right = removeNode(tmp->data, root->right);    
        } else if (root->left == nullptr) {
            tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == nullptr) {
            tmp = root->left;
            free(root);
            return tmp;
        }
    }
    return root;
}

void Tree::inOrder(node *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void Tree::posOrder(node *root) {
    if (root == nullptr) {
        return;
    }
    posOrder(root->left);
    posOrder(root->right);
    cout << root->data << " ";
}

void Tree::preOrder(node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void Tree::transversalOrder(node *root) {
    if (root == nullptr) {
        return;
    }
    vector<node*> searchNodes;
    searchNodes.push_back(root);
    while(searchNodes.size()) {
        node *ptr = searchNodes[0];
        searchNodes.erase(searchNodes.begin());
        cout << ptr->data << " ";
        if (ptr->left != nullptr) {
            searchNodes.push_back(ptr->left);
        }
        if (ptr->right != nullptr) {
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
    tree.remove(6);
    cout << "transversalOrder: "; 
    tree.transversalOrder(tree.root);
    cout << endl;
    tree.remove(6);   
    cout << "transversalOrder: "; 
    tree.transversalOrder(tree.root);
    cout << endl;
    return 0;
}