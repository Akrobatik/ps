// Title : 가위바위보
// Link  : https://www.acmicpc.net/problem/34623 
// Time  : 588 ms
// Memory: 50928 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node(int t, int s, int i) : type(t), sz(s), id(i) {}

  int type, sz, id;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Id = [&](char c) {
    if (c == 'R') return 0;
    if (c == 'S') return 1;
    return 2;
  };

  vector<pair<int, int>> arr;
  vector<bool> out;

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int idx = 0;
    arr.clear();
    while (idx < n) {
      int nxt = idx;
      while (nxt < n && s[idx] == s[nxt]) ++nxt;
      arr.push_back({Id(s[idx]), nxt - idx});
      idx = nxt;
    }
    int na = arr.size();

    for (int o = 0; o < 3; o++) {
      int x = o, y = (o + 1) % 3, z = (o + 2) % 3;

      list<Node> ls;
      for (int i = 0; i < na; i++) {
        ls.push_back({arr[i].first, arr[i].second, i});
      }

      out.assign(na, false);

      using IT = list<Node>::iterator;

      auto Win = [&](IT it, bool left) {
        IT jt;
        if (left) {
          if (it == ls.begin()) return false;
          jt = prev(it);
        } else {
          if (next(it) == ls.end()) return false;
          jt = next(it);
        }
        int iv = it->type, jv = jt->type;
        return (iv + 1) % 3 == jv;
      };

      auto Lose = [&](IT it, bool left) {
        IT jt;
        if (left) {
          if (it == ls.begin()) return false;
          jt = prev(it);
        } else {
          if (next(it) == ls.end()) return false;
          jt = next(it);
        }
        int iv = it->type, jv = jt->type;
        return (iv + 2) % 3 == jv;
      };

      int64_t sum = 0;

      auto Merge = [&](IT it, IT jt) {
        sum += jt->sz;
        it->sz += jt->sz;
        out[jt->id] = true;
        ls.erase(jt);

        if (it != ls.begin()) {
          auto lit = prev(it);
          if (lit->type == it->type) {
            it->sz += lit->sz;
            out[lit->id] = true;
            ls.erase(lit);
          }
        }
        if (next(it) != ls.end()) {
          auto rit = next(it);
          if (rit->type == it->type) {
            it->sz += rit->sz;
            out[rit->id] = true;
            ls.erase(rit);
          }
        }
        return it;
      };

      {
        auto Cmp = [&](const tuple<int, int, IT>& lhs, const tuple<int, int, IT>& rhs) {
          return get<0>(lhs) > get<0>(rhs);
        };

        priority_queue<tuple<int, int, IT>, vector<tuple<int, int, IT>>, decltype(Cmp)> pq(Cmp);

        auto Push = [&](IT it) {
          if (it->type != z) return;
          if (it != ls.begin() && prev(it)->type == y) {
            pq.push({0, it->id, it});
            return;
          }
          if (next(it) != ls.end() && next(it)->type == y) {
            pq.push({0, it->id, it});
            return;
          }

          if (it != ls.begin() && prev(it)->type == x) {
            auto jt = prev(it);
            if (jt != ls.begin() && prev(jt)->type == y) {
              pq.push({jt->sz, jt->id, jt});
            }
          }
          if (next(it) != ls.end() && next(it)->type == x) {
            auto jt = next(it);
            if (next(jt) != ls.end() && next(jt)->type == y) {
              pq.push({jt->sz, jt->id, jt});
            }
          }
        };

        for (auto it = ls.begin(); it != ls.end(); ++it) {
          Push(it);
        }

        while (!pq.empty()) {
          auto [sz, id, it] = pq.top();
          pq.pop();

          if (out[id]) continue;

          if (it->type == z) {
            if (it != ls.begin() && prev(it)->type == y) {
              it = Merge(prev(it), it);
            } else if (next(it) != ls.end() && next(it)->type == y) {
              it = Merge(next(it), it);
            }
          } else if (it->type == x && it->sz == sz) {
            if (it != ls.begin() && next(it) != ls.end()) {
              auto lit = prev(it), rit = next(it);
              if (lit->type != rit->type) {
                if (lit->type == z) {
                  it = Merge(rit, Merge(lit, it));
                } else {
                  it = Merge(lit, Merge(rit, it));
                }
              }
            }
          }

          Push(it);
          if (it != ls.begin()) {
            auto jt = prev(it);
            Push(jt);
            if (jt != ls.begin()) Push(prev(jt));
          }
          if (next(it) != ls.end()) {
            auto jt = next(it);
            Push(jt);
            if (next(jt) != ls.end()) Push(next(jt));
          }
        }
      }

      // cerr << sum << "\n";
      // for (auto [type, sz, id] : ls) cerr << string(sz, (type == 0 ? 'R' : (type == 1 ? 'S' : 'P')));
      // cerr << "\n";

      {
        auto it = ls.begin();
        while (it != ls.end()) {
          if (it->type != y) {
            ++it;
            continue;
          }

          if (Lose(it, true)) {
            auto jt = prev(it);
            it = Merge(jt, it);
          } else if (Lose(it, false)) {
            auto jt = next(it);
            it = Merge(jt, it);
          } else {
            ++it;
          }
        }
      }

      cout << (ls.size() == 1 && ls.begin()->type == x ? sum : -1) << " ";
    }
    cout << "\n";
  }

  return 0;
}