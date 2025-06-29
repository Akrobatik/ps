// Title : 이진 탐색 트리 복원하기
// Link  : https://www.acmicpc.net/problem/18240 
// Time  : 120 ms
// Memory: 54628 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[300001], layers[300001];
int memo[300001];

int Traverse(int cur, int st) {
  int sum = 1, cnt = -1;
  for (auto nxt : edges[cur]) {
    int x = Traverse(nxt, cnt == -1 ? st : st + cnt + 1);
    if (cnt == -1) cnt = x;
    sum += x;
  }
  if (cnt == -1) cnt = 0;
  memo[cur] = st + cnt;
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  layers[0].push_back(1);
  layers[0].push_back(1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    if (layers[x - 1].empty()) {
      cout << "-1";
      return 0;
    }
    edges[layers[x - 1].back()].push_back(i);
    layers[x - 1].pop_back();
    layers[x].push_back(i);
    layers[x].push_back(i);
  }

  Traverse(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << memo[i] << " ";
  }

  return 0;
}