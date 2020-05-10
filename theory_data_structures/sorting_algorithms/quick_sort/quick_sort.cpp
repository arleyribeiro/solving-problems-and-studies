#include <bits/stdc++.h>

using namespace std;

void quickSort(int* elements, int start, int end);
void show(int* elements, int length);
void swap(int *a, int *b);

int main () {
  int length = 9;
  int elements[length] = {6,7,3,9,5,1,4,8,2};
  quickSort(elements, 0, length-1);
  show(elements, length);
  return 0;
}

void quickSort(int* elements, int start, int end) {  
	int i = start;
	int j = end;
	int middle = ((end + start) / 2);
  int pivo = elements[middle];
	while (i <= j) {
		while (i < end && pivo > elements[i]) {
			i++;
		}
		while (j > start && pivo < elements[j])
		{
			j--;
		}
		if (i <= j) {
			swap(&elements[i], &elements[j]);
			i++;
			j--;
		}		
	}

	if (i < end) {
		quickSort(elements, i, end);
	}

	if (j > start) {
		quickSort(elements, start, j+1);
	}
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void show(int* elements, int length) {
  for (int i = 0; i < length; i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
}