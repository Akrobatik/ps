// Title : Hello World!
// Link  : https://www.acmicpc.net/problem/13140 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

// h w e o l r d
constexpr int kIdx[] = {0, 2, 4, 4, 3, 1, 3, 5, 4, 6};

int n;
int arr[7];
bool used[10];

int Calc() {
  int x = 0;
  for (int i = 0; i < 5; i++) {
    x = x * 10 + arr[kIdx[i]] + arr[kIdx[i + 5]];
  }
  return x;
}

void Traverse(int idx) {
  if (idx == 7) {
    if (Calc() == n) {
      cout << "  ";
      for (int i = 0; i < 5; i++) {
        cout << arr[kIdx[i]];
      }
      cout << "\n+ ";
      for (int i = 5; i < 10; i++) {
        cout << arr[kIdx[i]];
      }
      cout << "\n-------\n";
      cout << setw(7) << setfill(' ') << n;
      exit(0);
    }
    return;
  }

  for (int i = (idx <= 1); i < 10; i++) {
    if (used[i]) continue;
    used[i] = true;
    arr[idx] = i;
    Traverse(idx + 1);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  Traverse(0);
  cout << "No Answer";

  return 0;
}
