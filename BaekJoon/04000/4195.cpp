// Title : 친구 네트워크
// Link  : https://www.acmicpc.net/problem/4195 
// Time  : 88 ms
// Memory: 18908 KB

#include <bits/stdc++.h>

using namespace std;

int memo[200000], cnt[200000];

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

int Query(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return cnt[a];

  if (cnt[a] > cnt[b]) swap(a, b);
  memo[a] = b;
  cnt[b] += cnt[a];
  return cnt[b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    iota(memo, memo + (n << 1), 0);
    fill_n(cnt, n << 1, 1);

    unordered_map<string, int> hm;
    while (n--) {
      string s1, s2;
      cin >> s1 >> s2;
      int i1, i2;
      if (auto it = hm.find(s1); it != hm.end()) {
        i1 = it->second;
      } else {
        i1 = hm[s1] = hm.size();
      }
      if (auto it = hm.find(s2); it != hm.end()) {
        i2 = it->second;
      } else {
        i2 = hm[s2] = hm.size();
      }
      cout << Query(i1, i2) << "\n";
    }
  }

  return 0;
}
