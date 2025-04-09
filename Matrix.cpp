#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Matrix::Matrix(size_t N) {
    matrix.resize(N, std::vector<int>(N, 0));
}

Matrix::Matrix(std::vector<std::vector<int>> nums) {
    matrix = nums;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if (matrix.size() != rhs.matrix.size()) {
        throw std::invalid_argument("Matrices must be of the same size");
    }

    size_t N = matrix.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N));

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            result[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }

    return Matrix(result);
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if (matrix.size() != rhs.matrix.size()) {
        throw std::invalid_argument("Matrices must be of the same size");
    }

    size_t N = matrix.size();
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {
                result[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }

    return Matrix(result);
}

void Matrix::set_value(size_t i, size_t j, int n) {
    if (i >= matrix.size() || j >= matrix.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    matrix[i][j] = n;
}

int Matrix::get_value(size_t i, size_t j) const {
    if (i >= matrix.size() || j >= matrix.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return matrix[i][j];
}

int Matrix::get_size() const {
    return matrix.size();
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < matrix.size(); i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    size_t N = matrix.size();
    for (size_t i = 0; i < N; i++) {
        sum += matrix[i][N - 1 - i];
    }
    return sum;
}

void Matrix::swap_rows(size_t r1, size_t r2) {
    if (r1 >= matrix.size() || r2 >= matrix.size()) {
        throw std::out_of_range("Row index out of bounds");
    }
    std::swap(matrix[r1], matrix[r2]);
}

void Matrix::swap_cols(size_t c1, size_t c2) {
    if (c1 >= matrix.size() || c2 >= matrix.size()) {
        throw std::out_of_range("Column index out of bounds");
    }
    for (size_t i = 0; i < matrix.size(); i++) {
        std::swap(matrix[i][c1], matrix[i][c2]);
    }
}

void Matrix::print_matrix() const {
    for (const auto &row : matrix) {
        for (int val : row) {
            std::cout << std::setw(4) << val;
        }
        std::cout << std::endl;
    }
}