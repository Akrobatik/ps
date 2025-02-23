#include <bits/stdc++.h>

using namespace std;

int D(int n) {
  return (n << 1) % 10000;
}

int S(int n) {
  return n ? n - 1 : 9999;
}

int L(int n) {
  return (n % 1000 / 100) * 1000  //
         + (n % 100 / 10) * 100   //
         + (n % 10) * 10          //
         + (n / 1000);
}

int R(int n) {
  return (n % 10) * 1000          //
         + (n / 1000) * 100       //
         + (n % 1000 / 100) * 10  //
         + (n % 100 / 10);
}

const pair<char, int (*)(int)> kOps[] = {
    {'D', D},
    {'S', S},
    {'L', L},
    {'R', R},
};

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

      for (auto [op, fn] : kOps) {
        int nxt = fn(cur);
        if (visited[nxt]) continue;
        visited[nxt] = true;
        ops[nxt] = op;
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
