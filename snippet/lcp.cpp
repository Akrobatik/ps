#include <bits/stdc++.h>

using namespace std;

// https://cp-algorithms.com/string/suffix-array.html

struct LCP {
  void Init(string_view sv) {
    int n = sv.size();
    sa.resize(n), lcp.resize(n);
    vector<int> p(n), pn(n), cnts(max<int>(n, 256));

    auto Sort = [&]() {
      memset(cnts.data(), 0, cnts.size() * sizeof(int));
      for (auto e : p) ++cnts[e];
      partial_sum(cnts.begin(), cnts.end(), cnts.begin());
      for (auto e : views::reverse(pn)) sa[--cnts[p[e]]] = e;
    };

    // SA
    for (int i = 0; i < n; i++) sa[i] = pn[i] = i, p[i] = sv[i];
    Sort();
    for (int k = 1; p[sa.back()] + 1 != n; k <<= 1) {
      iota(pn.begin(), pn.begin() + k, n - k);
      for (int i = 0, j = k; i < n; i++) {
        if (sa[i] < k) continue;
        pn[j++] = sa[i] - k;
      }
      Sort();
      int o1, o2;
      o1 = sa[0], pn[o1] = 0;
      for (int i = 1; i < n; i++) {
        o2 = o1, o1 = sa[i];
        pn[o1] = pn[o2];
        if (o1 + k < n && o2 + k < n && p[o1] == p[o2] && p[o1 + k] == p[o2 + k]) continue;
        ++pn[o1];
      }
      swap(p, pn);
    }

    // LCP
    for (int i = 0, k = 0; i < n; i++, k && --k) {
      if (p[i] == 0) continue;
      int j = sa[p[i] - 1];
      while (i + k < n && j + k < n && sv[i + k] == sv[j + k]) ++k;
      lcp[p[i]] = k;
    }
  }

  vector<int> sa, lcp;
};