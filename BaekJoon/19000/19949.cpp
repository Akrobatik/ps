// Title : 영재의 시험
// Link  : https://www.acmicpc.net/problem/19949 
// Time  : 28 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int cnt;
int ans[10], memo[10];

void Traverse(int idx, int score) {
  if (idx == 10) {
    cnt += (score >= 5);
    return;
  }

  for (int i = 1; i <= 5; i++) {
    if (idx >= 2 && memo[idx - 2] == i && memo[idx - 1] == i) continue;
    memo[idx] = i;
    Traverse(idx + 1, score + (ans[idx] == memo[idx]));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (auto& e : ans) cin >> e;
  Traverse(0, 0);
  cout << cnt;

  return 0;
}
