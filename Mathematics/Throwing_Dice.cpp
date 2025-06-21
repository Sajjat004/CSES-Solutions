#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T> class MatrixExpo {
public:
  vector<vector<T>> matrix;
  int rows, cols, mod;
  MatrixExpo(int row, int col, int mod) : rows(row), cols(col), mod(mod), matrix(row, vector<T>(col, 0)) {}
  MatrixExpo(const vector<vector<T>>& mat, int mod) : rows(mat.size()), cols(mat[0].size()), mod(mod), matrix(mat) {}
  MatrixExpo(const MatrixExpo& m) : rows(m.rows), cols(m.cols), mod(m.mod), matrix(m.matrix) {}

  MatrixExpo operator+(const MatrixExpo& m) const {
    MatrixExpo result(rows, cols, mod);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result.matrix[i][j] = (matrix[i][j] + m.matrix[i][j]) % mod;
      }
    }
    return result;
  }

  MatrixExpo operator-(const MatrixExpo& m) const {
    MatrixExpo result(rows, cols, mod);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result.matrix[i][j] = (matrix[i][j] - m.matrix[i][j] + mod) % mod;
      }
    }
    return result;
  }

  MatrixExpo operator*(const MatrixExpo& m) const {
    MatrixExpo result(rows, m.cols, mod);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < m.cols; ++j) {
        for (int k = 0; k < cols; ++k) {
          result.matrix[i][j] = (result.matrix[i][j] + (1LL * matrix[i][k] * m.matrix[k][j]) % mod) % mod;
        }
      }
    }
    return result;
  }

  MatrixExpo& operator+=(const MatrixExpo& m) { return *this = *this + m; }
  MatrixExpo& operator-=(const MatrixExpo& m) { return *this = *this - m; }
  MatrixExpo& operator*=(const MatrixExpo& m) { return *this = *this * m; }
  bool operator==(const MatrixExpo& m) const { return matrix == m.matrix; }
  bool operator!=(const MatrixExpo& m) const { return matrix != m.matrix; }

  static MatrixExpo identity(int size, int mod) {
    MatrixExpo idnt(size, size, mod);
    for (int i = 0; i < size; ++i) {
      idnt.matrix[i][i] = 1;
    }
    return idnt;
  }

  MatrixExpo power(T expo) const {
    MatrixExpo result = identity(rows, mod);
    MatrixExpo base = *this;
    while (expo > 0) {
      if (expo & 1) {
        result *= base;
      }
      base *= base;
      expo >>= 1;
    }
    return result;
  }
};

void solution() {
  const int MOD = 1000000007;
  ll n; cin >> n;
  if (n <= 6) {
    cout << (1LL << (n - 1)) % MOD << '\n';
    return;
  }

  vector<vector<ll>> mat = {
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
  };
  MatrixExpo<ll> matrixExpo(mat, MOD);
  MatrixExpo<ll> result = matrixExpo.power(n - 6);
  vector<vector<ll>> base = {{1}, {2}, {4}, {8}, {16}, {32}};
  result = result * MatrixExpo<ll>(base, MOD);

  cout << result.matrix[5][0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1;
  while (tests--) {
    solution();
  }

  return 0;
}

// Problem Link: https://cses.fi/problemset/task/1096/
