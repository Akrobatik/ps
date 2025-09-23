// Title : 근성아 일 좀 하자
// Link  : https://www.acmicpc.net/problem/34410 
// Time  : 24 ms
// Memory: 7228 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node(int _id, int64_t _t, int64_t _w, int64_t _d, int64_t _l, int64_t _r) : id(_id), t(_t), w(_w), d(_d), l(_l), r(_r) {}

  int id;
  int64_t t, w, d, l, r;
};

using tup = tuple<int64_t, list<Node>::iterator, list<Node>::iterator>;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, char>> arr(m);
  for (auto& [p, w, d] : arr) cin >> p >> w >> d;
  sort(arr.begin(), arr.end());

  list<Node> ls;
  ls.push_back(Node(0, 0, kInf, 0, 0, 0));
  for (int i = 1; i <= m; i++) {
    auto [p, w, d] = arr[i - 1];
    ls.push_back(Node(i, 0, w, d == 'R' ? 1 : -1, (p - 1) << 1, p << 1));
  }
  ls.push_back(Node(m + 1, 0, kInf, 0, n << 1, n << 1));

  auto Cmp = [&](const tup& lhs, const tup& rhs) {
    return get<0>(lhs) > get<0>(rhs);
  };

  priority_queue<tup, vector<tup>, decltype(Cmp)> pq(Cmp);

  auto Move = [&](list<Node>::iterator it, int64_t t) {
    int64_t dt = t - it->t;
    if (dt == 0) return;

    it->t += dt;
    it->l += dt * it->d;
    it->r += dt * it->d;
  };

  auto Push = [&](int64_t cur, list<Node>::iterator lit, list<Node>::iterator rit) {
    if (lit->d == rit->d || lit->d == -1 || rit->d == 1) return;

    Move(lit, cur), Move(rit, cur);
    int64_t dist = rit->l - lit->r;
    int64_t velo = abs(lit->d) + abs(rit->d);
    pq.push({cur + dist / velo, lit, rit});
  };

  for (auto rit = next(ls.begin()); rit != ls.end(); ++rit) {
    auto lit = prev(rit);
    Push(0, lit, rit);
  }

  vector<bool> out(m + 2);

  auto Check3 = [&](list<Node>::iterator it, int64_t t) {
    if (it->d != 0) return false;
    if (it == ls.begin() || next(it) == ls.end()) return false;

    auto lit = prev(it), rit = next(it);
    Move(it, t), Move(lit, t), Move(rit, t);
    if (lit->d != 1 || rit->d != -1) return false;
    if (lit->r != it->l || it->r != rit->l) return false;
    return true;
  };

  auto Merge2 = [&](list<Node>::iterator lit, list<Node>::iterator rit, int64_t t) {
    Move(lit, t), Move(rit, t);

    int64_t d = 0;
    if (lit->w > rit->w) d = lit->d;
    if (lit->w < rit->w) d = rit->d;

    lit->d = d;
    lit->w += rit->w;
    lit->r = rit->r;
    out[rit->id] = true;
    ls.erase(rit);
    return lit;
  };

  auto Merge3 = [&](list<Node>::iterator lit, list<Node>::iterator mit, list<Node>::iterator rit, int64_t t) {
    Move(lit, t), Move(mit, t), Move(rit, t);

    int64_t d = 0;
    if (lit->w > rit->w) d = lit->d;
    if (lit->w < rit->w) d = rit->d;
    if (mit->w >= lit->w && mit->w >= rit->w) d = 0;

    mit->d = d;
    mit->w += lit->w + rit->w;
    mit->l = lit->l;
    mit->r = rit->r;
    out[lit->id] = out[rit->id] = true;
    ls.erase(lit), ls.erase(rit);
    return mit;
  };

  int64_t t = 0;
  while (!pq.empty()) {
    auto [ct, lit, rit] = pq.top();
    pq.pop();

    if (out[lit->id] || out[rit->id]) continue;
    t = ct;

    list<Node>::iterator nit;
    if (Check3(lit, t)) {
      nit = Merge3(prev(lit), lit, rit, t);
    } else if (Check3(rit, t)) {
      nit = Merge3(lit, rit, next(rit), t);
    } else {
      nit = Merge2(lit, rit, t);
    }

    if (nit != ls.begin()) Push(t, prev(nit), nit);
    if (next(nit) != ls.end()) Push(t, nit, next(nit));
  }

  int cnt = 0;
  for (auto e : ls) {
    cnt += (e.l != e.r);
  }

  cout << (t >> 1) << "." << ((t & 1) ? 5 : 0) << " " << cnt;

  return 0;
}