#include <bits/stdc++.h>

using namespace std;

constexpr int kMask = (1 << 9) - 1;

int MakeKey(int a, int b, int c) {
  return (a << 18) | (b << 9) | c;
}

tuple<int, int, int> SplitKey(int key) {
  int a = (key >> 18) & kMask;
  int b = (key >> 9) & kMask;
  int c = key & kMask;
  return {a, b, c};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt, t;
  cin >> nt >> t;
  vector<int> trr(nt);
  for (auto& e : trr) cin >> e;

  int na, nb, nc;
  cin >> na >> nb >> nc;
  vector<int> arr(na), brr(nb), crr(nc);
  for (auto& e : arr) cin >> e;
  for (auto& e : brr) cin >> e;
  for (auto& e : crr) cin >> e;

  vector<int> axr(na + 1), bxr(nb + 1), cxr(nc + 1);
  partial_sum(arr.begin(), arr.end(), axr.begin() + 1);
  partial_sum(brr.begin(), brr.end(), bxr.begin() + 1);
  partial_sum(crr.begin(), crr.end(), cxr.begin() + 1);

  vector<pair<int, int>> cands;
  vector<vector<pair<int, int>>> perms;

  unordered_map<int, int> cur;
  cur[MakeKey(0, 0, 0)] = 0;

  for (int i = 1; i < nt; i++) {
    int trem = trr[i] - trr[i - 1] - 1;
    if (trem == 0) continue;
    unordered_map<int, int> nxt;

    for (auto [key, cnt] : cur) {
      auto [a, b, c] = SplitKey(key);
      cands.clear();
      if (a < na) cands.push_back({0, a});
      if (b < nb) cands.push_back({1, b});
      if (c < nc) cands.push_back({2, c});

      perms.clear();
      do {
        perms.push_back(cands);
      } while (next_permutation(cands.begin(), cands.end()));

      for (auto& perm : perms) {
        int used = 0, added = 0;
        int aa = a, bb = b, cc = c;
        for (auto [id, start] : perm) {
          auto& sxr = id == 0 ? axr : (id == 1 ? bxr : cxr);
          int limit = id == 0 ? na : (id == 1 ? nb : nc);
          int maxx = start;
          while (maxx < limit && used + sxr[maxx + 1] - sxr[start] <= trem) ++maxx;

          used += sxr[maxx] - sxr[start];
          added += maxx - start;
          if (id == 0) {
            aa = maxx;
          } else if (id == 1) {
            bb = maxx;
          } else {
            cc = maxx;
          }
        }

        int nkey = MakeKey(aa, bb, cc);
        int total = cnt + added;
        if (auto it = nxt.find(nkey); it != nxt.end()) {
          it->second = max<int>(it->second, total);
        } else {
          nxt[nkey] = total;
        }
      }
    }

    cur.swap(nxt);
  }

  int ans = 0;
  for (auto [key, cnt] : cur) {
    ans = max<int>(ans, cnt);
  }
  cout << ans;

  return 0;
}
