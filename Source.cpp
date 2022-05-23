#include <Windows.h> 
#include <iostream> 
#include <time.h> 
using namespace std;


void outputMatrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getIterationCount(int** matrix, int row, int col) {
    int res = 0;

    for (int i = 0; i < row; i++) {
        bool withoutNull = true;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                withoutNull = false;
                break;
            }
        }
        if (withoutNull) {
            res++;
        }
    }

    return res;
}

int getRecursiveCount(int** matrix, int row, int col, int& sum, int i = 0, int j = 0, bool withoutNull = true) {


    if (j >= col) {
        i++;
        j = 0;
        if (!withoutNull) {
            withoutNull = true;
        }
        else
            sum += 1;
    }

    if (i >= row) {

        return 0;
    }

    if (matrix[i][j] == 0) withoutNull = false;
    j++;
    getRecursiveCount(matrix, row, col, sum, i, j, withoutNull);
    return sum;
}




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int** matrix;
    int row, col;
    cout << "Введіть розмір квадратної матриці: "; cin >> row >> col;
    matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 11;
        }
    }
    outputMatrix(matrix, row, col);
    int sum = 0;
    cout << "Кількість рядків без 0 ітераційний спосіб: " << getIterationCount(matrix, row, col) << endl;
    cout << "Кількість рядків без 0 рекурсивний спосіб: " << getRecursiveCount(matrix, row, col, sum) << endl;
    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;

}