// Title : DSLR
// Link  : https://www.acmicpc.net/problem/9019
// Time  : 744 ms
// Memory: 2312 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int D(int n) {
  return n * 2 % 10000;
}

constexpr int S(int n) {
  return n ? n - 1 : 9999;
}

constexpr int L(int n) {
  return (n % 1000 / 100) * 1000  //
         + (n % 100 / 10) * 100   //
         + (n % 10) * 10          //
         + (n / 1000);
}

constexpr int R(int n) {
  return (n % 10) * 1000          //
         + (n / 1000) * 100       //
         + (n % 1000 / 100) * 10  //
         + (n % 100 / 10);
}

constexpr array<int[4], 10000> kTable = []() {
  array<int[4], 10000> arr{};
  for (int i = 0; i < 10000; i++) {
    arr[i][0] = D(i);
    arr[i][1] = S(i);
    arr[i][2] = L(i);
    arr[i][3] = R(i);
  }
  return arr;
}();

constexpr const char* kOps = "DSLR";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    char ops[10000] = {};
    bool visited[10000] = {};
    int memo[10000];
    iota(memo, memo + 10000, 0);

    queue<int> q;
    visited[a] = true;
    q.push(a);
    while (!visited[b]) {
      auto cur = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        auto nxt = kTable[cur][i];
        if (visited[nxt]) continue;
        visited[nxt] = true;
        ops[nxt] = kOps[i];
        memo[nxt] = cur;
        q.push(nxt);
      }
    }

    string ans;
    while (b != memo[b]) {
      ans.push_back(ops[b]);
      b = memo[b];
    }

    for (auto c : views::reverse(ans)) cout << c;
    cout << "\n";
  }

  return 0;
}
