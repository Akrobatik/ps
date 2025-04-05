// Title : 최소비용 구하기
// Link  : https://www.acmicpc.net/problem/1916
// Time  : 24 ms
// Memory: 4752 KB

#include <bits/stdc++.h>

using namespace std;

struct City {
  City() : min(INT_MAX) {}

  int min;
  vector<pair<int, int>> bus;
};

struct Path {
  auto operator<=>(const Path& rhs) const {
    return weight <=> rhs.weight;
  }

  int pos;
  int weight;
};

City nodes[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    nodes[a].bus.push_back(make_pair(b, c));
  }
  int s, e;
  cin >> s >> e;
  priority_queue<Path, vector<Path>, greater<Path>> pq;
  pq.push(Path{s, 0});
  while (!pq.empty()) {
    auto v = pq.top();
    pq.pop();

    if (v.pos == e) {
      cout << v.weight << endl;
      break;
    }

    if (v.weight < nodes[v.pos].min) {
      nodes[v.pos].min = v.weight;
      for (auto [id, weight] : nodes[v.pos].bus) {
        if (v.weight + weight < nodes[id].min) {
          pq.push(Path{id, v.weight + weight});
        }
      }
    }
  }

  return 0;
}
