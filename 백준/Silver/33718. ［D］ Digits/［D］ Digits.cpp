#include <bits/stdc++.h>

using namespace std;

using Op = int64_t (*)(int64_t, int64_t);

int64_t Add(int64_t a, int64_t b) {
  return a + b;
}

int64_t Sub(int64_t a, int64_t b) {
  return a - b;
}

int64_t Mul(int64_t a, int64_t b) {
  return a * b;
}

int64_t Div(int64_t a, int64_t b) {
  return b && a % b == 0 ? a / b : 0;
}

Op ops[4] = {
    Add, Sub, Mul, Div};

char cops[4] = {
    '+', '-', '*', '/'};

int64_t t;
int an;
tuple<int64_t, int64_t, int64_t, char> ans[5];

void Sort(array<int64_t, 6>& arr, int n) {
  bool ok = true;
  for (int i = 0; ok && i < n - 1; i++) {
    ok = false;
    for (int j = 0; j < n - i; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        ok = true;
      }
    }
  }
}

bool Traverse(array<int64_t, 6> arr, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == t) {
      an = 6 - n;
      return true;
    }
  }

  if (n == 1) return false;

  Sort(arr, n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      array<int64_t, 6> nxt{};
      auto it = nxt.begin();
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        *it++ = arr[k];
      }
      for (int k = 0; k < 4; k++) {
        int64_t x = ops[k](arr[i], arr[j]);
        if (x <= 0) continue;
        *it = x;
        ans[6 - n] = {arr[i], arr[j], x, cops[k]};
        if (Traverse(nxt, n - 1)) return true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  array<int64_t, 6> arr;
  for (auto& e : arr) cin >> e;
  if (Traverse(arr, 6)) {
    cout << an << "\n";
    for (int i = 0; i < an; i++) {
      auto [a, b, c, op] = ans[i];
      cout << a << " " << op << " " << b << " = " << c << "\n";
    }
  } else {
    cout << "-1";
  }

  return 0;
}
