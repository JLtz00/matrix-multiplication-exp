#include <iostream>
#include <vector>
using namespace std;

void multiplyStandard(const vector<double> &, const vector<double> &, vector<double> &, int);
vector<double> generateMatrix(int, int);

int main() {
  int n = 4;

  vector<double> A = generateMatrix(n, 1);
  vector<double> B = generateMatrix(n, 2);
  vector<double> C(n * n);

  multiplyStandard(A, B, C, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << C[i * n + j] << " ";
    }
    cout << endl;
  }

  return 0;
}
