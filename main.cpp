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
        std::cout << "Matrix C (A + B): " << std::endl;
        C->ShowMatrix();

        IMatrix *D = (*A - *B);
        std::cout << "Matrix D (A - B): " << std::endl;
        D->ShowMatrix();

        IMatrix *E = (*A * *B);
        std::cout << "Matrix E (A * B): " << std::endl;
        E->ShowMatrix();

        IMatrix *H = (*A * 2);
        std::cout << "Matrix H (A * 2): " << std::endl;
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
        std::cout << "Matrix G (A->Transpose()): " << std::endl;
        G->ShowMatrix();

        bool boolResultFG = F == G;
        std::cout << "F == G: " << boolResultFG << std::endl;

        bool boolResultFA = F->EqMatrix(*A);
        std::cout << "F->EqMatrix(*A): " << boolResultFA << std::endl;

        A->SumMatrix(*B);
        std::cout << "A->SumMatrix(*B): " << std::endl;
        A->ShowMatrix();

        A->SubMatrix(*B);
        std::cout << "A->SubMatrix(*B): " << std::endl;
        A->ShowMatrix();

        B->MulNumber(2);
        std::cout << "B->MulNumber(2): " << std::endl;
        B->ShowMatrix();

        B->MulMatrix(*B);
        std::cout << "B->MulMatrix(*B): " << std::endl;
        B->ShowMatrix();

        IMatrix *I = E->CalcComplements();
        std::cout << "Matrix I (E->CalcComplements()): " << std::endl;
        I->ShowMatrix();

        double detD = D->Determinant();
        std::cout << "D->Determinant(): " << detD <<std::endl;


        IMatrix *J = new Matrix(3, 3);
        (*J)(0, 0) = 1;
        (*J)(0, 1) = 2;
        (*J)(0, 2) = 3;
        (*J)(1, 0) = -2;
        (*J)(1, 1) = 1;
        (*J)(1, 2) = 2;
        (*J)(2, 0) = 1;
        (*J)(2, 1) = -1;
        (*J)(2, 2) = -2;
        std::cout << "Create matrix J: " << std::endl;
        J->ShowMatrix();

        IMatrix* K = J->InverseMatrix();
        std::cout << "Matrix J (J->InverseMatrix()): " << std::endl;
        K->ShowMatrix();

//        K->MulMatrix(*J);
//        std::cout << "Check inverse matrix (J->MulMatrix(*J)): " << std::endl;
//        K->ShowMatrix();

//        std::cout << std::endl;
//        IMatrix *L = new Matrix(2,2);
//        (*L)(0,0) = 2;
//        (*L)(0,1) = -3;
//        (*L)(1,0) = 1;
//        (*L)(1,1) = 2;
//        L->ShowMatrix();
//        std::cout<< L->Determinant() << std::endl;

        delete A;
        delete B;
        delete C;
        delete D;
        delete E;
        delete F;
        delete G;
        delete H;
        delete I;
        delete J;
        delete K;
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
