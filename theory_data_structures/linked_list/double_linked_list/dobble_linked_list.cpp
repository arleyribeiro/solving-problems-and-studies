#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *next = nullptr;
  node *previous = nullptr;
};

class List {
  private:
    node *head = new node;
    int length = 0;
  public:
    List() {
      head->next = nullptr;
      head->previous = nullptr;
    };
    bool isEmpty() {
      return (head->previous == nullptr && head->next == nullptr);
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
  no->next = nullptr;
  no->previous = nullptr;
  length++;
  if (isEmpty()) {
    head->next = no;
    no->previous = head;
  } else {
    node *parent = head;
    node *ptr = head->next;
    while(ptr != nullptr) {
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
  while (ptr != nullptr) {
    if(ptr->data == data) {
      if (ptr->next == nullptr) {
        ptr->previous->next = nullptr;
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
      if (index == 0)
      {
        if (ptr->next == nullptr) {
          head->next = nullptr;
        } else {
          ptr->next->previous = head;
          head->next = ptr->next;
        }
      } else if(ptr->next != nullptr) {
        parent->next = ptr->next;
        ptr->next->previous = parent;
      } else {
        parent->next = nullptr;
      }
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
    cout << "Empty list!" << endl;
    return;
  }
  node *parent = head;
  node *ptr = head->next;
  while(ptr != nullptr) {
    parent = ptr;
    cout << ptr->data << " ";
    ptr = ptr->next;  
  }
  cout << endl;
  if (inverseOrder) {
    cout << "List inverse order: ";
    node *ptr = parent;
    while(ptr != nullptr) {
      if (ptr->previous != nullptr) {
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
  list.show(true);
  list.removeByIndex(3);
  list.removeByIndex(2);
  list.removeByIndex(1);
  list.removeByIndex(0);

  list.show(true);

  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.show(true);

  list.removeByIndex(4);
  list.removeByIndex(1);
  list.removeByIndex(2);
  list.removeByIndex(1);
  list.removeByIndex(0);
  list.show(true);
  return 0;
}