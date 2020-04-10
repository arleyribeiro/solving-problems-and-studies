#include <bits/stdc++.h>

using namespace std;

int main() {

    int length_board, number_obstacles;
    int m, n, attack = 0, bx, by;
    set< pair<int, int> >obstacles;

    scanf("%d %d", &length_board, &number_obstacles);
    scanf("%d %d", &m, &n);

    while(number_obstacles--) {
        scanf("%d %d", &bx, &by);
        obstacles.insert(make_pair(bx, by));
    }

    for(int i = m, j = n - 1 ; j > 0; j--) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }

    for(int i = m, j = n + 1 ; j <= length_board; j++) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }
    
    for(int i = m - 1, j = n; i > 0; i--) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }
    for(int i = m+1, j = n; i <= length_board; i++) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }

    for(int i = m-1, j = n-1; i > 0 && j > 0; i--, j--) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }

    for(int i = m+1, j = n+1; i <= length_board && j <= length_board; i++, j++) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }

    for(int i = m-1, j = n+1; i > 0 && j <= length_board; i--, j++) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }

    for(int i = m+1, j = n-1; i <= length_board && j > 0; i++, j--) {
        if(obstacles.find(make_pair(i, j)) != obstacles.end())
            break;
        attack++;
    }

    cout << attack << endl;
    return 0;
}