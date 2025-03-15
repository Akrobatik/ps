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
    SAIS(span<const char>(sv.data(), n + 1));
  }

  span<int> sa;

 private:
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

constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 131;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k;
  cin >> s >> k;

  int n = s.size();
  int lc = s[0], li = 0;
  for (int i = 1; i <= n - k; i++) {
    if (lc > s[i]) lc = s[i], li = i;
  }

  if (k == 1) {
    cout << (char)lc;
    return 0;
  }

  string_view sv(s.begin() + li + 1, s.end());
  LCP solver;
  solver.Init(sv);
  auto& sa = solver.sa;

  int ns = sv.size();
  vector<int64_t> h(ns + 1), p(ns + 1);
  p[0] = 1;
  for (int i = 1; i <= ns; i++) {
    p[i] = p[i - 1] * kBase % kMod;
  }

  for (int i = 0; i < ns; i++) {
    h[i + 1] = (h[i] + p[i] * sv[i]) % kMod;
  }

  int mi;
  for (int i = 0; i < ns; i++) {
    if (sa[i] > ns - k + 1) continue;
    mi = sa[i];
    int64_t ih = ((h[sa[i] + k - 2] - h[sa[i]] + kMod) % kMod) * p[ns - sa[i]] % kMod;
    for (int j = i + 1; j < ns; j++) {
      if (sa[j] > ns - k + 1) break;
      int64_t jh = ((h[sa[j] + k - 2] - h[sa[j]] + kMod) % kMod) * p[ns - sa[j]] % kMod;
      if (ih != jh) break;
      mi = min<int>(mi, sa[j]);
    }
    break;
  }

  int rc = sv[mi + k - 2];
  for (int i = mi + k - 1; i < ns; i++) {
    if (rc > sv[i]) rc = sv[i];
  }

  cout << (char)lc << sv.substr(mi, k - 2) << (char)rc;

  return 0;
}
