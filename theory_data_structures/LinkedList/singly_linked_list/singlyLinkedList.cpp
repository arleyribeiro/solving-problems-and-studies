#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *next = NULL;
};

class List {
    node * head = NULL;
  public:
    List() {
      
    };
    bool isEmpty() {
      return head == NULL;
    }
    void insert(int data);
    //void remove(int data);
    void show();
};

void List::insert(int data) {
  node *no = new node;
  no->data = data;
  no->next = NULL;
  if (isEmpty()) {
    head = no;
    return;
  }
  node *parent;
  node *ptr = head;
  while(ptr != NULL) {
    parent = ptr;
    ptr = ptr->next;
  }
  parent->next = no;
}

void List::show() {
  if (isEmpty()) {
    return;
  }
  node *ptr = head;
  while(ptr != NULL) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

int main () {

  List list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.show();

  return 0;
}