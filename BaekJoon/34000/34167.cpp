// Title : Hello, MatKor Cup!
// Link  : https://www.acmicpc.net/problem/34167 
// Time  : 120 ms
// Memory: 13676 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> weights;
  vector<vector<int>> queries;

  int s = 1, r = n, t = k;
  while (r > t || weights.empty()) {
    int c = r / t;
    while (--c) {
      weights.push_back(t);
      auto& qr = queries.emplace_back();
      qr.resize(k);
      for (int i = 0; i < t; i++) qr[i] = s + i;
      for (int i = t; i < k; i++) qr[i] = n - k + i + 1;
      r -= t, s += t;
    }

    weights.push_back(r % t ? r % t : t);
    auto& qr = queries.emplace_back();
    qr.resize(k);
    for (int i = 0; i < t; i++) qr[i] = s + i;
    for (int i = t; i < k; i++) qr[i] = n - k + i + 1;

    int x = r - t;
    r -= x, t -= x;
  }

  int nq = queries.size();
  int64_t sum = 0;
  for (int i = 0; i < nq; i++) {
    cout << "?";
    for (auto e : queries[i]) cout << " " << e;
    cout << endl;

    int64_t val;
    cin >> val;
    sum += val * weights[i];
  }
  cout << "! " << sum / k << endl;

  return 0;
}