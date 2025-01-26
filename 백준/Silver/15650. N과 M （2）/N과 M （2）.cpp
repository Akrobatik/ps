#include <bits/stdc++.h>

using namespace std;

int nums[8];

int n, m;

void PrintUnit(int depth, int value) {
  nums[depth] = value;
  if (depth + 1 == m) {
    for (int i = 0; i < m; i++) {
      cout << nums[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = value + 1; i <= n; i++) {
    PrintUnit(depth + 1, i);
  }
}

void Print() {
  for (int i = 1; i <= n; i++) {
    PrintUnit(0, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  Print();

  return 0;
}
