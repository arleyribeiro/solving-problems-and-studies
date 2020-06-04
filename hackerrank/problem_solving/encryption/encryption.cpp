#include <bits/stdc++.h>

using namespace std;

int main () {

    string message;

    cin >> message;

    int characters = message.size();
    string decode_message = "";

    int _sqrt = sqrt(characters);
    int lines = floor(_sqrt);
    int columns = lines * lines < characters ? lines + 1 : lines;

    if (lines * columns < characters) {
        if(lines < columns)
            lines++;
        else
            columns++;
    }

    for(int i = 0; i < columns; i++) {
        int index = i;
        if (i > 0)
            decode_message += " ";
        for(int j = 0; j < lines; j++) {
            if(index < characters) {
                decode_message += message[index];
            }
            index += columns;
        }
    }
    cout << decode_message << endl;
    return 0;
}