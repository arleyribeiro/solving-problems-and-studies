#include <bits/stdc++.h>

using namespace std;

int main () {
    int start, end;
    string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> start >> end;
    for(int number = start; number <= end; number++) {
        if (number <= 9)  {
            cout << numbers[number] << endl;
        } else if(number % 2 == 0) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    }
    return 0;
}