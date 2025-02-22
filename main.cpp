#include <iostream>
#include "include/Matrix.h"

int main() {
    try {
        IMatrix *A = new Matrix(3, 3);
        (*A)(0, 0) = 1;
        (*A)(0, 1) = 2;
        (*A)(1, 0) = 3;
        (*A)(1, 1) = 4;

        std::cout << "Matrix A: " << std::endl;
        A->ShowMatrix();

        IMatrix *B = new Matrix(3, 3);
        (*B)(0,0) = 4;
        (*B)(0,1) = 3;
        (*B)(1,0) = 2;
        (*B)(1,1) = 1;

        std::cout << "Matrix B: " << std::endl;
        B->ShowMatrix();

        IMatrix *C = (*A + *B);
        std::cout << "Matrix A + B: " << std::endl;
        C->ShowMatrix();

        IMatrix *D = (*A - *B);
        std::cout << "Matrix A - B: " << std::endl;
        D->ShowMatrix();

        IMatrix *E = (*A * *B);
        std::cout << "Matrix A * B: " << std::endl;
        E->ShowMatrix();

        



    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
