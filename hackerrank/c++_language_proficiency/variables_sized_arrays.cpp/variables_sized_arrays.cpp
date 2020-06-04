#include <bits/stdc++.h>

using namespace std;

int main () {

    vector<vector<int>> adjacentList;
    int numberArrays, numberQueries, search, indexArray, lengthArray, number;

    scanf("%d %d", &numberArrays, &numberQueries);
    while (numberArrays--) {
        vector<int> newArray;
        scanf("%d", &lengthArray);
        for(int i = 0; i < lengthArray; i++) {
            scanf("%d", &number);
            newArray.push_back(number);
        }
        adjacentList.push_back(newArray);
    }

    while (numberQueries--) {
        scanf("%d %d", &indexArray, &search);
        printf("%d\n", adjacentList[indexArray][search]);
    }
    return 0;
}