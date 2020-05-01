#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int* elements, int length);
void show(int* elements, int length);
void swap(int *a, int *b);

int main () {
  int length = 9;
  int elements[length] = {6,7,3,9,5,1,2,8,4};
  bubbleSort(elements, length);
  show(elements, length);
  return 0;
}

void bubbleSort(int* elements, int length) {
  int key;
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - 1; j++) {
      if (elements[j] >= elements[j + 1]) {
        swap(&elements[j], &elements[j + 1]);
      }
    }
  }
}

void show(int* elements, int length) {
  for (int i = 0; i < length; i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}