#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> vec;
  memo[1] = true;
  vec.push_back(1);
  int i = 0;
  for (; !memo[n]; i++) {
    vector<int> nxt;
    nxt.reserve(vec.size() * 3);
    for (int v : vec) {
      int arr[] = {
          v + 1,
          v * 2,
          v * 3};
      for (int e : arr) {
        if (e > 1000000 || memo[e]) continue;
        memo[e] = true;
        nxt.push_back(e);
      }
    }
    vec.swap(nxt);
  }

  cout << i;

  return 0;
}
