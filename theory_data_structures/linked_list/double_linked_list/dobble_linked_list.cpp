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
    void removeByIndex(int index);
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

void List::removeByIndex(int index) {
  
  int count = 0;
  if (index < 0 || (index > this->size()-1) )
  {
    cout << "Index out of range" << endl;
    return;
  }
  node *ptr = head->next;
  node *parent = head;
  while (ptr != nullptr)
  {
    if (count == index)
    {
      if (index == 0 && ptr->next != nullptr)
      {
        head->next = ptr->next;
        ptr->next->previous = head;
      } else {
        parent->next = ptr->next;
        ptr->next->previous = parent;
      }
      free(ptr);
      break;
    }
    else if (ptr->next == nullptr && (count + 1) == index)
    {
      parent->next = NULL;
      free(ptr);
      break;
    }
    count++;
    parent = ptr;
    ptr = ptr->next;
  }
}

void List::show(bool inverseOrder) {
  if (isEmpty()) {
    head->next = NULL;
    head->previous = NULL;
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

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  cout << list.size() << endl;
  list.removeByIndex(4);
  list.removeByIndex(3);
  list.removeByIndex(2);
  list.removeByIndex(1);
  list.removeByIndex(0);

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.show(true);

  list.removeByIndex(0);
  list.removeByIndex(1);
  list.removeByIndex(2);
  list.removeByIndex(1);
  list.removeByIndex(0);
  list.show(true);
  return 0;
}