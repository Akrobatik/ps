// Title : 감소하는 수
// Link  : https://www.acmicpc.net/problem/1038 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  queue<int64_t> q;
  for (int i = 0; i < 10; i++) {
    q.push(i);
  }

  int64_t result = -1;
  int nn = 0;
  while (!q.empty()) {
    int64_t v = q.front();
    q.pop();

    if (nn++ == n) {
      result = v;
      break;
    }

    for (int i = 0; i < v % 10; i++) {
      q.push(v * 10 + i);
    }
  }

  cout << result << endl;

  return 0;
}