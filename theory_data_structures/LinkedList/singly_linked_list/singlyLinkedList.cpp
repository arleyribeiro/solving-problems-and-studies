#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *next = NULL;
};

class List {
  node * head = new node;
  public:
    List() {
      head->next = NULL;
    };
    bool isEmpty() {
      return head->next == NULL;
    }
    void insert(int data);
    void remove(int data);
    void show();
};

void List::insert(int data) {
  node *no = new node;
  no->data = data;
  no->next = NULL;
  if (isEmpty()) {
    head->next = no;
    return;
  }
  node *parent;
  node *ptr = head->next;
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
  node *ptr = head->next;
  while(ptr != NULL) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

void List::remove(int data) {
  if (isEmpty()) {
    return;
  }
  node *parent = head;
  node *ptr = head->next;
  while(ptr != NULL) {
    if (ptr->data == data) {
      node *next = new node;      
      if (ptr->next != NULL) {
        next = ptr->next;
        parent->next = next;
      } else {
        parent->next = NULL;
      }
      free(ptr);
      return;
    }
    parent = ptr;
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
  list.insert(5);
  list.insert(6);
  list.insert(7);
  list.insert(8);
  list.insert(9);
  list.insert(10);
  list.show();
  list.remove(9);
  list.show();
  list.remove(5);
  list.show();
  list.remove(10);
  list.show();
  list.remove(1);
  list.show();

  return 0;
}