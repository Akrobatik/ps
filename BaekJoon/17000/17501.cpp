// Title : 수식 트리
// Link  : https://www.acmicpc.net/problem/17501 
// Time  : 40 ms
// Memory: 10672 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int m = (n << 1) - 1;
  vector<tuple<char, int, int>> lr(m + 1);
  for (int i = 1; i < n; i++) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    lr[i + n] = {op, l, r};
  }

  vector<int> flip(n + 1);
  [&](this auto&& self, int cur, int f) -> void {
    auto [op, l, r] = lr[cur];
    if (op == 0) {
      flip[cur] = f;
    } else {
      self(l, f);
      self(r, f ^ (op == '-'));
    }
  }(m, 0);

  int sum = 0;
  vector<int> add, sub;
  for (int i = 1; i <= n; i++) {
    if (flip[i]) {
      sum -= arr[i];
      sub.push_back(arr[i]);
    } else {
      sum += arr[i];
      add.push_back(arr[i]);
    }
  }
  sort(add.begin(), add.end(), greater<int>());
  sort(sub.begin(), sub.end());

  while (!add.empty() && !sub.empty()) {
    int av = add.back(), sv = sub.back();
    add.pop_back(), sub.pop_back();

    int dt = sv - av;
    if (dt <= 0) break;

    sum += dt * 2;
  }
  cout << sum;

  return 0;
}