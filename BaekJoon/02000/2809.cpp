// Title : 아스키 거리
// Link  : https://www.acmicpc.net/problem/2809 
// Time  : 2956 ms
// Memory: 239292 KB

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

// https://github.com/Akrobatik/ps/blob/main/template/modint.cpp
template <int32_t MOD>
struct ModInt32 {
  using CT = conditional_t<MOD <= numeric_limits<int32_t>::max() / 2, int32_t, int64_t>;

  constexpr ModInt32() : val(0) {}
  constexpr ModInt32(int32_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt32(int64_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}
  constexpr ModInt32(__int128_t x) : val((x %= MOD) < 0 ? x + MOD : x) {}

  constexpr ModInt32 Pow(int64_t exp) const {
    int64_t n = val, x = 1;
    while (exp) {
      if (exp & 1) x = x * n % MOD;
      n = n * n % MOD;
      exp >>= 1;
    }

    ModInt32 res;
    res.val = x;
    return res;
  }

  constexpr ModInt32 Inv() const {
    return Pow(MOD - 2);
  }

  constexpr ModInt32& operator++() {
    if (++val == MOD) val = 0;
    return *this;
  }

  constexpr ModInt32 operator++(int) {
    ModInt32 tmp(*this);
    operator++();
    return tmp;
  }

  constexpr ModInt32& operator+=(const ModInt32& other) {
    CT x = (CT)val + other.val;
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator-=(const ModInt32& other) {
    CT x = (CT)val + (MOD - other.val);
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }

  constexpr ModInt32& operator*=(const ModInt32& other) {
    val = (int64_t)val * other.val % MOD;
    return *this;
  }

  constexpr ModInt32& operator/=(const ModInt32& other) {
    *this *= other.Inv();
    return *this;
  }

  constexpr ModInt32 operator-() const {
    ModInt32 res;
    if (val) res.val = MOD - val;
    return res;
  }

  constexpr ModInt32 operator+(const ModInt32& rhs) const {
    return ModInt32(*this) += rhs;
  }

  constexpr ModInt32 operator-(const ModInt32& rhs) const {
    return ModInt32(*this) -= rhs;
  }

  constexpr ModInt32 operator*(const ModInt32& rhs) const {
    return ModInt32(*this) *= rhs;
  }

  constexpr ModInt32 operator/(const ModInt32& rhs) const {
    return ModInt32(*this) /= rhs;
  }

  constexpr bool operator!() const {
    return val == 0;
  }

  friend istream& operator>>(istream& is, ModInt32& num) {
    is >> num.val;
    if ((num.val %= MOD) < 0) num.val += MOD;
    return is;
  }

  friend ostream& operator<<(ostream& os, const ModInt32& num) {
    os << num.val;
    return os;
  }

  int32_t val;
};

template <int32_t MOD1, int32_t BASE1, int32_t MOD2, int32_t BASE2>
struct PolyHash {
  using M1 = ModInt32<MOD1>;
  using M2 = ModInt32<MOD2>;

  PolyHash() : b1(BASE1), b2(BASE2), p1{1}, p2{1}, r1{1}, r2{1}, h1{0}, h2{0} {}

  void Init(string_view sv) {
    n = sv.size();
    int old = p1.size();
    p1.resize(n + 1), p2.resize(n + 1);
    for (int i = old; i <= n; i++) {
      p1[i] = p1[i - 1] * b1;
      p2[i] = p2[i - 1] * b2;
    }

    r1.resize(n + 1), r2.resize(n + 1);
    r1[n] = p1[n].Inv(), r2[n] = p2[n].Inv();
    for (int i = n - 1; i >= old; i--) {
      r1[i] = r1[i + 1] * b1;
      r2[i] = r2[i + 1] * b2;
    }

    h1.resize(n + 1), h2.resize(n + 1);
    for (int i = 0; i < n; i++) {
      int x = (int)sv[i] + 1;
      h1[i + 1] = h1[i] + p1[i] * x;
      h2[i + 1] = h2[i] + p2[i] * x;
    }
  }

  bool Match(int i, int j, int len) {
    if (i + len > n || j + len > n) return false;
    return GetHash(i, len) == GetHash(j, len);
  }

  int64_t GetHash(int i, int len) {
    if (i + len > n) return -1;
    M1 x1 = h1[i + len] - h1[i];
    M2 x2 = h2[i + len] - h2[i];
    x1 *= r1[i];
    x2 *= r2[i];
    return (((int64_t)x1.val) << 32) | x2.val;
  }

 private:
  int n;
  M1 b1;
  M2 b2;
  vector<M1> p1, h1, r1;
  vector<M2> p2, h2, r2;
};

constexpr int kMod1 = 1e9 + 7;
constexpr int kBase1 = 337;
constexpr int kMod2 = 1e9 + 9;
constexpr int kBase2 = 331;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> s >> m;

  PolyHash<kMod1, kBase1, kMod2, kBase2> ph, ph2;
  ph.Init(s);

  s.push_back('~');
  vector<int16_t> lens(n + 1);
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
  solver.Init(s, false);

  auto& sa = solver.sa;
  auto& lcp = solver.lcp;

  int ns = s.size();
  vector<pair<int, int64_t>> stk;
  for (int i = 0; i < ns; i++) {
    int pos = sa[i];
    if (pos < n) {
      while (!stk.empty() && ph.GetHash(pos, lens[stk.back().first]) != stk.back().second) stk.pop_back();
      lens[pos] = (stk.empty() ? 0 : lens[stk.back().first]);
    } else if (lens[pos]) {
      string_view sv = s;
      ph2.Init(sv.substr(pos, lens[pos]));
      stk.push_back({pos, ph2.GetHash(0, lens[pos])});
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