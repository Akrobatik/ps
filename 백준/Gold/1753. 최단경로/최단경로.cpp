#include <bits/stdc++.h>

using namespace std;

int memo[20001];

struct Path : public pair<int, int> {
  Path(int pos, int cost) : pair<int, int>(make_pair(pos, cost)) {}

  constexpr auto operator<=>(const Path& rhs) const {
    return second <=> rhs.second;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int v, e, s;
  map<int, map<int, int>> m;
  cin >> v >> e >> s;
  for (int i = 1; i <= v; i++) {
    m.insert(make_pair(i, map<int, int>()));
  }
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    auto& mm = m[a];
    if (auto it = mm.find(b); it != mm.end())
      it->second = min<int>(it->second, c);
    else
      mm.insert(make_pair(b, c));
  }

  fill_n(memo, 20001, INT_MAX);
  memo[s] = 0;

  priority_queue<Path, vector<Path>, greater<Path>> pq;
  pq.push(Path(s, 0));
  while (!pq.empty()) {
    auto [pos, cost] = pq.top();
    pq.pop();

    if ((memo[pos] & 0x80000000) == 0) {
      memo[pos] |= 0x80000000;
      auto& mm = m[pos];
      for (auto& elem : m[pos]) {
        if (memo[elem.first] >= 0 && memo[elem.first] > cost + elem.second) {
          memo[elem.first] = cost + elem.second;
          pq.push(Path(elem.first, cost + elem.second));
        }
      }
    }
  }

  for (int i = 1; i <= v; i++) {
    if (memo[i] != INT_MAX)
      cout << (memo[i] & 0x7FFFFFFF) << "\n";
    else
      cout << "INF\n";
  }

  return 0;
}
