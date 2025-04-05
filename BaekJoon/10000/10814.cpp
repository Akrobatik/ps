// Title : 나이순 정렬
// Link  : https://www.acmicpc.net/problem/10814
// Time  : 32 ms
// Memory: 17880 KB

#include <bits/stdc++.h>

using namespace std;

struct Man {
  char name[101];
};

vector<Man> mans[201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int age;
    cin >> age;
    auto& man = mans[age].emplace_back();
    cin >> man.name;
  }
  for (int i = 1; i <= 200; i++) {
    for (auto& man : mans[i]) cout << i << " " << man.name << "\n";
  }
  return 0;
}
