//
// Created by 011ko on 15.02.2025.
//

#include "../include/Matrix.h"

// Memory
void Matrix::memoryAllocation() {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
    }
}

void Matrix::memoryDeallocation() {
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}


// Constructor | Destructor
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

// Operation
bool Matrix::EqMatrix(const IMatrix &other) {
    if (rows_ != other.getRows() || cols_ != other.getCols()) {
        return false;
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (matrix_[i][j] != other(i, j)) {
                return false;
            }
        }
    }
}

void Matrix::SumMatrix(const IMatrix &other) {
    if (rows_ != other.getRows() || cols_ != other.getCols()) {
        throw std::invalid_argument("Different dimensions of the matrices");
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] += other(i, j);
        }
    }
}

void Matrix::SubMatrix(const IMatrix &other) {
    if (rows_ != other.getRows() || cols_ != other.getCols()) {
        throw std::invalid_argument("Different dimensions of the matrices");
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] -= other(i, j);
        }
    }
}

void Matrix::MulNumber(const double num) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] *= num;
        }
    }
};

void Matrix::MulMatrix(const IMatrix &other) {
    if (cols_ != other.getRows()) {
        throw std::invalid_argument(
                "The number of columns of the first matrix is not equal to the number of columns of the second matrix");
    }
    Matrix result(rows_, other.getCols());
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.getCols(); ++j) {
            for (int k = 0; k < cols_; ++k) {
                result.matrix_[i][j] += matrix_[i][k] * other(k, j);
            }
        }
    }
    *this = result; //???
};

IMatrix* Matrix::Transpose() {
    Matrix* result = new Matrix(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result->matrix_[j][i] = matrix_[i][j];
        }
    }
    return result;
}

// Operator
double &Matrix::operator()(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::out_of_range("out_of_range");
    }
    return matrix_[row][col];
}

const double &Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::out_of_range("out_of_range");
    }
    return matrix_[row][col];
}




