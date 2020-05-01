#include <bits/stdc++.h>

using namespace std;
#define tam 8
int segmentTree[tam*2] = {0};

void make(int* array) {
    for(int i = tam*2 - 1, j = tam - 1; j >= 0; i--, j--) {
        segmentTree[i] = array[j];
    }
        
    for(int i = tam-1; i > 0; i--) {
        segmentTree[i] = max(segmentTree[i*2], segmentTree[2*i+1]);
    }
}

void update(int i, int value) {
    i += tam;
    segmentTree[i] = value;
    int newValue;
    while(i > 1) {
        i /= 2;
        newValue = max(segmentTree[i * 2], segmentTree[ 2 * i + 1]);
        if (segmentTree[i] != newValue) {
            segmentTree[i] = newValue;
        } else {
            return;
        }
    }
}

int maxValue(int from, int to) {
    from += tam;
    to += tam;

    int maxValue = INT_MIN;

    while(from < to) {
        if((from & 1) == 1) {
            maxValue = max(maxValue, segmentTree[from]);
            from++;
        }

        if((to & 1) == 1) {
            maxValue = max(maxValue, segmentTree[to]);
            to--;
        }
        from /= 2;
        to /= 2;
    }
    return maxValue;
}

int main () {
    int array[tam] = {6,10,5,2,7,8,0,9};
    make(array);
    for(int i = 1; i < 2*tam; i++) {
        cout << segmentTree[i] << " ";
    }

    for(int i = 1; i < tam; i++) {
        cout << maxValue(i, i+1) << " ";
    }
    cout << endl;
    return 0;
}