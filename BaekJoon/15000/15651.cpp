// Title : N과 M (3)
// Link  : https://www.acmicpc.net/problem/15651 
// Time  : 340 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[7];

void Traverse(int idx) {
  if (idx == m) {
    for (int i = 0; i < m; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    arr[idx] = i;
    Traverse(idx + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  Traverse(0);

  return 0;
}
