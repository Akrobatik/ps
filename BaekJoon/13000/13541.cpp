// Title : K번째 부분 문자열
// Link  : https://www.acmicpc.net/problem/13541 
// Time  : 60 ms
// Memory: 37500 KB

#include <bits/stdc++.h>

using namespace std;

// Suffix Automation
// https://cp-algorithms.com/string/suffix-automaton.html

struct SuffixAutomaton {
  struct State {
    State() : len(0), link(-1), cnt(0), nxt{} {}
    State(int _len, int64_t _cnt, array<int, 26> _nxt) : len(_len), link(-1), cnt(_cnt), nxt(_nxt) {}

    int len, link;
    int64_t cnt;
    array<int, 26> nxt;
  };

  SuffixAutomaton() : last(0), ndiffs(0) {
    states.emplace_back();
  }

  void Extend(int c) {
    int cur = AddState(states[last].len + 1, -1, 1);
    int p = last;
    while (p != -1 && !states[p].nxt[c]) {
      states[p].nxt[c] = cur;
      p = states[p].link;
    }
    if (p == -1) {
      SetLink(cur, 0);
    } else {
      int q = states[p].nxt[c];
      if (states[p].len + 1 == states[q].len) {
        SetLink(cur, q);
      } else {
        int clone = AddState(states[p].len + 1, states[q].link, 0, states[q].nxt);
        while (p != -1 && states[p].nxt[c] == q) {
          states[p].nxt[c] = clone;
          p = states[p].link;
        }
        SetLink(q, clone), SetLink(cur, clone);
      }
    }
    last = cur;
  }

  int last;
  int64_t ndiffs;
  vector<State> states;

 private:
  void SetLink(int u, int v) {
    auto& st = states[u];
    if (st.link != -1) ndiffs -= st.len - states[st.link].len;
    st.link = v;
    if (st.link != -1) ndiffs += st.len - states[st.link].len;
  }

  int AddState(int len, int link, int64_t cnt, const array<int, 26>& nxt = {}) {
    int cur = states.size();
    states.emplace_back(len, cnt, nxt);
    SetLink(cur, link);
    return cur;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int64_t k;
  cin >> s >> k;

  int64_t all = (int64_t)s.size() * (s.size() + 1) / 2;
  if (all < k) {
    cout << "-1";
    return 0;
  }

  SuffixAutomaton sa;
  sa.states.reserve(s.size() + 1);
  for (auto c : s) sa.Extend(c - 'a');
  auto& states = sa.states;

  int maxx = 0;
  for (auto& st : states) maxx = max<int>(maxx, st.len);

  vector<int64_t> cnts(maxx + 1);
  for (auto& st : states) ++cnts[st.len];
  for (int i = 1; i <= maxx; i++) cnts[i] += cnts[i - 1];

  int ns = states.size();
  vector<int> rank(ns);
  for (int i = ns - 1; i >= 0; i--) rank[--cnts[states[i].len]] = i;

  vector<int64_t> rems(ns);
  for (int i = 0; i < ns; i++) rems[i] = states[i].cnt;
  for (int i = ns - 1; i >= 0; i--) {
    int u = rank[i];
    if (states[u].link == -1) continue;
    rems[states[u].link] += rems[u];
  }

  vector<int64_t> dups(ns, -1);
  [&](this auto&& self, int u) -> int64_t {
    if (dups[u] != -1) return dups[u];

    int64_t res = 0;
    for (auto v : states[u].nxt) {
      if (v == 0) continue;
      res += rems[v];
      res += self(v);
    }
    return dups[u] = res;
  }(0);

  int cur = 0;
  while (k > 0) {
    for (int i = 0; i < 26; i++) {
      int nxt = states[cur].nxt[i];
      if (nxt == 0) continue;
      if (k <= rems[nxt]) {
        cout << (char)('a' + i);
        return 0;
      }
      k -= rems[nxt];

      if (k <= dups[nxt]) {
        cout << (char)('a' + i);
        cur = nxt;
        break;
      }
      k -= dups[nxt];
    }
  }

  return 0;
}
