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

  vector<int> sizes = {8, 16, 32, 64, 128};
  vector<int> thresholds = {16, 32, 64};
  int repetitions = 101;

  ofstream file("results/results_multi_thresholds5.csv");
  file << "n,standard";
  for (int t : thresholds) {
    file << ", strassen_" << t;
  }
  file << "\n";

  for (int n : sizes) {
    vector<double> A = generateMatrix(n, 1);
    vector<double> B = generateMatrix(n, 2);
    vector<double> C(n * n);

    // Estandar
    vector<double> timeStd;
    for (int i = 0; i < repetitions; i++) {
      timeStd.push_back(measureStandard(A, B, C, n));
    }

    double tStd = median(timeStd);

    // Strassen
    vector<double> resultsStr;
    for (int t : thresholds) {
      vector<double> timeStr;
      for (int i = 0; i < repetitions; i++) {
        timeStr.push_back(measureStrassen(A, B, C, n, t));
      }
      resultsStr.push_back(median(timeStr));
    }

    file << n << "," << tStd;
    for (double val : resultsStr) {
      file << "," << val;
    }
    file << "\n";

    cout << "n=" << n << " done\n";
  }

  file.close();
  return 0;
}
