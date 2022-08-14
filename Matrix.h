#include "Matrix.cpp"
#include <iostream>
using namespace std;

// Start class Matrix2dArray

int Matrix2dArray::min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
Matrix2dArray::Matrix2dArray(int height, int width)
{
    this->width = width;
    this->height = height;
    data = new double *[width];
    for (int i = 0; i < width; i++)
    {
        data[i] = new double[height];
    }
}
double Matrix2dArray::getElem(int i, int j)
{
    return data[i - 1][j - 1];
}
void Matrix2dArray::setElem(int i, int j, double val)
{
    data[i - 1][j - 1] = val;
}
void Matrix2dArray::toString()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << data[i][j] << " ";
        }
    }
}
Matrix2dArray &Matrix2dArray::add(Matrix2dArray &other)
{
    if (this->height != other.height || this->width != other.width)
    {
        return other;
    }

    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            other.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return other;
}
Matrix2dArray &Matrix2dArray::multiply(Matrix2dArray &other)
{
    if (this->height != other.height || this->width != other.width)
    {
        return other;
    }
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            other.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return other;
}
Matrix2dArray::~Matrix2dArray()
{
    for (int i = 0; i < width; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    data = NULL;
}

// End class Matrix2dArray

// start class MatrixLin

int MatrixLin::min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// End class MatrixLin

// start class MatrixRowWise

MatrixRowWise::MatrixRowWise(int height, int width)
{
    this->width = width;
    this->height = height;
    data = new double[height * width];
}
MatrixRowWise::~MatrixRowWise()
{
    delete[] data;
    data = NULL;
}
Matrix2dArray MatrixRowWise::delinearize()
{
    Matrix2dArray newMatrix(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newMatrix.setElem(i, j, data[i * width + j]);
        }
    }
    return newMatrix;
}
void MatrixRowWise::toString()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << data[i * width + j] << " ";
        }
    }
}
double MatrixRowWise::getElem(int i, int j)
{
    return data[i * width + j];
}
void MatrixRowWise::setElem(int i, int j, double value)
{
    data[i * width + j] = value;
}
MatrixRowWise &MatrixRowWise::add(MatrixRowWise &other)
{
    if (this->height != other.height || this->width != other.width)
    {
        return other;
    }
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            other.data[i] = data[i] + other.data[i];
        }
    }

    return other;
}
MatrixRowWise &MatrixRowWise::multiply(MatrixRowWise &other)
{
    if (this->height != other.height || this->width != other.width)
    {
        return other;
    }
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            other.data[i] = data[i] * other.data[i];
        }
    }

    return other;
}

// End class MatrixRowWise
// start class MatrixColWise

MatrixColWise::MatrixColWise(int height, int width)
{
    this->width = width;
    this->height = height;
    data = new double[height * width];
}
Matrix2dArray MatrixColWise::delinearize()
{
    Matrix2dArray newMatrix(height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newMatrix.setElem(i, j, data[i * width + j]);
        }
    }
    return newMatrix;
}
double MatrixColWise::getElem(int i, int j)
{
    return data[i * width + j];
}
void MatrixColWise::setElem(int i, int j, double value)
{
    data[i * width + j] = value;
}
MatrixColWise &MatrixColWise::add(MatrixColWise &other)
{
    if (this->height != other.height || this->width != other.width)
    {
        return other;
    }
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            other.data[i] = data[i] + other.data[i];
        }
    }

    return other;
}
MatrixColWise &MatrixColWise::multiply(MatrixColWise &other)
{
    if (this->height != other.height || this->width != other.width)
    {
        return other;
    }
    for (int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->height; j++)
        {
            other.data[i] = data[i] * other.data[i];
        }
    }

    return other;
}
void MatrixColWise::toString()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << data[i * width + j] << " ";
        }
    }
}
MatrixColWise::~MatrixColWise()
{
    delete[] data;
    data = NULL;
}

// End class MatrixColWise
