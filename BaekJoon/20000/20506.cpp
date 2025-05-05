// Title : Kaisar - 생존
// Link  : https://www.acmicpc.net/problem/20506 
// Time  : 48 ms
// Memory: 11572 KB

#include <bits/stdc++.h>

using namespace std;

vector<int64_t> memo;
vector<int> edges[200001];

int Traverse(int cur) {
  int64_t all = 0;
  int sum = 0;
  for (auto nxt : edges[cur]) {
    int cnt = Traverse(nxt);
    all -= (int64_t)cnt * cnt;
    sum += cnt;
  }

  ++sum;
  all += (int64_t)sum * sum;
  memo[cur] = all;
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n;
  memo.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) {
      edges[x].push_back(i);
    } else {
      r = i;
    }
  }
  Traverse(r);

  int64_t o = 0, e = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    int64_t cnt = memo[i], half = cnt >> 1;
    o += half * i, e += half * i;
    cur += cnt;
    if (cnt & 1) {
      if (cur & 1) {
        o += i;
      } else {
        e += i;
      }
    }
  }
  cout << e << " " << o;

  return 0;
}
