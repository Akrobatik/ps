#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<int> s;
  int n;
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    s.insert(v);
  }

  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    cout << (s.contains(v) ? '1' : '0') << '\n';
  }

  return 0;
}
