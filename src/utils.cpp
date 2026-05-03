#include <cstdlib>
#include <vector>
using namespace std;

vector<double> generateMatrix(int n, int seed) {
  srand(seed);
  vector<double> M(n * n);

  for (int i = 0; i < n * n; i++) {
    M[i] = rand() % 100;
  }

  return M;
}
