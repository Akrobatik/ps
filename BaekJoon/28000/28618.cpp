// Title : Подрыв ветряка
// Link  : https://www.acmicpc.net/problem/28618 
// Time  : 28 ms
// Memory: 2648 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kPad = 2e4;

bool _memo[2][50001];
pair<int, int> links[50001];

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

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [la, lb, li] = lhs;
    auto [ra, rb, ri] = rhs;
    return la + lb > ra + rb;
  });

  sort(brr.begin(), brr.end(), [](const tup& lhs, const tup& rhs) {
    return get<0>(lhs) < get<0>(rhs);
  });

  auto memo = _memo[0], mnxt = _memo[1];
  memo[s + kPad] = true;

  auto Update = [&](int x, int b, int i) {
    if (!mnxt[x + b]) links[x + b] = {x, i};
    mnxt[x + b] = true;
  };

  for (auto [a, b, i] : brr) {
    memcpy(mnxt, memo, 50001);
    for (int x = a + kPad; x <= 50000; x++) {
      if (!memo[x]) continue;
      Update(x, b, i);
    }
    swap(memo, mnxt);
  }

  for (auto [a, b, i] : arr) {
    memcpy(mnxt, memo, 50001);
    for (int x = a + kPad; x <= 50000; x++) {
      if (!memo[x]) continue;
      Update(x, b, i);
    }
    swap(memo, mnxt);
  }

  int id = 0;
  while (!memo[id]) ++id;
  int minn = id - kPad;

  vector<int> ans;
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
