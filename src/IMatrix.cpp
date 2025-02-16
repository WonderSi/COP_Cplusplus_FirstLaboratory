//
// Created by 011ko on 15.02.2025.
//

#include <iostream>
#include "../include/Matrix.h"

class IMatrix {
public:
    virtual ~IMatrix() = default;

    // Setter / Getter
    virtual int getRows() const = 0;
    virtual int getCols() const = 0;
    virtual void setRows(int rows) = 0;
    virtual void setCols(int cols) = 0;
    virtual IMatrix* getMinor(int rows, int cols) = 0;

    // Operation
    virtual bool EqMatrix(const IMatrix& other) = 0;
    virtual void SumMatrix(const IMatrix& other) = 0;
    virtual void SubMatrix(const IMatrix& other) = 0;
    virtual void MulNumber(const double num) = 0;
    virtual void MulMatrix(const IMatrix& other) = 0;
    virtual IMatrix* Transpose() = 0;
    virtual int CalcComplementsElements(int rows, int cols) = 0;
    virtual IMatrix* CalcComplements() = 0;
    virtual double Determinant() = 0;
    virtual IMatrix* InverseMatrix() = 0;

    // Operator
    virtual IMatrix* operator+(const IMatrix& other) const = 0;
    virtual IMatrix* operator-(const IMatrix& other) const = 0;
    virtual IMatrix* operator*(const IMatrix& other) const = 0;
    virtual IMatrix* operator*(const double num) const = 0;
    virtual bool operator==(const IMatrix& other) const = 0;
    virtual IMatrix& operator=(const IMatrix& other)  = 0;
    virtual IMatrix& operator+=(const IMatrix& other) = 0;
    virtual IMatrix& operator-=(const IMatrix& other) = 0;
    virtual IMatrix& operator*=(const IMatrix& other) = 0;
    virtual IMatrix& operator*=(const double num) = 0;
    virtual double& operator()(int row, int col) = 0;
    virtual const double& operator()(int row, int col) const = 0;
};