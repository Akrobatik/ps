// Title : 정수 a를 k로 만들기
// Link  : https://www.acmicpc.net/problem/25418 
// Time  : 8 ms
// Memory: 3524 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, k;
  cin >> a >> k;

  queue<int> q;
  visited[a] = true;
  q.push(a);
  for (int i = 0;; i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      if (cur == k) {
        cout << i;
        return 0;
      }

      for (auto nxt : {cur + 1, cur << 1}) {
        if (nxt <= k && !visited[nxt]) {
          visited[nxt] = true;
          q.push(nxt);
        }
      }
    }
  }

  return 0;
}
