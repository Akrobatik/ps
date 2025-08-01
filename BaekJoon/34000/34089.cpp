// Title : Wildcard and Query
// Link  : https://www.acmicpc.net/problem/34089 
// Time  : 220 ms
// Memory: 89244 KB

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
    lcp.resize(n);
    SAIS(span<const char>(sv.data(), n + 1));
    Kasai(sv);
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

constexpr int kMax = 1 << 19;
vector<int> tree[kMax << 1];

int Query(int idx, int x) {
  auto& node = tree[idx];
  auto it = lower_bound(node.begin(), node.end(), x);
  return it != node.end() ? *it : INT_MAX;
}

int Query(int l, int r, int x) {
  int res = INT_MAX;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min<int>(res, Query(l++, x));
    if (r & 1) res = min<int>(res, Query(--r, x));
  }
  return res;
}

int QueryR(int idx, int x) {
  auto& node = tree[idx];
  auto it = lower_bound(node.rbegin(), node.rend(), x, greater<int>());
  return it != node.rend() ? *it : INT_MIN;
}

int QueryR(int l, int r, int x) {
  int res = INT_MIN;
  for (l += kMax, r += kMax + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max<int>(res, QueryR(l++, x));
    if (r & 1) res = max<int>(res, QueryR(--r, x));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int q;
  cin >> s >> q;
  int n = s.size();
  string org = s;

  vector<string> qss(q);
  for (auto& qs : qss) cin >> qs;

  s.push_back('~');
  vector<bool> masks(n + 1);
  vector<int> lens(n + 1);

  auto AppendToken = [&](string_view sv) {
    if (sv.empty()) return 0;
    if (sv.size() > n) return -1;

    int pos = s.size();
    s.append(sv);
    s.push_back('$');
    masks.resize(s.size());
    masks[pos] = true;
    lens.resize(s.size());
    lens[pos] = sv.size();
    return pos;
  };

  vector<vector<int>> tss(q);
  for (int i = 0; i < q; i++) {
    auto& qs = qss[i];
    auto& ts = tss[i];
    int nq = qs.size();
    string_view sv(qs);
    size_t b = 0, e;
    while ((e = sv.find('*', b)) != string::npos) {
      ts.push_back(AppendToken(sv.substr(b, e - b)));
      b = e + 1;
    }
    ts.push_back(AppendToken(sv.substr(b)));
  }

  int m = s.size();

  LCP solver;
  solver.Init(s);
  auto& sa = solver.sa;
  auto& lcp = solver.lcp;
  vector<pair<int, int>> lrs(m);
  vector<int> stk;
  int idx = 0;
  for (int i = 0; i < m; i++) {
    int pos = sa[i];
    int len = lcp[i];
    while (!stk.empty() && len < lens[stk.back()]) {
      lrs[stk.back()].second = idx - 1;
      stk.pop_back();
    }

    if (pos < n) {
      tree[kMax + idx++].push_back(pos);
    } else if (masks[pos]) {
      lrs[pos].first = idx;
      stk.push_back(pos);
    }
  }

  for (int i = kMax - 1; i > 0; i--) {
    auto& mnode = tree[i];
    auto& lnode = tree[i << 1];
    auto& rnode = tree[(i << 1) + 1];
    mnode.resize(lnode.size() + rnode.size());
    merge(lnode.begin(), lnode.end(), rnode.begin(), rnode.end(), mnode.begin());
  }

  vector<int> fwd, bwd;
  for (int i = 0; i < q; i++) {
    auto& ts = tss[i];
    int nt = ts.size();
    if (nt == 1) {
      cout << (qss[i] == org) << "\n";
      continue;
    }

    int fi = 0;
    fwd.assign(nt, INT_MAX);
    for (int j = 0; j < nt; j++) {
      int ti = ts[j];
      if (ti < 0) break;

      int len = lens[ti];
      if (len > 0) {
        auto [l, r] = lrs[ti];
        fi = Query(l, r, fi);
        if (fi == INT_MAX) break;
      }
      fwd[j] = fi;
      fi += len;
    }

    int bi = n;
    bwd.assign(nt, INT_MIN);
    for (int j = nt - 1; j >= 0; j--) {
      int ti = ts[j];
      if (ti < 0) break;

      int len = lens[ti];
      if (len > 0) {
        auto [l, r] = lrs[ti];
        bi = QueryR(l, r, bi - len);
        if (bi == INT_MIN) break;
      }
      bwd[j] = bi;
    }

    bool ok = true, amb = false;
    bool pre = (ts.front() > 0);
    bool suf = (ts.back() > 0);
    if (ok && pre) ok = (fwd[0] == 0);
    if (ok && suf) ok = (bwd[nt - 1] + lens[ts[nt - 1]] == n);
    for (int j = 0; ok && j < nt; j++) {
      ok = (fwd[j] != INT_MAX && bwd[j] != INT_MIN);
    }

    if (ok) {
      bool all = (qss[i].size() + 1 == nt);
      if (!amb) amb = (nt > 2 && all);

      int st = pre ? 1 : 0;
      int en = suf ? nt - 2 : nt - 1;
      for (int j = st; !amb && j <= en; j++) {
        amb = (ts[j] && fwd[j] < bwd[j]);
      }

      if (!amb && !all) {
        st = 0, en = nt - 1;
        while (ts[st] == 0) ++st;
        while (ts[en] == 0) --en;

        if (!amb) amb = (st >= 2 && bwd[st] > 0);
        if (!amb) amb = (en + 2 < nt && fwd[en] + lens[ts[en]] < n);

        int old = st;
        for (int j = st + 1; !amb && j <= en; j++) {
          int ti = ts[j];
          if (ti == 0) continue;

          amb = (old + 1 < j && fwd[old] + lens[ts[old]] < bwd[j]);
          old = j;
        }
      }
    }

    cout << (ok ? (amb ? 2 : 1) : 0) << "\n";
  }

  return 0;
}
