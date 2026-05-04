#include <iostream>
#include <vector>

#define THRESHOLD 32
using namespace std;

void strassen(const vector<double> &A, const vector<double> &B, vector<double> &C, int n, int threshold);
void multiplyStandard(const vector<double> &, const vector<double> &, vector<double> &, int);
vector<double> generateMatrix(int, int);

int main() {
  int n = 64;

  vector<double> A = generateMatrix(n, 1);
  vector<double> B = generateMatrix(n, 2);
  vector<double> C(n * n);

  strassen(A, B, C, n, THRESHOLD);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << C[i * n + j] << " ";
    }
    cout << endl;
  }

  return 0;
}
