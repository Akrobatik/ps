// Title : 균형잡힌 세상
// Link  : https://www.acmicpc.net/problem/4949
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (;;) {
    string s;
    getline(cin, s);
    if (s.size() == 1) break;

    bool ok = true;
    stack<char> st;
    for (char c : s) {
      if (c == '(' || c == '[') {
        st.push(c);
        continue;
      }

      if (c == ')' || c == ']') {
        if (st.empty() || (c & 0x20) != (st.top() & 0x20)) {
          ok = false;
          break;
        }
        st.pop();
      }
    }

    cout << (ok && st.empty() ? "yes\n" : "no\n");
  }

  return 0;
}
