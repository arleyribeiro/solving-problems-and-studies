#include <bits/stdc++.h>

#define CLOUD_MAX 100

using namespace std;

int minimumBribes(vector<int> queue) {

    int  persons = queue.size(), 
        minBribes = 0;
    
    for(int i = 1; i < persons; i++) {

        if (queue[i] != i) {
            int temp = queue[i];
            queue[i] = queue[temp];
            queue[temp] = temp;
            minBribes++;
        }
    }
    return minBribes;
}

int main () {

    vector<int> queue;
    int persons;
    cin >> persons;

    for(int i = 1; i <= persons; i++) {
        cin >> queue[i];
    }
    
    cout << minimumBribes(queue) << endl;
    return 0;
}