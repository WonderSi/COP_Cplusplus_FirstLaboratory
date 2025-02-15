//
// Created by 011ko on 15.02.2025.
//

#include "../include/Matrix.h"

void Matrix::memoryAllocation() {
    matrix_ = new double *[rows_];
    for (int i = 0;i < rows_; i++) {
        matrix_[i] = new double[cols_];
    }
}

void Matrix::memoryDeallocation() {
    for (int i = 0;i < rows_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}



Matrix::Matrix() {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

Matrix::Matrix(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    memoryAllocation();
}

Matrix::~Matrix() {
    memoryDeallocation();
}

double& Matrix::operator()(int row, int col) {
    if ()
}




