#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, q;
    string str;
    map<string, int> sparseArrays;
    map<string,int>::iterator element;
    cin >> n;
    while (n--) {
        cin >> str;
        element = sparseArrays.find(str);
        if (element != sparseArrays.end()) {
            sparseArrays[str] += 1;
        } else {
            sparseArrays[str] = 1;
        }
    }
    cin >> q;
    while (q--) {
        cin >> str;
        cout << sparseArrays[str] << endl;
    }
    return 0;
}