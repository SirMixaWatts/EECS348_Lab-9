#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> readMatrix(std::ifstream& file, int N) {
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
        }
    }
    return matrix;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int N;
    file >> N;

    auto matrix1_data = readMatrix(file, N);
    auto matrix2_data = readMatrix(file, N);
    file.close();

    Matrix m1(matrix1_data);
    Matrix m2(matrix2_data);

    std::cout << "Matrix 1:" << std::endl;
    m1.print_matrix();
    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    m2.print_matrix();
    std::cout << std::endl;

    std::cout << "Matrix Sum:" << std::endl;
    Matrix sum = m1 + m2;
    sum.print_matrix();
    std::cout << std::endl;

    std::cout << "Matrix Product:" << std::endl;
    Matrix product = m1 * m2;
    product.print_matrix();
    std::cout << std::endl;

    std::cout << "Matrix 1 Major Diagonal Sum: " << m1.sum_diagonal_major() << std::endl;
    std::cout << "Matrix 1 Minor Diagonal Sum: " << m1.sum_diagonal_minor() << std::endl;
    std::cout << std::endl;

    std::cout << "Matrix 2 Major Diagonal Sum: " << m2.sum_diagonal_major() << std::endl;
    std::cout << "Matrix 2 Minor Diagonal Sum: " << m2.sum_diagonal_minor() << std::endl;
    std::cout << std::endl;

    std::cout << "Matrix 1 after swapping rows 0 and 1:" << std::endl;
    m1.swap_rows(0, 1);
    m1.print_matrix();
    m1.swap_rows(0, 1); // swap back
    std::cout << std::endl;

    std::cout << "Matrix 1 after swapping columns 0 and 1:" << std::endl;
    m1.swap_cols(0, 1);
    m1.print_matrix();
    m1.swap_cols(0, 1); // swap back
    std::cout << std::endl;

    std::cout << "Matrix 1 after setting (0,0) to 100:" << std::endl;
    m1.set_value(0, 0, 100);
    m1.print_matrix();
    m1.set_value(0, 0, matrix1_data[0][0]); // restore original value
    std::cout << std::endl;

    return 0;
}
