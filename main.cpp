#include <iostream>
#include "include/Matrix.h"

int main() {
    try {
        IMatrix *A = new Matrix(3, 3);
        (*A)(0, 0) = 1;
        (*A)(0, 1) = 2;
        (*A)(0, 2) = 3;
        (*A)(1, 0) = 4;
        (*A)(1, 1) = 5;
        (*A)(1, 2) = 6;
        (*A)(2, 0) = 7;
        (*A)(2, 1) = 8;
        (*A)(2, 2) = 9;

        std::cout << "Matrix A: " << std::endl;
        A->ShowMatrix();

        IMatrix *B = new Matrix(3, 3);
        (*B)(0,0) = 9;
        (*B)(0,1) = 8;
        (*B)(0,2) = 7;
        (*B)(1,0) = 6;
        (*B)(1,1) = 5;
        (*B)(1,2) = 4;
        (*B)(2,0) = 3;
        (*B)(2,1) = 1;
        (*B)(2,2) = 0;

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

        IMatrix *H = (*A * 2);
        std::cout << "Matrix A * 2: " << std::endl;
        H->ShowMatrix();

        IMatrix *F = A;
        std::cout << "Matrix F (copy of A): " << std::endl;
        F->ShowMatrix();

        *F += *B;
        std::cout << "Matrix F (F += B): " << std::endl;
        F->ShowMatrix();

        *F -= *B;
        std::cout << "Matrix F (F -= B): " << std::endl;
        F->ShowMatrix();

        *F *= *B;
        std::cout << "Matrix F (F *= B): " << std::endl;
        F->ShowMatrix();

        *F *= 2;
        std::cout << "Matrix F (F *= 2): " << std::endl;
        F->ShowMatrix();

        IMatrix *G = A->Transpose();
        std::cout << "Transpose of Matrix A: " << std::endl;
        G->ShowMatrix();

        bool boolResultFG = F == G;
        std::cout << "F == G: " << boolResultFG << std::endl;

        bool boolResultFA = F->EqMatrix(*A);
        std::cout << "F->EqMatrix(*A): " << boolResultFA << std::endl;



        delete A;
        delete B;
        delete C;
        delete D;
        delete E;
        delete F;
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
