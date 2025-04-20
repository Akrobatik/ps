// Title : Thomas
// Link  : https://www.acmicpc.net/problem/33787 
// Time  : 4 ms
// Memory: 2948 KB

#include <bits/stdc++.h>

using namespace std;

bool memo[1 << 15];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<string> ans;

  int limit = 1 << n;
  for (int i = 0; i < limit; i++) {
    if (memo[i]) continue;
    bitset<15> bits(i);
    ans.push_back(bits.to_string().substr(15 - n));
    for (int j = 0; j < n; j++) {
      bits.flip(j);
      memo[bits.to_ulong()] = true;
      bits.flip(j);
    }
  }

  cout << ans.size() << "\n";
  for (auto& s : ans) cout << s << "\n";

  return 0;
}
