#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *next = NULL;
  node *previous = NULL;
};

class List {
  private:
    node *head = new node;
    int length = 0;
  public:
    List() {
      head->next = NULL;
      head->previous = NULL;
    };
    bool isEmpty() {
      return (head->previous == NULL && head->next == NULL);
    }
    void insert(int data);
    void show(bool inverseOrder);
    void remove(int data);
    int size();
};

void List::insert(int data) {
  node *no = new node;
  no->data = data;
  no->next = NULL;
  no->previous = NULL;
  length++;
  if (isEmpty()) {
    head->next = no;
    no->previous = head;
  } else {
    node *parent = head;
    node *ptr = head->next;
    while(ptr != NULL) {
      parent = ptr;
      ptr = ptr->next;
    }
    no->previous = parent;
    parent->next = no;
  }
}

void List::remove(int data) {
  if (isEmpty()) {
    return;
  }
  node *parent = head;
  node *ptr = head->next;
  while (ptr != NULL) {
    if(ptr->data == data) {
      if (ptr->next == NULL) {
        ptr->previous->next = NULL;
      } else {
        parent->next = ptr->next;
        ptr->next->previous = parent;
      }
      length--;
      free(ptr);
      return;
    }
    parent = ptr;
    ptr = ptr->next;
  }
}

void List::show(bool inverseOrder) {
  if (isEmpty()) {
    cout << "Empty list!" << endl;
    return;
  }
  node *parent = head;
  node *ptr = head->next;
  while(ptr != NULL) {
    parent = ptr;
    cout << ptr->data << " ";
    ptr = ptr->next;  
  }
  cout << endl;
  if (inverseOrder) {
    cout << "List inverse order: ";
    node *ptr = parent;
    while(ptr != NULL) {
      if (ptr->previous != NULL) {
        cout << ptr->data << " ";
      }
      ptr = ptr->previous;
    }
    cout << endl;
  }
}

int List::size() {
  return length;
}

int main() {
  List list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  cout << list.size() << endl;
  list.show(true);
  list.remove(3);
  list.show(true);
  list.remove(5);
  list.show(true);
  list.remove(1);
  list.show(true);
  list.remove(2);
  list.show(true);
  list.remove(4);
  list.show(true);
  cout << list.size() << endl;
  return 0;
}