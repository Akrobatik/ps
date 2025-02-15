#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  stack<int> st;
  while (n--) {
    int v;
    cin >> v;
    if (v) {
      st.push(v);
    } else {
      st.pop();
    }
  }

  int sum = 0;
  while (!st.empty()) {
    sum += st.top();
    st.pop();
  }
  cout << sum;

  return 0;
}
