#include <bits/stdc++.h>
/*Força bruta, otimizar para arvore*/
using namespace std;

#define MAX_LENGTH 99999999
vector<int> width;

int getMinWidth(int start, int end) {
    int minWidth = MAX_LENGTH;
    for (int i = start; i <= end; i++) {
        if(minWidth >= width[i])
            minWidth = width[i];
    }
    return minWidth;
}

int main () {
    int lanesNumbers = 0, tests = 0, aux, start, end;
    
    scanf("%d %d", &lanesNumbers, &tests);

    for (int i = 0; i < lanesNumbers; i++) {
        scanf("%d ", &aux);
        width.push_back(aux);
    }

    for (int i = 0; i < tests; i++) {
        scanf("%d %d", &start, &end);
        printf("%d\n", getMinWidth(start, end));
    }


    return 0;
}