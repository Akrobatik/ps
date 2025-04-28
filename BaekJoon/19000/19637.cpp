// Title : IF문 좀 대신 써줘
// Link  : https://www.acmicpc.net/problem/19637 
// Time  : 80 ms
// Memory: 9948 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<int, string, greater<int>> memo;

  int n, m;
  cin >> n >> m;
  while (n--) {
    string s;
    int x;
    cin >> s >> x;
    auto it = memo.find(x);
    if (it == memo.end()) memo[x] = s;
  }

  while (m--) {
    int x;
    cin >> x;
    auto it = memo.upper_bound(x);
    cout << (--it)->second << "\n";
  }

  return 0;
}
