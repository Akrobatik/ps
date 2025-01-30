#include <bits/stdc++.h>

using namespace std;

int memo[100001];

int Find(int id) {
  if (memo[id] == id) return id;
  return memo[id] = Find(memo[id]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int g, p;
  cin >> g >> p;
  for (int i = 1; i <= g; i++) memo[i] = i;

  int ans = g;
  for (int i = 0; i < p; i++) {
    int gi;
    cin >> gi;
    int slot = Find(gi);
    if (slot) {
      memo[slot] = Find(slot - 1);
    } else {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
