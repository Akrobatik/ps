// Title : Lost Civilization
// Link  : https://www.acmicpc.net/problem/33803 
// Time  : 36 ms
// Memory: 6340 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> layers[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    layers[x].push_back(i);
    maxx = max<int>(maxx, x);
  }

  vector<int> arr(layers[0]);
  arr.reserve(n);
  for (int i = 1; i <= maxx; i++) {
    if (arr.size() < i * 2) {
      cout << "-1";
      return 0;
    }
    arr.insert(arr.end(), layers[i].begin(), layers[i].end());
  }

  for (int i = 2; i < n; i += 2) {
    int c1 = arr[i - 2], c2 = arr[i - 1];
    int p1 = arr[i], p2 = arr[min<int>(i + 1, n - 1)];
    cout << c1 << " " << p1 << "\n"
         << c2 << " " << p2 << "\n";
  }

  if (n % 2 == 0) {
    cout << arr[n - 2] << " " << arr[n - 1];
  }

  return 0;
}
