// Title : 배
// Link  : https://www.acmicpc.net/problem/1092
// Time  : 4 ms
// Memory: 2184 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n1, n2;
  vector<int> cranes;
  vector<int> boxes;

  cin >> n1;
  cranes.resize(n1);
  for (int i = 0; i < n1; i++) {
    int v;
    cin >> v;
    cranes[i] = v;
  }
  sort(cranes.begin(), cranes.end(), greater<int>());

  cin >> n2;
  boxes.resize(n2);
  for (int i = 0; i < n2; i++) {
    int v;
    cin >> v;
    boxes[i] = v;
  }
  sort(boxes.begin(), boxes.end(), greater<int>());

  int result = -1;
  if (cranes.front() >= boxes.front()) {
    vector<int> offsets(cranes.size(), 0);
    result = 0;
    while (!boxes.empty()) {
      result++;
      for (int i = 0; i < cranes.size(); i++) {
        int c = cranes[i];
        int o = offsets[i];
        if (o >= 0) {
          bool erase = false;
          for (int j = o; j < boxes.size(); j++) {
            if (c >= boxes[j]) {
              boxes.erase(boxes.begin() + j);
              offsets[i] = j;
              for (int k = i + 1; k < cranes.size(); k++) {
                if (offsets[k] > 0) offsets[k]--;
              }
              erase = true;
              break;
            }
          }
          if (!erase) offsets[i] = -1;
        }
      }
    }
  }

  cout << result << "\n";

  return 0;
}