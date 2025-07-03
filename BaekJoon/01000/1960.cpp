// Title : 행렬만들기
// Link  : https://www.acmicpc.net/problem/1960 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> mat(n, string(n, '0'));

  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) continue;
    pq.push({x, i});
  }

  vector<pair<int, int>> tmp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x > pq.size()) {
      cout << "-1";
      return 0;
    }

    while (x--) {
      auto [cnt, row] = pq.top();
      pq.pop();

      mat[row][i] = '1';
      if (--cnt) tmp.push_back({cnt, row});
    }

    while (!tmp.empty()) pq.push(tmp.back()), tmp.pop_back();
  }

  if (!pq.empty()) {
    cout << "-1";
    return 0;
  }

  cout << "1\n";
  for (auto& s : mat) cout << s << "\n";

  return 0;
}
