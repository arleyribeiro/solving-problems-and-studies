#include <bits/stdc++.h>

using namespace std;
#define tam 10
int tree[tam] = {0};

int sum(int i) {
    int sum = 0;
    while(i > 0){
        sum += tree[i]; 
        i -= i & -i;
    }
    return sum;
}

void add(int i, int k) {
    while (i < tam) {
        tree[i] += k;
        i += i & -i;
    }
}

void make(int* array) {
    size_t n = sizeof(array);
    for(int i = 1; i <= tam; i++) {
        tree[i] = array[i];
    }
    for(int i = 1; i < tam; i++) {
        int p = i + (i & -i);
        if (p < tam) {
            tree[p] += tree[i];
        }
    }
}

int main () {
    int array[tam] = {0,1,2,3,4,5,6,7,8,9};
    make(array);
    cout << tree[5] << endl;

    cout << "Initial array: ";
    for(int i = 1; i < tam; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Fenwick Tree:  ";
    for(int i = 1; i < tam; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << "Sum of i:  ";
    for(int i = 1; i < tam; i++) {
        cout << sum(i) << " ";
    }
    return 0;
}