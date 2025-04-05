// Title : 괄호
// Link  : https://www.acmicpc.net/problem/9012
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (n--) {
    string s;
    getline(cin, s);

    bool ok = true;
    stack<char> st;
    for (char c : s) {
      if (c == '(') {
        st.push(c);
      } else if (c == ')') {
        if (st.empty()) {
          ok = false;
          break;
        }
        st.pop();
      }
    }

    cout << (ok && st.empty() ? "YES\n" : "NO\n");
  }

  return 0;
}
