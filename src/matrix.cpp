#include "matrix.hpp"

#include <iostream>



const int fp[3] = {1, 0, 0};
const int lp[3] = {2, 2, 1};

double get_det_of_matrix(double s[3][3]) {
  double d;
  for (int j = 0; j < 3; j++) {
    double val =
      s[fp[0]][fp[j]] * s[lp[0]][lp[j]] - s[fp[0]][lp[j]] * s[lp[0]][fp[j]];
    d += val * s[0][j];
  }

  return d;
}

TYPE3x3 solve_matrix(double s[3][3]) {
  const int N = 3;
  auto ret = new double[3][3]();
  double det = get_det_of_matrix(s);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ret[i][j] = (s[fp[i]][fp[j]] * s[lp[i]][lp[j]] -
                   s[fp[i]][lp[j]] * s[lp[i]][fp[j]]) /
        det;
    }
  }

  return ret;
}

void set_c_of_matrix(TYPE3x3 m, int c, double *l) {
  for (int i = 0; i < 3; i++) {
    m[c][i] = l[i];
  }
}

void print_matrix(TYPE3x3 f) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << f[j][i] << ", ";
    }
    std::cout << "\n";
  }
}

double *operator*(TYPE3x3 m, const myVector3D &l) {
  auto ret = new double[3];

  for (int i = 0; i < 3; i++) {
    ret[i] = m[i][0] * l.components[0] + m[i][1] * l.components[1] +
      m[i][2] * l.components[2];
  }
  return ret;
}
