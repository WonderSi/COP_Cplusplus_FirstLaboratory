//
// Created by 011ko on 15.02.2025.
//

#pragma once

#include <iostream>

class Matrix : public IMatrix {
private :
    int rows_, cols_;
    double **matrix_;

    void memoryAllocation();
    void memoryDeallocation();

public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();

    int getRows() const override;
    int getCols() const override;

    double& operator()(int row, int col) override;
};