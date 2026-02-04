// Title : Dungeon Equilibrium
// Link  : https://www.acmicpc.net/problem/35230 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> cnt(n + 1);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  int cut = 0;
  for (int i = 0; i <= n; i++) {
    cut += cnt[i] - (cnt[i] >= i ? i : 0);
  }
  cout << cut;

  return 0;
}