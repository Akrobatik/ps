#include <bits/stdc++.h>

using namespace std;

class Graph : public vector<uint8_t> {
 public:
  Graph(int n) : vector<uint8_t>(n * n, 0), n_(n) {}

  uint8_t& at(int y, int x) {
    return operator[](y * n_ + x);
  }

 private:
  int n_;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string line;
  cin >> n;
  Graph g(n);
  for (int i = 0; i < n; i++) {
    cin >> line;
    for (int j = 0; j < n; j++) {
      g.at(i, j) = line[j] == 'Y';
    }
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    vector<uint8_t> v(n, 0);
    for (int j = 0; j < n; j++) {
      if (g.at(i, j)) {
        v[j] = 1;
        for (int k = 0; k < n; k++) {
          if (g.at(j, k) && g.at(i, j)) {
            v[k] = 1;
          }
        }
      }
    }
    v[i] = 0;

    int cur = count_if(v.begin(), v.end(), [](int x) { return x; });
    max = cur > max ? cur : max;
  }

  cout << max;

  return 0;
}