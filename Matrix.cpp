class Matrix{
public:
    virtual double getElem(int i, int j)=0;
    virtual void setElem(int i, int j, double val)=0;
};

class Matrix2dArray : public Matrix
{
private:
    int width,height;
    double **data;
    int static min(int a, int b);
public:
    Matrix2dArray();
    Matrix2dArray(int height, int width);
    ~Matrix2dArray();
    double getElem(int i, int j);
    void setElem(int i, int j, double val);
    void toString();
    Matrix2dArray &add(Matrix2dArray &B);
    Matrix2dArray& multiply(Matrix2dArray &other);
};

class MatrixLin : public Matrix
{
protected:
    double *data;
    int width,height;
    int static min(int a, int b);
public:
    virtual Matrix2dArray delinearize()=0;
};

class MatrixRowWise : public MatrixLin
{
public:
    MatrixRowWise(int height, int width);
    ~MatrixRowWise();
    double getElem(int i, int j);
    void setElem(int i, int j, double val);
    void toString();
    MatrixRowWise& add(MatrixRowWise &other);
    MatrixRowWise& multiply(MatrixRowWise &other);
    Matrix2dArray delinearize();
    
};
class MatrixColWise : public MatrixLin
{
public:
    MatrixColWise(int height, int width);
    ~MatrixColWise();
    double getElem(int i, int j);
    void setElem(int i, int j, double val);
    void toString();
    MatrixColWise& add(MatrixColWise &other);
    MatrixColWise& multiply(MatrixColWise &other);
    Matrix2dArray delinearize();
};
