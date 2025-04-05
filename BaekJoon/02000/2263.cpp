// Title : 트리의 순회
// Link  : https://www.acmicpc.net/problem/2263
// Time  : 28 ms
// Memory: 16736 KB

#include <bits/stdc++.h>

using namespace std;

int in[1000000];
int post[1000000];
int memo[1000001];

void Solve(int ib, int ie, int pb, int pe) {
  if (ib > ie || pb > pe) return;

  int root = post[pe];
  int idx = memo[root];

  cout << root << " ";
  Solve(ib, idx - 1, pb, pb + idx - ib - 1);
  Solve(idx + 1, ie, pb + idx - ib, pe - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> in[i], memo[in[i]] = i;
  for (int i = 0; i < n; i++) cin >> post[i];

  Solve(0, n - 1, 0, n - 1);

  return 0;
}
