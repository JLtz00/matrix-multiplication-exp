#include <vector>
using namespace std;

void multiplyStandard(const vector<double> &A, const vector<double> &B, vector<double> &C, int n);

void add(const vector<double> &A, const vector<double> &B, vector<double> &C, int n);
void sub(const vector<double> &A, const vector<double> &B, vector<double> &C, int n);
int nextPowerOfTwo(int n);

void strassen(const vector<double> &A, const vector<double> &B, vector<double> &C, int n, int threshold) {

  if (n <= threshold) {
    multiplyStandard(A, B, C, n);
    return;
  }

  int newSize = n / 2;

  // Submatrices
  vector<double> a(newSize * newSize), b(newSize * newSize),
      c(newSize * newSize), d(newSize * newSize),
      e(newSize * newSize), f(newSize * newSize),
      g(newSize * newSize), h(newSize * newSize);

  // Dividir matrices
  for (int i = 0; i < newSize; i++) {
    for (int j = 0; j < newSize; j++) {
      int idx = i * newSize + j;

      a[idx] = A[i * n + j];
      b[idx] = A[i * n + j + newSize];
      c[idx] = A[(i + newSize) * n + j];
      d[idx] = A[(i + newSize) * n + j + newSize];

      e[idx] = B[i * n + j];
      f[idx] = B[i * n + j + newSize];
      g[idx] = B[(i + newSize) * n + j];
      h[idx] = B[(i + newSize) * n + j + newSize];
    }
  }

  // Productos intermedios
  vector<double> P1(newSize * newSize), P2(newSize * newSize),
      P3(newSize * newSize), P4(newSize * newSize),
      P5(newSize * newSize), P6(newSize * newSize),
      P7(newSize * newSize);

  vector<double> temp1(newSize * newSize), temp2(newSize * newSize);

  // P1 = a*(f-h)
  sub(f, h, temp1, newSize);
  strassen(a, temp1, P1, newSize, threshold);

  // P2 = (a+b)*h
  add(a, b, temp1, newSize);
  strassen(temp1, h, P2, newSize, threshold);

  // P3 = (c+d)*e
  add(c, d, temp1, newSize);
  strassen(temp1, e, P3, newSize, threshold);

  // P4 = d*(g-e)
  sub(g, e, temp1, newSize);
  strassen(d, temp1, P4, newSize, threshold);

  // P5 = (a+d)*(e+h)
  add(a, d, temp1, newSize);
  add(e, h, temp2, newSize);
  strassen(temp1, temp2, P5, newSize, threshold);

  // P6 = (b-d)*(g+h)
  sub(b, d, temp1, newSize);
  add(g, h, temp2, newSize);
  strassen(temp1, temp2, P6, newSize, threshold);

  // P7 = (a-c)*(e+f)
  sub(a, c, temp1, newSize);
  add(e, f, temp2, newSize);
  strassen(temp1, temp2, P7, newSize, threshold);

  // Combinar resultados
  vector<double> C11(newSize * newSize), C12(newSize * newSize),
      C21(newSize * newSize), C22(newSize * newSize);

  // C11 = P5 + P4 - P2 + P6
  add(P5, P4, temp1, newSize);
  sub(temp1, P2, temp2, newSize);
  add(temp2, P6, C11, newSize);

  // C12 = P1 + P2
  add(P1, P2, C12, newSize);

  // C21 = P3 + P4
  add(P3, P4, C21, newSize);

  // C22 = P5 + P1 - P3 - P7
  add(P5, P1, temp1, newSize);
  sub(temp1, P3, temp2, newSize);
  sub(temp2, P7, C22, newSize);

  // Unir resultados en C
  for (int i = 0; i < newSize; i++) {
    for (int j = 0; j < newSize; j++) {
      int idx = i * newSize + j;

      C[i * n + j] = C11[idx];
      C[i * n + j + newSize] = C12[idx];
      C[(i + newSize) * n + j] = C21[idx];
      C[(i + newSize) * n + j + newSize] = C22[idx];
    }
  }
}

void strassenWrapper(const vector<double> &A, const vector<double> &B, vector<double> &C, int n, int threshold) {

  int m = nextPowerOfTwo(n);

  // matrices padded
  vector<double> A_pad(m * m, 0.0);
  vector<double> B_pad(m * m, 0.0);
  vector<double> C_pad(m * m, 0.0);

  // copiar datos originales
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A_pad[i * m + j] = A[i * n + j];
      B_pad[i * m + j] = B[i * n + j];
    }
  }

  // ejecutar strassen
  strassen(A_pad, B_pad, C_pad, m, threshold);

  // recortar resultado
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i * n + j] = C_pad[i * m + j];
    }
  }
}
