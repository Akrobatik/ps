// Title : 배열 알아맞히기
// Link  : https://www.acmicpc.net/problem/23636 
// Time  : 72 ms
// Memory: 17584 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  mt19937 gen(random_device{}());
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 1);
  shuffle(ids.begin(), ids.end(), gen);

  int m = min<int>(n, 200);
  vector<pair<int64_t, int64_t>> arr;
  arr.reserve(m);

  int64_t v12, v13, v23;
  cout << "? " << ids[0] << " " << ids[1] << endl;
  cin >> v12;
  cout << "? " << ids[0] << " " << ids[2] << endl;
  cin >> v13;
  cout << "? " << ids[1] << " " << ids[2] << endl;
  cin >> v23;
  int64_t v123 = (v12 + v13 + v23) >> 1;

  arr.push_back({ids[0], v123 - v23});
  arr.push_back({ids[1], v123 - v13});
  arr.push_back({ids[2], v123 - v12});

  for (int i = 3; i < m; i++) {
    auto [op, ov] = arr[i - 1];
    cout << "? " << op << " " << ids[i] << endl;
    int64_t x;
    cin >> x;
    arr.push_back({ids[i], x - ov});
  }

  sort(arr.begin(), arr.end());

  unordered_map<int64_t, int> memo;
  for (int i = 0; i < m; i++) {
    auto [ip, iv] = arr[i];
    for (int j = i + 1; j < m; j++) {
      auto [jp, jv] = arr[j];
      int64_t x = jp - ip, y = jv - iv;
      if (y % x) continue;
      ++memo[y / x];
    }
  }

  int64_t a = 0, am = 0;
  for (auto [k, v] : memo) {
    if (am < v) am = v, a = k;
  }

  memo.clear();
  for (int i = 0; i < m; i++) {
    auto [ip, iv] = arr[i];
    int64_t x = iv - (ip - 1) * a;
    ++memo[x];
  }

  int64_t b = 0, bm = 0;
  for (auto [k, v] : memo) {
    if (bm < v) bm = v, b = k;
  }

  int64_t k = INT64_MAX;
  for (int i = 0; i < m; i++) {
    auto [ip, iv] = arr[i];
    int64_t x = iv - a * (ip - 1) - b;
    if (x) k = x;
  }
  cout << "! " << a << " " << b << " " << k << endl;

  return 0;
}