#include <bits/stdc++.h>

using namespace std;

string isBalanced(string str) {
  bool isBalanced = true;
  stack<char> brackets;
    int length = str.size();
    for(int i = 0; i < length; i++) {
      char c = str[i];
      if (c == '{' || c == '(' || c == '[') {
        brackets.push(c);        
      } else if (!brackets.empty()) {
        char top = brackets.top();
        if ((top == '{' && c == '}') || (top == '(' && c == ')') || (top == '[' && c == ']')) {
          brackets.pop();          
        } else {
          isBalanced = false;
          break;
        }
      } else {
        isBalanced = false;
        break;
      }
    }
  return (isBalanced && brackets.empty())? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
