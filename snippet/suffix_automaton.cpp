#include <bits/stdc++.h>

using namespace std;

// Suffix Automation
// https://cp-algorithms.com/string/suffix-automaton.html

struct SuffixAutomaton {
  struct State {
    State() : len(0), link(-1), nxt{} {}
    State(int _len, array<int, 26> _nxt) : len(_len), link(-1), nxt(_nxt) {}

    int len, link;
    array<int, 26> nxt;
  };

  SuffixAutomaton() : last(0), ndiffs(0) {
    states.emplace_back();
  }

  void Extend(int c) {
    int cur = AddState(states[last].len + 1, -1);
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
        int clone = AddState(states[p].len + 1, states[q].link, states[q].nxt);
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

  int AddState(int len, int link, const array<int, 26>& nxt = {}) {
    int cur = states.size();
    states.emplace_back(len, nxt);
    SetLink(cur, link);
    return cur;
  }
};
