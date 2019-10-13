#include <iostream>
#include <cassert>

bool findMatrixTarget(int **matrix, int rows, int columns, int target) {
    assert(matrix != nullptr);
    int row = 0, column = columns - 1;
    while (row < rows && column >= 0) {
        if (matrix[row][column] == target) {
            return true;
        } else if (target < matrix[row][column]) {
            --column;
        } else {
            ++row;
        }
    }
    return false;
}


int main() {
    int rows = 0, columns = 0, target = 0;
    std::cin >> rows >> columns >> target;
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << findMatrixTarget(matrix, rows, columns, target);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
