#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    void dfs(int x, int y, std::string str, int index) {
        if (index == str.length() || this->isHasPath) {
            this->isHasPath = true;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + go[i][0];
            int ny = y + go[i][1];
            if (nx < 0 || nx >= rows) continue;
            if (ny < 0 || ny >= columns) continue;
            if (this->mark[nx][ny] || str[index] != this->matrix[nx][ny]) continue;
            mark[nx][ny] = true;
            dfs(nx, ny, str, index + 1);
            mark[nx][ny] = false;
        }
    }

    bool hasPath(const std::vector<std::vector<char>> &matrix,
                 int rows, int columns,
                 std::string str) {
        if (matrix.empty() || str.length() <= 0) return false;
        this->isHasPath = false;
        this->matrix = matrix;
        this->rows = matrix.size();
        this->columns = matrix[0].size();
        this->mark.resize(this->rows);
        for (int i = 0; i < this->rows; ++i) {
            this->mark[i].resize(this->columns);
        }
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                this->mark[i][j] = false;
            }
        }
        this->isHasPath = false;
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                if (matrix[i][j] == str[0]) {
                    this->mark[i][j] = true;
                    dfs(i, j, str, 1);
                    this->mark[i][j] = false;
                    if (this->isHasPath) {
                        return this->isHasPath;
                    }
                }
            }
        }
        return false;
    }

private:
    std::vector<std::vector<char>> matrix;
    std::vector<std::vector<bool>> mark;
    int columns;
    int rows;
    int go[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool isHasPath = false;
};

int main() {
    int rows, columns;
    std::cin >> rows >> columns;
    char ch;
    std::vector<std::vector<char>> matrix(rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i].resize(columns);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> ch;
            matrix[i][j] = ch;
        }
    }
    std::string str;
    while (std::cin >> str) {
        std::cout << Solution().hasPath(matrix, rows, columns, str) << std::endl;
    }
    return 0;
}
