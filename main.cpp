#include "Matrix.h"

int main(int argc, char const *argv[])
{
    Matrix2dArray M1(2, 2);
    M1.setElem(1, 1, 1);
    M1.setElem(1, 2, 2);
    M1.setElem(2, 1, 3);
    M1.setElem(2, 2, 4);

    Matrix2dArray M2(2, 2);
    M2.setElem(1, 1, 5);
    M2.setElem(1, 2, 6);
    M2.setElem(2, 1, 7);
    M2.setElem(2, 2, 8);

    // Matrix2dArray M3(2, 2); 
    // M3 = M1.add(M2);
    // cout << M3.getElem(1,1);

    // M1.toString();

    
    // M2.getElem(2,1);


    MatrixColWise colWiseMatrix(2, 2);
    colWiseMatrix.setElem(0, 0, 1);
    colWiseMatrix.setElem(0, 1, 2);
    colWiseMatrix.setElem(1, 0, 3);
    colWiseMatrix.setElem(1, 1, 4);

    MatrixColWise colWiseMatrix1(2, 2);
    colWiseMatrix1 = colWiseMatrix.add(colWiseMatrix);
    cout << colWiseMatrix1.getElem(1,1);
    colWiseMatrix1.toString();


    // colWiseMatrix.toString();

    // MatrixRowWise rowWiseMatrix(2, 2);
    // rowWiseMatrix.setElem(0, 0, 9);
    // rowWiseMatrix.setElem(0, 1, 3);
    // rowWiseMatrix.setElem(1, 0, 7);
    // rowWiseMatrix.setElem(1, 1, 4);

    // rowWiseMatrix.toString();

    return 0;
}
