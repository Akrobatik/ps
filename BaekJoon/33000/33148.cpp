// Title : 또또 수열 문제야
// Link  : https://www.acmicpc.net/problem/33148 
// Time  : 1060 ms
// Memory: 64608 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int64_t, int, greater<int64_t>> mp;
  for (int i = 0; i < n * n; i++) {
    int64_t x;
    cin >> x;
    ++mp[x];
  }

  auto it = mp.begin();
  int64_t val = it->first;
  if (--(it->second) == 0) mp.erase(it);

  int64_t key = (int64_t)sqrt((long double)val);
  while (key * key < val) ++key;
  if (key * key != val) {
    cout << "NO";
    return 0;
  }

  vector<int64_t> arr{key};
  arr.reserve(n);

  for (int i = 1; i < n; i++) {
    int64_t cur = mp.begin()->first;
    if (cur % key) {
      cout << "NO";
      return 0;
    }

    cur /= key;
    for (int j = 0; j < i; j++) {
      val = cur * arr[j];
      auto it = mp.find(val);
      if (it == mp.end() || it->second == 1) {
        cout << "NO";
        return 0;
      }

      if ((it->second -= 2) == 0) mp.erase(it);
    }

    auto it = mp.find(cur * cur);
    if (it == mp.end()) {
      cout << "NO";
      return 0;
    }

    if (--(it->second) == 0) mp.erase(it);
    arr.push_back(cur);
  }

  cout << "YES\n";
  for (auto e : arr) cout << e << " ";

  return 0;
}
