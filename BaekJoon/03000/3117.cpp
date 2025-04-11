// Title : YouTube
// Link  : https://www.acmicpc.net/problem/3117 
// Time  : 116 ms
// Memory: 14144 KB

#include <bits/stdc++.h>

using namespace std;

int start[100001];
int memo[100001][30];

int Find(int id, int rem) {
  if (rem == 0) return id;
  int delta = (int)log2(rem);
  return Find(memo[id][delta], rem - (1 << delta));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, m;
  cin >> n >> k >> m;

  for (int i = 1; i <= n; i++) {
    cin >> start[i];
  }

  for (int i = 1; i <= k; i++) {
    cin >> memo[i][0];
  }

  for (int j = 1; j < 30; j++) {
    for (int i = 1; i <= k; i++) {
      memo[i][j] = memo[memo[i][j - 1]][j - 1];
    }
  }

  for (int i = 1; i <= n; i++){
    cout << Find(start[i], m - 1) << " ";
  }

  return 0;
}
