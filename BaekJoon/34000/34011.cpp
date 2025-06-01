// Title : 꽁꽁 얼어붙은 트리
// Link  : https://www.acmicpc.net/problem/34011 
// Time  : 584 ms
// Memory: 92748 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[1000001];
int memo[1000001];
bool seive[1000001];
int maxd;

void Traverse(int cur, int depth) {
  maxd = max<int>(maxd, depth);
  ++memo[depth];
  for (auto nxt : edges[cur]) {
    Traverse(nxt, depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    edges[x].push_back(i);
  }

  Traverse(1, 0);

  int maxx = 1;
  for (int i = 2; i <= n; i++) {
    if (seive[i]) continue;

    int cur = 0;
    for (int j = 0; j <= maxd; j += i) {
      cur += memo[j];
      seive[j] = true;
    }
    maxx = max<int>(maxx, cur);
  }
  cout << maxx;

  return 0;
}
