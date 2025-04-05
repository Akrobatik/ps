// Title : 지역 코드 정하기
// Link  : https://www.acmicpc.net/problem/33698
// Time  : 52 ms
// Memory: 5280 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> cands[1024];

int memo[1024], mcopy[1024];
vector<int> elems[1024];
int cnts[1024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    bitset<10> bits;
    for (auto c : s) bits.flip(c ^ 0x30);
    int x = bits.to_ulong(), len = s.size();
    if (cands[x].size() < 2) {
      cands[x].push_back({len, i});
    } else {
      for (auto& [l, idx] : cands[x]) {
        if (l > len) {
          l = len, idx = i;
          break;
        }
      }
    }
  }

  for (auto& e : memo) e = INT_MAX;
  for (int x = 0; x < 1024; x++) {
    for (auto [len, idx] : cands[x]) {
      memcpy(mcopy, memo, sizeof(mcopy));
      for (int i = 1; i < 1024; i++) {
        if (mcopy[i] == INT_MAX) continue;
        int nxt = i ^ x;
        if (memo[nxt] > mcopy[i] + len) {
          memo[nxt] = mcopy[i] + len;
          elems[nxt].resize(elems[i].size() + 1);
          copy(elems[i].begin(), elems[i].end(), elems[nxt].begin());
          elems[nxt].back() = idx;
        }
      }
      if (memo[x] > len) {
        memo[x] = len;
        elems[x].clear();
        elems[x].push_back(idx);
      }
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
