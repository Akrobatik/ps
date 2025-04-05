// Title : 스택
// Link  : https://www.acmicpc.net/problem/10828
// Time  : 0 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

char op[8];
int st[10000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto ptr = st;
  while (n--) {
    cin >> op;
    switch (*(uint16_t*)op) {
      case 'p' | ('u' << 8): {
        cin >> *ptr++;
      } break;
      case 'p' | ('o' << 8): {
        cout << (ptr != st ? *--ptr : -1) << "\n";
      } break;
      case 's' | ('i' << 8): {
        cout << ptr - st << "\n";
      } break;
      case 'e' | ('m' << 8): {
        cout << (char)('0' + (ptr == st)) << "\n";
      } break;
      case 't' | ('o' << 8): {
        cout << (ptr != st ? *(ptr - 1) : -1) << "\n";
      } break;
    }
  }

  return 0;
}
