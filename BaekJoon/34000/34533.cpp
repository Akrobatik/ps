// Title : Euler Tour Problem
// Link  : https://www.acmicpc.net/problem/34533 
// Time  : 80 ms
// Memory: 19224 KB

#include <bits/stdc++.h>

using namespace std;

struct LCP {
 private:
  struct Buckets : public vector<int> {
    template <typename T>
    Buckets(span<const T> sv) : vector<int>(*max_element(sv.begin(), sv.end()) + 1) {
      for (auto e : sv) ++operator[](e);
    }

    vector<int> Incl() const {
      vector<int> incl(size());
      partial_sum(begin(), end(), incl.begin());
      return incl;
    }

    vector<int> Excl() const {
      vector<int> excl(size());
      partial_sum(begin(), end() - 1, excl.begin() + 1);
      return excl;
    }
  };

  struct LTypes : public vector<bool> {
    template <typename T>
    LTypes(span<const T> sv) : vector<bool>(sv.size()) {
      int n = sv.size();
      for (int i = n - 2; i >= 0; i--) {
        operator[](i) = sv[i] > sv[i + 1] || (sv[i] == sv[i + 1] && operator[](i + 1));
      }
    }
  };

 public:
  void Init(const string_view sv) {
    int n = sv.size();
    buf.resize(n + 1);
    sa = span<int>(buf.data() + 1, n);
    // lcp.resize(n);
    SAIS(span<const char>(sv.data(), n + 1));
    // Kasai(sv);
  }

  span<int> sa;
  vector<int> lcp;

 private:
  void Kasai(const string_view sv) {
    int n = sv.size();
    vector<int> ranks(n);
    for (int i = 0; i < n; i++) ranks[sa[i]] = i + 1;
    for (int i = 0, k = 0; i < n; i++, k && --k) {
      if (ranks[i] == n) {
        k = 0;
        continue;
      }
      int j = sa[ranks[i]];
      while (i + k < n && j + k < n && sv[i + k] == sv[j + k]) k++;
      lcp[ranks[i]] = k;
    }
  }

  template <typename T>
  void SAIS(span<const T> sv) {
    int n = sv.size();
    memset(buf.data(), 0, n * sizeof(int));
    Buckets bkts(sv);
    LTypes ltypes(sv);
    Sort(sv, ltypes, bkts);

    int *sub, sub_len;
    if (!Reduce(sv, ltypes, bkts, sub, sub_len)) {
      SAIS(span<const int>(sub, sub_len));
      for (int i = 0; i < sub_len; i++) sub[buf[i]] = i;
    }

    for (int i = 1, j = 0; i < n; i++) {
      if (IsLMS(ltypes, i)) buf[sub[j++]] = -i;
    }
    memset(buf.data() + sub_len, 0, (n - sub_len) * sizeof(int));
    Sort(sv, ltypes, sub_len, bkts);
  }

  template <typename T>
  void Sort(span<const T> sv, const LTypes& ltypes, Buckets& bkts) {
    int n = sv.size();
    auto incl = bkts.Incl();
    for (int i = 1; i < n; i++) {
      if (IsLMS(ltypes, i)) buf[--incl[sv[i]]] = i;
    }
    SortLS(sv, ltypes, bkts);
  }

  template <typename T>
  void Sort(span<const T> sv, const LTypes& ltypes, int lms_len, Buckets& bkts) {
    auto incl = bkts.Incl();
    for (int i = lms_len - 1; i >= 0; i--) buf[--incl[sv[-buf[i]]]] = -buf[i];
    SortLS(sv, ltypes, bkts);
  }

  template <typename T>
  void SortLS(span<const T> sv, const LTypes& ltypes, Buckets& bkts) {
    int n = sv.size();
    auto incl = bkts.Incl(), excl = bkts.Excl();

    for (int i = 0; i < n; i++) {
      int pos = buf[i] - 1;
      if (pos >= 0 && ltypes[pos]) buf[excl[sv[pos]]++] = pos;
    }

    for (int i = n - 1; i > 0; i--) {
      int pos = buf[i] - 1;
      if (pos >= 0 && !ltypes[pos]) buf[--incl[sv[pos]]] = pos;
    }
  }

  template <typename T>
  bool Reduce(span<const T> sv, const LTypes& ltypes, const Buckets& bkts, int*& sub, int& sub_len) {
    int n = sv.size();
    sub = buf.data() + (n >> 1);
    sub_len = n - (n >> 1);

    int rcnt = 0;
    for (int i = 0; i < n; i++) {
      if (buf[i] && IsLMS(ltypes, buf[i])) buf[rcnt++] = buf[i];
    }
    memset(sub, -1, sub_len * sizeof(int));

    int rank = sub[(buf[0] - 1) >> 1] = 0;
    for (int i = 1; i < rcnt; i++) {
      if (!IsEqual(sv, ltypes, buf[i - 1], buf[i])) ++rank;
      sub[(buf[i] - 1) >> 1] = rank;
    }

    sub_len = remove(sub, sub + sub_len, -1) - sub;
    return rank + 1 == sub_len;
  }

  bool IsLMS(const LTypes& ltypes, int i) {
    return ltypes[i] < ltypes[i - 1];
  }

  template <typename T>
  bool IsEqual(span<const T> sv, const LTypes& ltypes, int i, int j) {
    for (;; i++, j++) {
      if (sv[i] != sv[j] || ltypes[i] != ltypes[j]) return false;
      if (IsLMS(ltypes, i + 1) && IsLMS(ltypes, j + 1)) return sv[i + 1] == sv[j + 1];
    }
  }

 private:
  vector<int> buf;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LCP solver;
  vector<vector<int>> g;
  string org, ans, tmp;
  vector<int> in, out, ids, nxtz, rank;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = n << 1;

    g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x != -1) g[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
      sort(g[i].begin(), g[i].end());
    }

    org.clear();
    org.reserve(m);
    in.resize(n + 1), out.resize(n + 1);
    ids.clear();
    ids.reserve(n);

    [&](this auto&& self, int cur) -> void {
      ids.push_back(cur);
      in[cur] = org.size();
      org.push_back('1');
      for (auto nxt : g[cur]) {
        self(nxt);
      }
      org.push_back('0');
      out[cur] = org.size();
    }(1);

    nxtz.resize(m);
    for (int i = m - 1, j = 0; i >= 0; i--) {
      if (org[i] == '0') {
        j = i;
      } else {
        nxtz[i] = j;
      }
    }

    solver.Init(org);
    auto sa = solver.sa;

    rank.resize(m);
    for (int i = 0; i < m; i++) {
      rank[sa[i]] = i;
    }

    ans.resize(m);
    copy(org.begin(), org.end(), ans.begin());
    int limit = INT_MAX;
    for (auto i : ids) {
      if (g[i].size() <= 1) continue;
      if (limit <= in[i]) break;

      sort(g[i].begin(), g[i].end(), [&](int lhs, int rhs) {
        return rank[in[lhs]] < rank[in[rhs]];
      });

      int fst = g[i][0];
      int val = nxtz[in[fst]] - in[fst] + in[i] + 1;
      if (limit < val) continue;

      int ng = g[i].size();
      bool ok = true;
      for (int j = 1; ok && j < ng; j++) {
        ok = (g[i][j - 1] < g[i][j]);
      }
      if (ok) continue;

      tmp.resize(m);
      copy(org.begin(), org.end(), tmp.begin());
      int idx = in[i] + 1;
      for (auto nxt : g[i]) {
        int st = in[nxt], en = out[nxt];
        for (int j = st; j < en; j++) {
          tmp[idx++] = org[j];
        }
      }

      int pv = 0;
      for (int j = 0; j < m; j++) {
        if (ans[j] == tmp[j]) continue;
        ok = (ans[j] > tmp[j]);
        pv = j;
        break;
      }

      if (ok) ans = move(tmp), limit = pv;
    }

    cout << ans << "\n";
  }

  return 0;
}