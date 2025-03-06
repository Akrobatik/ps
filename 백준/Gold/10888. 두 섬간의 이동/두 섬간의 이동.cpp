#include <bits/stdc++.h>

using namespace std;

int64_t table[100001], table2[100001];
int memo[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    table[i + 1] = table[i] + i;
    table2[i + 1] = table2[i] + table[i + 1];
  }
  for (int i = 1; i <= n; i++) memo[i] = i;

  int64_t np = 0, ns = 0;
  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;

    int ll = memo[u];
    int rr = memo[u + 1];
    int nl = u - ll + 1;
    int nr = rr - u;
    memo[ll] = rr;
    memo[rr] = ll;
    np += table[nl + nr] - table[nl] - table[nr];
    ns += table2[nl + nr] - table2[nl] - table2[nr];
    cout << np << " " << ns << "\n";
  }

  return 0;
}
