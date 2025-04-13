// Title : 귤나무
// Link  : https://www.acmicpc.net/problem/31005 
// Time  : 32 ms
// Memory: 6784 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;
  vector<int64_t> arr(n);
  int64_t sum = 0;
  for (auto& e : arr) {
    cin >> e;
    sum += e;
  }

  while (!arr.empty()) {
    m %= sum;
    vector<int64_t> nxt;
    sum = 0;
    for (auto e: arr) {
      if (e <= m) {
        m -= e;
        sum += e;
        nxt.push_back(e);
      }
    }
    arr.swap(nxt);
  }
  cout << m;

  return 0;
}
