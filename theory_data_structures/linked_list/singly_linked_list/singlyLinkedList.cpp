#include <bits/stdc++.h>

using namespace std;
/*
struct node {
  int data;
  node *next = nullptr;
};
*/
class Node
{
public:
  int data;
  Node *next;

  Node() {}
  Node(int node_data)
  {
    this->data = node_data;
    this->next = nullptr;
  }
};

class List
{
  Node *head = new Node();
  int length;

public:
  List()
  {
    head->next = nullptr;
    length = 0;
  };
  bool isEmpty()
  {
    return head->next == nullptr;
  }
  void insert(int data);
  void remove(int data);
  void insertNodeAtPosition(int data, int position);
  void removeAtPosition(int position);
  void show();
  int size();
};

void List::insert(int data)
{
  Node *no = new Node(data);
  length++;
  if (isEmpty())
  {
    head->next = no;
    return;
  }
  Node *parent;
  Node *ptr = head->next;
  while (ptr != nullptr)
  {
    parent = ptr;
    ptr = ptr->next;
  }
  parent->next = no;
}

void List::show()
{
  if (isEmpty())
  {
    return;
  }
  Node *ptr = head->next;
  while (ptr != nullptr)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

int List::size()
{
  return length;
}

void List::insertNodeAtPosition(int data, int position)
{
  if (position > (this->size() - 1) || position < 0)
  {
    cout << "Index out of range" << endl;
    return;
  }
  if (isEmpty())
  {
    head->next = new Node(data);
  }
  else
  {
    int count = 0;
    Node *node = new Node(data);
    Node *ptr = head->next, *parent = head;
    while (ptr != nullptr)
    {
      if (count == position)
      {
        parent->next = node;
        node->next = ptr;
      }
      else
      {
        if (ptr->next == nullptr && (count + 1) == position)
        {
          parent->next = node;
          node->next = ptr;
        }
      }
      count++;
      parent = ptr;
      ptr = ptr->next;
    }
  }
}

void List::remove(int data)
{
  if (isEmpty())
  {
    return;
  }
  Node *parent = head;
  Node *ptr = head->next;
  while (ptr != nullptr)
  {
    if (ptr->data == data)
    {
      length--;
      Node *next;
      if (ptr->next != nullptr)
      {
        next = ptr->next;
        parent->next = next;
      }
      else
      {
        parent->next = nullptr;
      }
      free(ptr);
      return;
    }
    parent = ptr;
    ptr = ptr->next;
  }
}

void List::removeAtPosition(int position)
{
  int count = 0;
  if (position < 0 || (position > this->size()-1) )
  {
    cout << "Index out of range" << endl;
    return;
  }
  Node *ptr = head->next;
  Node *parent = head;
  while (ptr != nullptr)
  {
    if (count == position)
    {
      if (position == 0 && ptr->next != nullptr)
      {
        head->next = ptr->next;
      }
      parent->next = ptr->next;
      free(ptr);
      break;
    }
    else if (ptr->next == nullptr && (count + 1) == position)
    {
      free(ptr);
      break;
    }
    count++;
    parent = ptr;
    ptr = ptr->next;
  }
}

int main()
{

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
  list.insertNodeAtPosition(1, 0);
  list.show();
  list.insertNodeAtPosition(5, 4);
  list.show();
  list.insertNodeAtPosition(9, 8);
  list.show();
  list.removeAtPosition(0);
  list.show();
  list.removeAtPosition(2);
  list.show();
  list.removeAtPosition(5);
  list.show();
  list.removeAtPosition(6);

  return 0;
}