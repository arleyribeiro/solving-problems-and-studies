#include <bits/stdc++.h>

using namespace std;

int main () {
    int number = 0;
    string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> number;
    if (number <= 9)  {
        cout << numbers[number] << endl;
    } else {
        cout << "Greater than 9\n";
    }
    return 0;
}