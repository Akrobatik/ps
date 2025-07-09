// Title : N과 M (1)
// Link  : https://www.acmicpc.net/problem/15649 
// Time  : 20 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int arr[8];
bool used[9];

void Traverse(int idx, int maxx, int limit) {
  if (idx == limit) {
    for (int i = 0; i < limit; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= maxx; i++) {
    if (used[i]) continue;
    used[i] = true;
    arr[idx] = i;
    Traverse(idx + 1, maxx, limit);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  Traverse(0, n, k);

  return 0;
}
