// Title : 교수님은 기다리지 않는다
// Link  : https://www.acmicpc.net/problem/3830
// Time  : 332 ms
// Memory: 4104 KB

#include <bits/stdc++.h>

using namespace std;

int parents[100001];      // root는 가장 가벼운 애
int64_t weights[100001];  // parent 와 몸무게 차이

int Find(int id) {
  if (parents[id] == id) return id;
  int par = Find(parents[id]);
  weights[id] += weights[parents[id]];
  return parents[id] = par;
}

void Union(int a, int b, int w) {
  int pa = Find(a), pb = Find(b);
  if (pa == pb) return;
  parents[pb] = pa;
  weights[pb] = weights[a] - weights[b] + w;
}

optional<int64_t> Query(int a, int b) {
  int pa = Find(a), pb = Find(b);
  if (pa != pb) return nullopt;
  return weights[b] - weights[a];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m && n) {
    for (int i = 1; i <= n; i++) {
      parents[i] = i;
      weights[i] = 0;
    }

    while (m--) {
      char op;
      cin >> op;
      if (op == '!') {
        int a, b, w;
        cin >> a >> b >> w;
        Union(a, b, w);
      } else {
        int a, b;
        cin >> a >> b;
        auto res = Query(a, b);
        if (res.has_value()) {
          cout << res.value() << "\n";
        } else {
          cout << "UNKNOWN\n";
        }
      }
    }
  }

  return 0;
}
