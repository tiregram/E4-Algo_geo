#pragma once

#include "myVector3D.hpp"

// matrix
typedef double (*TYPE3x3)[3];

double get_det_of_matrix(double s[3][3]);
TYPE3x3 solve_matrix(double s[3][3]);
void set_c_of_matrix(TYPE3x3 m , int c, double* l);
void print_matrix(TYPE3x3 f );
double*  operator*(TYPE3x3 m , const myVector3D& l);
