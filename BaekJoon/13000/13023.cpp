// Title : ABCDE
// Link  : https://www.acmicpc.net/problem/13023 
// Time  : 248 ms
// Memory: 280144 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[2000];

bool Check(int x, int sz, const array<int, 5>& arr) {
  for (int i = 0; i <= sz; i++) {
    if (x == arr[i]) return false;
  }
  return true;
}

void Check(int id) {
  queue<array<int, 5>> q;
  q.push({id});

  for (int i = 0; !q.empty(); i++) {
    if (i == 4) {
      cout << "1";
      exit(0);
    }

    int nq = q.size();
    while (nq--) {
      auto arr = q.front();
      q.pop();

      int cur = arr[i];
      for (auto nxt : edges[cur]) {
        if (Check(nxt, i, arr)) {
          auto brr = arr;
          brr[i + 1] = nxt;
          q.push(brr);
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    Check(i);
  }

  cout << "0";

  return 0;
}
