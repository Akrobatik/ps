#include <bits/stdc++.h>

using namespace std;

int values[8];
int nums[8];

int n, m;

void PrintUnit(int depth, int value) {
  nums[depth] = value;
  if (depth + 1 == m) {
    for (int i = 0; i < m; i++) {
      cout << values[nums[i]] << " ";
    }
    cout << "\n";
    return;
  }

  auto b = begin(nums);
  auto e = b + depth + 1;
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (find(b, e, i) == e && last != values[i]) {
      last = values[i];
      PrintUnit(depth + 1, i);
    }
  }
}

void Print() {
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (last != values[i]) {
      last = values[i];
      PrintUnit(0, i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    values[i] = v;
  }
  sort(begin(values), begin(values) + n);

  Print();

  return 0;
}
