// Title : A + B Queries
// Link  : https://www.acmicpc.net/problem/34210 
// Time  : 36 ms
// Memory: 6720 KB

#include "aplusb.h"

std::vector<int> AA, BB;

void initialize(std::vector<int> A, std::vector<int> B) {
  AA = move(A), BB = move(B);
}

int answer_question(int i, int j) {
  return AA[i] + BB[j];
}
