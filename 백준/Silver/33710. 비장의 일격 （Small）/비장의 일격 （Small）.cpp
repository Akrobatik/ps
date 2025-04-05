#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> cands[26];
unordered_map<int64_t, int> memo;

int Calc(int idx, int rem) {
  if (idx == s.size() || rem == 0) return 0;

  int64_t key = ((int64_t)idx << 32) | rem;
  if (auto it = memo.find(key); it != memo.end()) return it->second;

  int64_t res = Calc(idx + 1, rem);
  auto& arr = cands[s[idx] - 'A'];
  auto it = upper_bound(arr.begin(), arr.end(), idx);
  while (it != arr.end()) {
    auto nxt = *it++ + 1;
    res = max<int64_t>(res, nxt - idx + Calc(nxt, rem - 1));
  }
  return memo[key] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') continue;
    cands[s[i] - 'A'].push_back(i);
  }
  cout << n - Calc(0, k);

  return 0;
}
