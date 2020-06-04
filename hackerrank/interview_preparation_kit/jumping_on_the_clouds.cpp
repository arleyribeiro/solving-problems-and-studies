#include <bits/stdc++.h>

#define CLOUD_MAX 100

using namespace std;

int jumpingOnClouds(vector<int> clouds) {

    int  number_clouds = clouds.size(), 
        jumps = 0,
        jump_min = CLOUD_MAX;

    for(int i = 0; i < number_clouds - 1; i++) {
        if (!clouds[i] && i) {
            jumps++;
        } else if ( i + 1 < number_clouds && !clouds[i + 1]) {
            jumps++;
            i++;
        }
    }
    jump_min = jumps;
    jumps = 0;
    for(int i = 0; i < number_clouds; i++) {
        if ( i + 2 < number_clouds && !clouds[i + 2]) {
            jumps++;
            i++;
        }
        else if ( i + 1 < number_clouds && !clouds[i + 1]) {
            jumps++;
        }
    }
    if (jump_min > jumps) {
        jump_min = jumps;
    }
    return jump_min;
}

int main () {

    vector<int> clouds;
    int x, number_clouds;

    cin >> number_clouds;

    for(int i = 0; i < number_clouds; i++) {
        cin >> x;
        clouds.push_back(x);
    }

    
    cout << jumpingOnClouds(clouds) << endl;
    return 0;
}