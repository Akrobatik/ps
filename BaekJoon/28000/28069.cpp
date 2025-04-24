// Title : 김밥천국의 계단
// Link  : https://www.acmicpc.net/problem/28069 
// Time  : 12 ms
// Memory: 3524 KB

#include <bits/stdc++.h>

using namespace std;

bool check[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  queue<int> q;
  check[0] = true;
  q.push(0);
  for (int i = 0; !q.empty() && i < k; i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      for (auto nxt : {cur + 1, cur + cur / 2}) {
        if (nxt == n) {
          cout << "minigimbob";
          return 0;
        } else if (nxt < n && !check[nxt]) {
          check[nxt] = true;
          q.push(nxt);
        }
      }
    }
  }

  cout << "water";

  return 0;
}
