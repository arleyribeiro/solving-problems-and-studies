#include <bits/stdc++.h>

using namespace std;

void insertionSort(int* elements, int length) {
  int key;
  for (int i = 1; i < length; i++) {
    key = elements[i];
    int j = i - 1;
    while (j >= 0 && elements[j] >= key) {
      elements[j + 1] = elements[j];
      j--;
    }
    elements[j + 1] = key;
  }
}

void show(int* elements, int length) {
  for (int i = 0; i < length; i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
}

int main () {
  int length = 9;
  int elements[length] = {6,7,3,9,5,1,2,8,4};
  insertionSort(elements, length);
  show(elements, length);
  return 0;
}