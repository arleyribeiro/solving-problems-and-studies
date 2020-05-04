#include <bits/stdc++.h>

using namespace std;

void merge(int* elements, int start, int middle, int end);
int mergeSort(int* elements, int start, int end);
void show(int* elements, int length);

int main () {
  int length = 9;
  int elements[length] = {6,7,3,9,5,1,4,8,2};
  mergeSort(elements, 0, length-1);
  show(elements, length);
  return 0;
}

void merge(int* elements, int start, int middle, int end) {
  int n1 = middle - start + 1;
  int n2 = end - middle;
  int L[n1], R[n2];

  for(int i = 0; i < n1; i++) {
    L[i] = elements[start + i];
  }

  for(int i = 0; i < n2; i++) {
    R[i] = elements[middle + i + 1];
  }

  int ir = 0, il = 0, i = start;
  
  while (il < n1 && ir < n2) {
    if (L[il] < R[ir]) {
      elements[i] = L[il];
      il++;
    } else {
      elements[i] = R[ir];
      ir++;
    }
    i++;
  }

  while (il < n1) {
    elements[i] = L[il];
    i++;
    il++;
  }

  while (ir < n2) {
    elements[i] = R[ir];
    i++;
    ir++;
  }
}

int mergeSort(int* elements, int start, int end) {
  if (start < end) {
    int middle = (start + end) / 2;
    mergeSort(elements, start, middle);
    mergeSort(elements, middle + 1, end);
    merge(elements, start, middle, end);
  }
}

void show(int* elements, int length) {
  for (int i = 0; i < length; i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
}