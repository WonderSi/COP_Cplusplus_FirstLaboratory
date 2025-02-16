//
// Created by 011ko on 15.02.2025.
//

#include "../include/Matrix.h"
#include "../include/IMatrix.h"

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
    matrix_ = nullptr;
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

Matrix::Matrix(const Matrix& other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    memoryAllocation();
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

Matrix::~Matrix() {
    memoryDeallocation();
}

// Setter / Getter
IMatrix* Matrix::getMinor(int rows, int cols) {
    if (rows < 0 || rows >= rows_ || cols < 0 || cols >= cols_) {
        throw std::out_of_range("out_of_range");
    }
    Matrix* minor = new Matrix(rows_ - 1, cols_ - 1);
    int ind_i = 0;
    for (int i = 0; i < rows_; ++i) {
        if (rows == i) { continue; }
        int ind_j = 0;
        for (int j = 0; j < cols_; ++j) {
            if (cols == j) { continue; }
            minor->matrix_[ind_i][ind_j] = matrix_[i][j];
            ind_j++;
        }
        ind_i++;
    }
    return minor;
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
    return true;
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

IMatrix *Matrix::Transpose() {
    Matrix *result = new Matrix(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result->matrix_[j][i] = matrix_[i][j];
        }
    }
    return result;
}

IMatrix *Matrix::CalcComplements() {
    if (rows_ != cols_) {
        throw std::invalid_argument("The matrix is not square");
    }
    Matrix* calcComplementsMatrix = new Matrix(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            IMatrix* minor = getMinor(i, j);
            double minorDet = minor->Determinant();
            calcComplementsMatrix->matrix_[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minorDet;
            delete minor;
        }
    }
    return calcComplementsMatrix;
}

double Matrix::Determinant() {
    if (rows_ != cols_) {
        throw std::invalid_argument("The matrix is not square");
    }
    Matrix temp(*this); // Copy
    double det = 1;
    for (int i = 0; i < rows_; ++i) {
        if (matrix_[i][i] == 0) {
            bool swapped = false;
            for (int k = 0; k < rows_; ++k) {
                if (matrix_[k][i] != 0) {
                    std::swap(matrix_[k], matrix_[i]);
                    det *= -1;
                    swapped = true;
                }
            }
            if (!swapped) { return 0; };
        }
        det *= temp.matrix_[i][i];
        for (int j = i + 1; j < rows_; ++j) {
            double factor = temp.matrix_[j][i]/temp.matrix_[i][i];
            for (int k = 0; k < cols_; ++k) {
                temp.matrix_[j][k] -= factor * temp.matrix_[i][k];
            }
        }
    }
    return det;
};

IMatrix* Matrix::InverseMatrix() {
    double det = Determinant();
    if (det == 0) {
        throw std::logic_error("Determinant is zero");
    }
    IMatrix* complement = CalcComplements();
    IMatrix* transpose = complement->Transpose();
    transpose->MulNumber(1 / det);
    delete complement;
    return transpose;
};

// Operator
IMatrix* Matrix::operator+(const IMatrix& other) const {
    if (getRows() != other.getRows() || getCols() != other.getCols()) {
        throw std::invalid_argument("Matrices dimensions must match for addition");
    }
    IMatrix *result = new Matrix(getRows(), getCols());
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            (*result)(i, j) = (*this)(i,j) + other(i, j);
        }
    }
    return result;
};

IMatrix* Matrix::operator-(const IMatrix& other) const {
    if (getRows() != other.getRows() || getCols() != other.getCols()) {
        throw std::invalid_argument("Matrices dimensions must match for addition");
    }
    IMatrix *result = new Matrix(getRows(), getCols());
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            (*result)(i, j) = (*this)(i,j) - other(i, j);
        }
    }
    return result;
};

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




