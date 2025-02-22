//
// Created by 011ko on 15.02.2025.
//

#pragma once
#include "IMatrix.h"
#include <iostream>

class Matrix : public IMatrix {
private :
    int rows_, cols_;
    double **matrix_;

    void memoryAllocation();
    void memoryDeallocation();
public:
    // Constructor / Destructor
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    ~Matrix();

    // Setter / Getter
    int getRows() const override {
        return rows_;
    };
    int getCols() const override {
        return cols_;
    };
    void setRows (int rows) override;
    void setCols (int cols) override;
    IMatrix* getMinor(int rows, int cols) override;

    // Operation
    bool EqMatrix(const IMatrix& other) const override;
    void SumMatrix(const IMatrix& other) override;
    void SubMatrix(const IMatrix& other) override;
    void MulNumber(const double num) override;
    void MulMatrix(const IMatrix& other) override;
    IMatrix* Transpose() override;
    IMatrix* CalcComplements() override;
    double Determinant() override;
    IMatrix* InverseMatrix() override;

    // Operator
    IMatrix* operator+(const IMatrix& other) const override;
    IMatrix* operator-(const IMatrix& other) const override;
    IMatrix* operator*(const IMatrix& other) const override;
    IMatrix* operator*(const double num) const override;
    bool operator==(const IMatrix& other) const override;
    Matrix& operator=(const Matrix& other);
    IMatrix& operator=(const IMatrix& other)  override;
    IMatrix& operator+=(const IMatrix& other) override;
    IMatrix& operator-=(const IMatrix& other) override;
    IMatrix& operator*=(const IMatrix& other) override;
    IMatrix& operator*=(const double num) override;
    double& operator()(int row, int col) override;
    const double& operator()(int row, int col) const override;

    // Show
    void ShowMatrix() const override;
};