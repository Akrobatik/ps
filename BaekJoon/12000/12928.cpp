// Title : 트리와 경로의 길이
// Link  : https://www.acmicpc.net/problem/12928
// Time  : 0 ms
// Memory: 2068 KB

#include <bits/stdc++.h>

using namespace std;

int n, s;
int memo[49];
bool visited[49][1001];

bool Traverse(int sum, int rem, int maxx) {
  if (sum > s) return false;
  if (rem == 0) return sum == s;
  if (rem > sum + memo[rem]) return false;
  if (visited[rem][sum]) return false;
  visited[rem][sum] = true;

  maxx = min<int>(maxx, rem);
  for (int i = 1; i <= maxx; i++) {
    if (Traverse(sum + memo[i], rem - i, i)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 48; i++) memo[i] = i * (i + 1) / 2;

  cin >> n >> s;
  cout << (n != 1 && Traverse(0, n - 2, INT_MAX) ? 1 : 0);

  return 0;
}
