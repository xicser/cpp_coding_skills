/*
听讲了半天没听到核心，上简书看了一下，左值引用和右值引用本质就是减少内存开销优化内存使用的一种方法，
提出右值引用的目的，就是将那些产生的临时的变量或对象偷过来作为长生命周期的对象存在，
避免了不必要的多次的在内存中创建销毁，不过还是要说，有垃圾回收的语言真的牛b
*/

#include <iostream>

using namespace std;

class Matrix {
private:
    int row, col;
    int** matrix;

public:
    Matrix() {
        printf("constructor()\n");
        row = 0;
        col = 0;
        matrix = nullptr;
    }
    Matrix(int _row, int _col) {
        printf("constructor(int _row, int _col)\n");

        row = _row;
        col = _col;
        matrix = new int* [row];
        for (int i = 0; i < row; i++) {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    /* 拷贝构造 */
    Matrix(const Matrix& m) {
        printf("copy constructor\n");

        row = m.row;
        col = m.col;
        matrix = new int* [row];
        for (int i = 0; i < row; i++) {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }

    /* 移动构造
       当一个函数试图返回一个对象（将亡值）的时候, 
       在赋值给接这个函数返回值对象的时候, 会优先考虑调用移动构造函数, 没有移动构造函数的时候才会调用拷贝构造,
       这样可以重复利用将亡值的内存, 避免多次构造对象, 提升性能
    */
    Matrix(Matrix&& m) {
        printf("move constructor\n");

        row = m.row;
        col = m.col;
        matrix = m.matrix;   //直接重用将亡值m的内存
        m.matrix = nullptr;  //一定要设置成nullptr
    }

    ~Matrix() {

        //一定要写 != nullptr 判断, 并且只要一delete, 就把指针写成nullptr
        //如果存在移动构造, 当偷走将亡值的内存后, 把指针写成nullptr, 其对应的内存由偷盗者去释放, 被偷的对象这里发现指针是nullptr,
        //就不会释放, 这样才能避免重复释放
        if (matrix != nullptr) {
            printf("~release\n");
            for (int i = 0; i < row; i++) {
                if (matrix[i] != nullptr) {
                    delete[] matrix[i];
                    matrix[i] = nullptr;
                }
            }
            delete[] matrix;
            matrix = nullptr;
        }
    }

    //重载赋值运算符
    Matrix& operator= (const Matrix& obj) {

        printf("assignment &\n");

        if (matrix != nullptr) {
            for (int i = 0; i < row; i++) {
                if (matrix[i] != nullptr) {
                    delete[] matrix[i];
                    matrix[i] = nullptr;
                }
            }
            delete[] matrix;
            matrix = nullptr;
        }

        this->row = obj.row;
        this->col = obj.col;

        matrix = new int* [row];
        for (int i = 0; i < row; i++) {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++) {
                matrix[i][j] = obj.matrix[i][j];
            }
        }

        return *this;
    }
    
    //重载赋值运算符（移动赋值）
    Matrix& operator= (Matrix&& obj) {

        printf("assignment &&\n");

        if (matrix != nullptr) {
            for (int i = 0; i < row; i++) {
                if (matrix[i] != nullptr) {
                    delete[] matrix[i];
                    matrix[i] = nullptr;
                }
            }
            delete[] matrix;
            matrix = nullptr;
        }

        //偷
        this->row = obj.row;
        this->col = obj.col;
        this->matrix = obj.matrix;
        obj.matrix = nullptr;

        return *this;
    }

    //重载加法运算符
    friend Matrix operator+ (const Matrix& a, const Matrix& b) {
        printf("operator+ &\n");
        if (a.row != b.row || a.col != b.col) {
            printf("Error!\n");
        }

        Matrix result(a.row, a.col);

        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.col; j++) {
                result.matrix[i][j] =
                    a.matrix[i][j] + b.matrix[i][j];
            }
        }
        printf("\n");
        return result;
    }

    //重载加法运算符
    friend Matrix operator+ (Matrix&& a, const Matrix& b) {
        printf("operator+ &&\n");
        if (a.row != b.row || a.col != b.col) {
            printf("Error!\n");
        }

        //把将亡值a的内存, 移动给result, 达到复用的效果, 提升效率
        Matrix result(std::move(a));

        for (int i = 0; i < result.row; i++) {
            for (int j = 0; j < result.col; j++) {
                result.matrix[i][j] =
                    result.matrix[i][j] + b.matrix[i][j];
            }
        }

        return result;
    }
};

void testMatrix()
{
    Matrix a(3, 4);
    Matrix b(3, 4);
    Matrix c(3, 4);
    printf("\n");

    //Matrix r = a + b   + c;
            // tmp_ab


    Matrix r;
    //r = Matrix(5, 6);

    r = a + b + c;

    printf("--------------------\n");
}