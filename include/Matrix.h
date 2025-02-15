//
// Created by 011ko on 15.02.2025.
//

#ifndef COP_CPLUSPLUS_FIRSTLABORATORY_MATRIX_H
#define COP_CPLUSPLUS_FIRSTLABORATORY_MATRIX_H

#endif //COP_CPLUSPLUS_FIRSTLABORATORY_MATRIX_H

#pragma once

#include <iostream>

class Matrix {
private :
    int rows_, cols_;
    double **matrix;

public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();
};