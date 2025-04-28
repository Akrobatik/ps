// Title : 라그랑주의 네 제곱수 정리
// Link  : https://www.acmicpc.net/problem/3933 
// Time  : 24 ms
// Memory: 2148 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1 << 15;

int memo[kMax];
vector<int> arr;

void Traverse(int sum, int idx, int cnt) {
  ++memo[sum];
  if (cnt == 4) return;

  for (int i = idx; i < arr.size(); i++) {
    int nxt = sum + arr[i];
    if (nxt >= kMax) break;
    Traverse(nxt, i, cnt + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i * i < kMax; i++) {
    arr.push_back(i * i);
  }
  Traverse(0, 0, 0);

  int n;
  while (cin >> n && n) {
    cout << memo[n] << "\n";
  }

  return 0;
}
