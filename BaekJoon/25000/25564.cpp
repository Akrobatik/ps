// Title : 역삼역
// Link  : https://www.acmicpc.net/problem/25564 
// Time  : 64 ms
// Memory: 13612 KB

#include <bits/stdc++.h>

using namespace std;

struct Manacher {
  void Init(string_view sv) {
    int n = (sv.size() << 1) + 1;
    table.clear(), table.resize(n);

    string s(n, '\0');
    auto ptr = s.data() + 1;
    for (char c : sv) *ptr = c, ptr += 2;

    int p, r = 0;
    for (int i = 1; i < n - 1; i++) {
      if (i > r) {
        p = r = i;
        while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
        table[i] = --r - p;
      } else {
        if (table[(p << 1) - i] < r - i) {
          table[i] = table[(p << 1) - i];
        } else if (table[(p << 1) - i] > r - i) {
          table[i] = r - i;
        } else {
          p = i;
          while (r < n && r <= (p << 1) && s[r] == s[(p << 1) - r]) ++r;
          table[i] = --r - p;
        }
      }
    }
  }

  vector<int> table;
};

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  Manacher mnchr;
  mnchr.Init(s);
  auto& table = mnchr.table;

  LCP sais;
  sais.Init(s);
  auto& lcp = sais.lcp;
  auto& sa = sais.sa;

  vector<int> memo(n, n);
  for (int i = 0; i < table.size(); i++) {
    int limit = ((table[i] & 1) == (k & 1) ? k : k + 1);
    if (table[i] >= limit) {
      int b = (i - limit) >> 1;
      memo[b] = min<int>(memo[b], b + limit - 1);
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    memo[i] = min<int>(memo[i], memo[i + 1]);
  }

  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int b = sa[i];
    int minn = max<int>(memo[b] - b + 1, lcp[i] + 1);
    int maxx = n - b;
    ans += max<int>(maxx - minn + 1, 0);
  }
  cout << ans;

  return 0;
}
