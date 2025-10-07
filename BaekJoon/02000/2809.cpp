// Title : 아스키 거리
// Link  : https://www.acmicpc.net/problem/2809 
// Time  : 3832 ms
// Memory: 510760 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/suffix_array.cpp
struct SuffixArray {
 private:
  struct Buckets : public vector<int> {
    template <typename T>
    Buckets(span<const T> s) : vector<int>(*max_element(s.begin(), s.end()) + 1) {
      for (auto e : s) ++operator[](e);
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

  struct LTypes : public vector<int8_t> {
    template <typename T>
    LTypes(span<const T> s) : vector<int8_t>(s.size()) {
      int n = s.size();
      for (int i = n - 2; i >= 0; i--) {
        operator[](i) = s[i] > s[i + 1] || (s[i] == s[i + 1] && operator[](i + 1));
      }
    }
  };

 public:
  void Init(string_view s, bool with_lcp) {
    int n = s.size();
    buf.resize(n + 1);
    sa = span<int>(buf.data() + 1, n);
    SAIS(span<const char>(s.data(), n + 1));

    if (with_lcp) {
      lcp.resize(n);
      Kasai(span<const char>(s.data(), n));
    }
  }

  template <typename T>
  void Init(const vector<T>& s, bool with_lcp) {
    int n = s.size();

    vector<T> comp(s.begin(), s.end());
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    tmp.resize(n + 1);
    tmp[n] = 0;
    for (int i = 0; i < n; i++) {
      tmp[i] = upper_bound(comp.begin(), comp.end(), s[i]) - comp.begin();
    }

    buf.resize(n + 1);
    sa = span<int>(buf.data() + 1, n);
    SAIS(span<const T>(tmp));

    if (with_lcp) {
      lcp.resize(n);
      Kasai(span<const T>(tmp.data(), n));
    }
  }

  span<int> sa;
  vector<int> lcp;

 private:
  template <typename T>
  void Kasai(span<const T> s) {
    int n = s.size();
    vector<int> ranks(n);
    for (int i = 0; i < n; i++) ranks[sa[i]] = i + 1;
    for (int i = 0, k = 0; i < n; i++, k && --k) {
      if (ranks[i] == n) {
        k = 0;
        continue;
      }
      int j = sa[ranks[i]];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
      lcp[ranks[i]] = k;
    }
  }

  template <typename T>
  void SAIS(span<const T> s) {
    int n = s.size();
    memset(buf.data(), 0, n * sizeof(int));
    Buckets bkts(s);
    LTypes ltypes(s);
    Sort(s, ltypes, bkts);

    int *sub, sub_len;
    if (!Reduce(s, ltypes, bkts, sub, sub_len)) {
      SAIS(span<const int>(sub, sub_len));
      for (int i = 0; i < sub_len; i++) sub[buf[i]] = i;
    }

    for (int i = 1, j = 0; i < n; i++) {
      if (IsLMS(ltypes, i)) buf[sub[j++]] = -i;
    }
    memset(buf.data() + sub_len, 0, (n - sub_len) * sizeof(int));
    Sort(s, ltypes, sub_len, bkts);
  }

  template <typename T>
  void Sort(span<const T> s, const LTypes& ltypes, Buckets& bkts) {
    int n = s.size();
    auto incl = bkts.Incl();
    for (int i = 1; i < n; i++) {
      if (IsLMS(ltypes, i)) buf[--incl[s[i]]] = i;
    }
    SortLS(s, ltypes, bkts);
  }

  template <typename T>
  void Sort(span<const T> s, const LTypes& ltypes, int lms_len, Buckets& bkts) {
    auto incl = bkts.Incl();
    for (int i = lms_len - 1; i >= 0; i--) buf[--incl[s[-buf[i]]]] = -buf[i];
    SortLS(s, ltypes, bkts);
  }

  template <typename T>
  void SortLS(span<const T> s, const LTypes& ltypes, Buckets& bkts) {
    int n = s.size();
    auto incl = bkts.Incl(), excl = bkts.Excl();

    for (int i = 0; i < n; i++) {
      int pos = buf[i] - 1;
      if (pos >= 0 && ltypes[pos]) buf[excl[s[pos]]++] = pos;
    }

    for (int i = n - 1; i > 0; i--) {
      int pos = buf[i] - 1;
      if (pos >= 0 && !ltypes[pos]) buf[--incl[s[pos]]] = pos;
    }
  }

  template <typename T>
  bool Reduce(span<const T> s, const LTypes& ltypes, const Buckets& bkts, int*& sub, int& sub_len) {
    int n = s.size();
    sub = buf.data() + (n >> 1);
    sub_len = n - (n >> 1);

    int rcnt = 0;
    for (int i = 0; i < n; i++) {
      if (buf[i] && IsLMS(ltypes, buf[i])) buf[rcnt++] = buf[i];
    }
    memset(sub, -1, sub_len * sizeof(int));

    int rank = sub[(buf[0] - 1) >> 1] = 0;
    for (int i = 1; i < rcnt; i++) {
      if (!IsEqual(s, ltypes, buf[i - 1], buf[i])) ++rank;
      sub[(buf[i] - 1) >> 1] = rank;
    }

    sub_len = remove(sub, sub + sub_len, -1) - sub;
    return rank + 1 == sub_len;
  }

  bool IsLMS(const LTypes& ltypes, int i) {
    return ltypes[i] < ltypes[i - 1];
  }

  template <typename T>
  bool IsEqual(span<const T> s, const LTypes& ltypes, int i, int j) {
    for (;; i++, j++) {
      if (s[i] != s[j] || ltypes[i] != ltypes[j]) return false;
      if (IsLMS(ltypes, i + 1) && IsLMS(ltypes, j + 1)) return s[i + 1] == s[j + 1];
    }
  }

  vector<int> buf, tmp;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> s >> m;

  s.push_back('~');
  vector<int> lens(n + 1);
  for (int i = 0; i < m; i++) {
    string tmp;
    cin >> tmp;

    int old = s.size();
    s.append(tmp);
    s.push_back('$');
    lens.resize(s.size());
    lens[old] = tmp.size();
  }

  SuffixArray solver;
  solver.Init(s, true);

  auto& sa = solver.sa;
  auto& lcp = solver.lcp;

  int ns = s.size();
  vector<int> stk;
  for (int i = 0; i < ns; i++) {
    int pos = sa[i], len = lcp[i];
    while (!stk.empty() && len < stk.back()) stk.pop_back();

    if (pos < n) {
      lens[pos] = (stk.empty() ? 0 : stk.back());
    } else if (lens[pos]) {
      stk.push_back(lens[pos]);
    }
  }

  int cnt = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    cur = max<int>(cur, i + lens[i]);
    cnt += (cur == i);
  }
  cout << cnt;

  return 0;
}