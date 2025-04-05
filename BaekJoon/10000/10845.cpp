// Title : 큐
// Link  : https://www.acmicpc.net/problem/10845
// Time  : 0 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

char op[8];
int q[10000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto b = q;
  auto e = b;
  while (n--) {
    cin >> op;
    switch (*(uint16_t*)op) {
      case 'p' | ('u' << 8): {
        cin >> *e++;
      } break;
      case 'p' | ('o' << 8): {
        cout << (b != e ? *b++ : -1) << "\n";
      } break;
      case 's' | ('i' << 8): {
        cout << e - b << "\n";
      } break;
      case 'e' | ('m' << 8): {
        cout << (char)('0' + (b == e)) << "\n";
      } break;
      case 'f' | ('r' << 8): {
        cout << (b != e ? *b : -1) << "\n";
      } break;
      case 'b' | ('a' << 8): {
        cout << (b != e ? *(e - 1) : -1) << "\n";
      } break;
    }
  }

  return 0;
}
