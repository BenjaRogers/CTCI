#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>>& matrix, int m, int n) {
    
    for (int i=0; i<m; i++) {
        std::cout << "\n" << "[";
        for(int j=0; j<n; j++) {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << "]";
    }
    std::cout << "\n";
    
}

// Zero all values in row/column if there is a value '0'
void zeroMatrix(std::vector<std::vector<int>>& matrix, int m, int n) {
    // Store positions of 0 values in matrix
    bool zeroPosArrayCol[10] = {};
    bool zeroPosArrayRow[10] = {};
    // Iterate whole matrix searching for 0 values
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {   
            // Write to array if value is zero
            if (matrix[i][j] == 0) {
                zeroPosArrayCol[i] = true;
                zeroPosArrayRow[j] = true;
            }
        }
    }
    // iterate position arrays and write zeros to corresponding rows/columns
    for (int i=0; i<10; i++) {
        if (zeroPosArrayCol[i] == true) {
            for (int col=0; col<10; col++) {
                matrix[i][col] = 0;
            }
        }
        if (zeroPosArrayRow[i] == true) {
            for (int row=0; row<10; row++) {
                matrix[row][i] = 0;
            }
        }
    }
    printMatrix(matrix, m, n);
}

int main() {
    int m = 10;
    int n = 10;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

    for (int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            matrix[i][j] = std::rand() % 10;
        }
    }
    std::cout << "Original Matrix";
    printMatrix(matrix, m, n);

    std::cout << "Zero Matrix";
    zeroMatrix(matrix, m, n);
}