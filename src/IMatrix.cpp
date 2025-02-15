//
// Created by 011ko on 15.02.2025.
//

#include <iostream>

class IMatrix {
public:
    virtual ~IMatrix() = default;

    virtual int getRows() const = 0;
    virtual int getCols() const = 0;
};