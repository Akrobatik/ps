#include <bits/stdc++.h>

using namespace std;

uint8_t s[21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    char op[7];
    int v;
    cin >> op;
    switch (op[1]) {
      case 'd': {  // add
        cin >> v;
        s[v] |= 1;
      } break;

      case 'e': {  // remove
        cin >> v;
        s[v] ^= s[v];
      } break;

      case 'h': {  // check
        cin >> v;
        cout << (char)('0' + s[v]) << "\n";
      } break;

      case 'o': {  // toggle
        cin >> v;
        s[v] ^= 1;
      } break;

      case 'l': {  // all
        memset(s + 1, 1, 20);
      } break;

      case 'm': {  // empty
        memset(s + 1, 0, 20);
      } break;

      default: {
        // Unreachable
      } break;
    }
  }

  return 0;
}
