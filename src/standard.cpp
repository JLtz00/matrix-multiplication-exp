#include <vector>
using namespace std;

void multiplyStandard(const vector<double> &A, const vector<double> &B, vector<double> &C, int n) {

  for (int i = 0; i < n * n; i++) {
    C[i] = 0.0;
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      double temp = A[i * n + k];
      for (int j = 0; j < n; j++) {
        C[i * n + j] += temp * B[k * n + j];
      }
    }
  }
}
