#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void multiplyStandard(const vector<double> &A, const vector<double> &B, vector<double> &C, int n);
void strassen(const vector<double> &A, const vector<double> &B, vector<double> &C, int n, int threshold);
vector<double> generateMatrix(int n, int seed);

double measureStandard(const vector<double> &A, const vector<double> &B, vector<double> &C, int n) {
  auto start = chrono::high_resolution_clock::now();
  multiplyStandard(A, B, C, n);
  auto end = chrono::high_resolution_clock::now();

  return chrono::duration<double, milli>(end - start).count();
}

double measureStrassen(const vector<double> &A, const vector<double> &B, vector<double> &C, int n, int threshold) {
  auto start = chrono::high_resolution_clock::now();
  strassen(A, B, C, n, threshold);
  auto end = chrono::high_resolution_clock::now();

  return chrono::duration<double, milli>(end - start).count();
}

double median(vector<double> &v) {
  sort(v.begin(), v.end());
  int size = v.size();

  if (size % 2 == 0)
    return (v[size / 2 - 1] + v[size / 2]) / 2.0;
  else
    return v[size / 2];
}

int main() {

  vector<int> sizes = {2, 4, 8, 16, 32, 64, 128, 256};
  int repetitions = 7;
  int threshold = 32;

  ofstream file("results/results.csv");
  file << "n,standard,strassen\n";

  for (int n : sizes) {

    vector<double> A = generateMatrix(n, 1);
    vector<double> B = generateMatrix(n, 2);
    vector<double> C(n * n);

    vector<double> timesStd;
    vector<double> timesStr;

    for (int i = 0; i < repetitions; i++) {

      timesStd.push_back(measureStandard(A, B, C, n));
      timesStr.push_back(measureStrassen(A, B, C, n, threshold));
    }

    double tStd = median(timesStd);
    double tStr = median(timesStr);

    cout << "n=" << n << " std=" << tStd << " str=" << tStr << endl;

    file << n << "," << tStd << "," << tStr << "\n";
  }

  file.close();
  return 0;
}
