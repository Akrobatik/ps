// Title : Подрыв ветряка
// Link  : https://www.acmicpc.net/problem/28618 
// Time  : 332 ms
// Memory: 3480 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kPad = 2e4 + 1;

pair<int, int> links[50002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<tup> arr, brr;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if (b < 0) {
      arr.push_back({a, b, i});
    } else if (b > 0) {
      brr.push_back({a, b, i});
    }
  }

  set<int, greater<int>> memo;
  memo.insert(s);
  sort(brr.begin(), brr.end());
  for (auto [a, b, i] : brr) {
    set<int> nxt;
    for (auto x : memo) {
      if (x < a) break;
      if (memo.contains(x + b)) continue;
      if (nxt.insert(x + b).second) links[x + b + kPad] = {x + kPad, i};
    }
    memo.insert(nxt.begin(), nxt.end());
  }

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [la, lb, li] = lhs;
    auto [ra, rb, ri] = rhs;
    return la + lb > ra + rb;
  });
  for (auto [a, b, i] : arr) {
    set<int> nxt;
    for (auto x : memo) {
      if (x < a) break;
      if (memo.contains(x + b)) continue;
      if (nxt.insert(x + b).second) links[x + b + kPad] = {x + kPad, i};
    }
    memo.insert(nxt.begin(), nxt.end());
  }
  
  vector<int> ans;
  int minn = *memo.rbegin(), id = minn + kPad;
  for (;;) {
    auto [nxt, idx] = links[id];
    if (idx == 0) break;
    ans.push_back(idx);
    id = nxt;
  }

  cout << minn << " " << ans.size() << "\n";
  for (auto e : views::reverse(ans)) cout << e << " ";

  return 0;
}
