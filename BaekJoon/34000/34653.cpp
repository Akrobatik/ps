// Title : Freedom Dive
// Link  : https://www.acmicpc.net/problem/34653 
// Time  : 160 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int64_t, int64_t>;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto Check = [&](const pii& a, const pii& b, const pii& c) {
    auto [ab, aa] = a;
    auto [bb, ba] = b;
    auto [cb, ca] = c;
    return (bb - cb) * (ca - aa) <= (ca - ba) * (ab - cb);
  };

  vector<pii> arr;
  while (n--) {
    int64_t l, d;
    cin >> l >> d;
    pii ld = {l, d};
    while (1 < arr.size() && Check(arr[arr.size() - 2], arr.back(), ld)) arr.pop_back();
    arr.push_back(ld);
  }

  int m;
  cin >> m;
  while (m--) {
    int64_t x;
    cin >> x;

    int id = lower_bound(arr.begin(), arr.end(), pair<int64_t, int64_t>{x, 0}) - arr.begin();
    auto [ll, ld] = arr[id - 1];
    auto [rl, rd] = arr[id];

    int64_t q = rl - ll, p = (rd - ld) * (x - ll);
    p += ld * q;
    int64_t g = GCD(p, q);
    p /= g, q /= g;
    cout << p << " " << q << "\n";
  }

  return 0;
}