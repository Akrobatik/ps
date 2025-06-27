// Title : 게리맨더링
// Link  : https://www.acmicpc.net/problem/17471 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> pops(n);
  for (auto& e : pops) cin >> e;

  vector<vector<int>> edges(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    while (m--) {
      int x;
      cin >> x;
      edges[i].push_back(x - 1);
    }
  }

  int minn = INT_MAX;
  int limit = 1 << n;
  vector<int> arr, brr;
  queue<int> q;
  for (int i = 1; i < limit; i++) {
    bitset<32> bits(i);
    if (bits.count() == n) continue;

    arr.clear(), brr.clear();
    for (int j = 0; j < n; j++) {
      if (bits.test(j)) {
        arr.push_back(j);
      } else {
        brr.push_back(j);
      }
    }

    auto Calc = [&](int st, const vector<int>& cands) {
      bool notv[10] = {};
      for (auto e : cands) notv[e] = true;

      auto Push = [&](int x) {
        if (!notv[x]) return;
        notv[x] = false;
        q.push(x);
      };

      Push(st);
      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : edges[cur]) {
          Push(nxt);
        }
      }

      int sum = 0;
      for (auto e : cands) {
        if (notv[e]) return -1;
        sum += pops[e];
      }
      return sum;
    };

    int a = Calc(arr[0], arr);
    int b = Calc(brr[0], brr);
    if (a != -1 && b != -1) minn = min<int>(minn, abs(a - b));
  }

  cout << (minn != INT_MAX ? minn : -1);

  return 0;
}
