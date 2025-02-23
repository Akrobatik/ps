#include <bits/stdc++.h>

using namespace std;

char ops[100001];
int nums[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    char _;
    cin >> ops >> n >> _;
    auto nb = nums, ne = nums + n;
    for (int i = 0; i < n; i++) cin >> nums[i] >> _;
    if (!n) cin >> _;

    bool ok = true;
    bool rev = false;
    for (auto ptr = ops; *ptr; ++ptr) {
      if (*ptr == 'R') {
        rev = !rev;
      } else {
        if (nb == ne) {
          ok = false;
          break;
        }
        if (!rev) {
          ++nb;
        } else {
          --ne;
        }
      }
    }

    if (ok) {
      if (nb == ne) {
        cout << "[]\n";
      } else {
        if (!rev) {
          cout << "[" << *nb++;
          while (nb != ne) cout << "," << *nb++;
          cout << "]\n";
        } else {
          cout << "[" << *--ne;
          while (nb != ne) cout << "," << *--ne;
          cout << "]\n";
        }
      }
    } else {
      cout << "error\n";
    }
  }

  return 0;
}
