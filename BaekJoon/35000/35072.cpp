// Title : Arcade Crane
// Link  : https://www.acmicpc.net/problem/35072 
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> qr;
  auto Move = [&](int i, int j) {
    qr.push_back({i, j});
    int val[3] = {arr[i], arr[i + 1], arr[i + 2]};
    arr.erase(arr.begin() + i, arr.begin() + i + 3);
    for (int k = 0; k < 3; k++) {
      arr.insert(arr.begin() + j + k, val[k]);
    }
  };

  for (int x = n; x > 5; x--) {
    int idx = 1;
    while (arr[idx] != x) ++idx;

    if (idx < 3) {
      Move(1, 4 - idx);
      Move(1, x - 2);
    } else {
      Move(idx - 2, x - 2);
    }
  }

  auto Check = [&]() {
    for (int i = 1; i <= 5; i++) {
      if (arr[i] != i) return false;
    }
    return true;
  };

  mt19937 gen(random_device{}());
  while (!Check()) {
    int a = gen() % 3 + 1, b = gen() % 3 + 1;
    while (a == b) b = gen() % 3 + 1;
    Move(a, b);
  }

  cout << qr.size() << "\n";
  for (auto [i, j] : qr) cout << i << " " << j << "\n";

  return 0;
}