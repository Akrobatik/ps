#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> MakeTable(const vector<int>& arr) {
  vector<vector<int>> table;
  int n = arr.size(), mid = n >> 1;
  int ns = 0;
  while ((1 << ns) < n) ++ns;
  table.reserve(ns + 1);
  vector<int> p(n), pn(n), cnts(n);

  for (int i = 0; i < n; i++) pn[i] = i, p[i] = arr[i];
  for (auto e : pn) ++cnts[arr[e]];
  partial_sum(cnts.begin(), cnts.end(), cnts.begin());
  for (auto e : views::reverse(pn)) p[--cnts[arr[e]]] = e;
  int rank = 0;
  auto& ranks = table.emplace_back(n);
  for (int i = 1; i < n; i++) {
    if (arr[p[i - 1]] != arr[p[i]]) ++rank;
    ranks[p[i]] = rank;
  }

  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - k;
      if (pn[i] < 0) pn[i] += n;
    }
    memset(cnts.data(), 0, cnts.size() * sizeof(int));
    auto& old = table.back();
    for (auto e : pn) ++cnts[old[e]];
    partial_sum(cnts.begin(), cnts.end(), cnts.begin());
    for (auto e : views::reverse(pn)) p[--cnts[old[e]]] = e;
    int rank = 0;
    auto& ranks = table.emplace_back(n);
    for (int i = 1; i < n; i++) {
      if (old[p[i - 1]] != old[p[i]] || old[(p[i - 1] + k) % n] != old[(p[i] + k) % n]) ++rank;
      ranks[p[i]] = rank;
    }
  }

  return table;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int n2 = n << 1;
  vector<int> arr(n2 + 1), rots(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i + n] = arr[i];
    rots[i] = i;
  }

  auto table = MakeTable(arr);

  auto CmpSeg = [&](int lhs, int rhs, int len) {
    if (len == 0) return 0;
    int step = bit_width((uint32_t)len) - 1;
    auto& ranks = table[step];
    len = len ^ (1 << step);
    return ranks[lhs] != ranks[rhs] ? ranks[lhs] - ranks[rhs] : ranks[lhs + len] - ranks[rhs + len];
  };

  auto Cmp = [&](int lhs, int rhs) {
    int s1 = arr[lhs], s2 = arr[rhs];
    int p1 = lhs < s1 ? lhs - s1 + n : lhs - s1;
    int p2 = rhs < s2 ? rhs - s2 + n : rhs - s2;

    int l, r, a1, a2;
    if (p1 < p2) {
      l = p1, r = p2, a1 = 1, a2 = 0;
    } else {
      l = p2, r = p1, a1 = 0, a2 = 1;
    }

    int cmp = CmpSeg(s1, s2, l);
    if (cmp) return cmp < 0;
    cmp = CmpSeg((s1 + l + a1) % n, (s2 + l + a2) % n, r - l);
    if (cmp) return cmp < 0;
    return CmpSeg((s1 + r + 1) % n, (s2 + r + 1) % n, n - r - 1) < 0;
  };

  nth_element(rots.begin(), rots.begin() + 1, rots.end(), Cmp);

  cout << rots[0] + 1;

  return 0;
}
