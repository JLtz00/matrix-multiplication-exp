#include <cstdlib>
#include <vector>
using namespace std;

vector<double> generateMatrix(int n, int seed) {
  srand(seed);
  vector<double> M(n * n);

  for (int i = 0; i < n * n; i++) {
    M[i] = rand() % 10;
  }

  return M;
}

void add(const vector<double> &A, const vector<double> &B, vector<double> &C, int n) {
  for (int i = 0; i < n * n; i++)
    C[i] = A[i] + B[i];
}

void sub(const vector<double> &A, const vector<double> &B, vector<double> &C, int n) {
  for (int i = 0; i < n * n; i++)
    C[i] = A[i] - B[i];
}

int nextPowerOfTwo(int n) {
  int power = 1;

  while (power < n)
    power <<= 1;

  return power;
}
