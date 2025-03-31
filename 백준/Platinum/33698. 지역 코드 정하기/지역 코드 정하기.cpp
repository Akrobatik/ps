#include <bits/stdc++.h>

using namespace std;

int memo[1024], mcopy[1024];
vector<int> elems[1024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto& e : memo) e = INT_MAX;

  int n;
  cin >> n;
  for (int j = 1; j <= n; j++) {
    string s;
    cin >> s;
    bitset<10> bits;
    for (auto c : s) bits.flip(c ^ 0x30);
    int len = s.size(), x = bits.to_ulong();
    memcpy(mcopy, memo, sizeof(mcopy));
    for (int i = 1; i < 1024; i++) {
      if (mcopy[i] == INT_MAX) continue;
      int nxt = i ^ x;
      if (memo[nxt] > mcopy[i] + len) {
        memo[nxt] = mcopy[i] + len;
        elems[nxt].resize(elems[i].size() + 1);
        copy(elems[i].begin(), elems[i].end(), elems[nxt].begin());
        elems[nxt].back() = j;
      }
    }
    if (memo[x] > len) {
      memo[x] = len;
      elems[x].clear();
      elems[x].push_back(j);
    }
  }

  int minn = memo[0], idx = 0;
  for (int i = 1; i != 1024; i <<= 1) {
    if (minn > memo[i]) minn = memo[i], idx = i;
  }

  if (minn == INT_MAX) {
    cout << "-1";
  } else {
    cout << minn << "\n";
    sort(elems[idx].begin(), elems[idx].end());
    cout << elems[idx].size() << "\n";
    for (auto e : elems[idx]) cout << e << " ";
  }

  return 0;
}
