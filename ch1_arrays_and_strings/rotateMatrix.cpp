#include <iostream>
#include <cmath>
// Print matrix for easier readability
void printMatrix(int matrix[10][10]) {
    for (int i=0; i<10; i++) {
        std::cout << "[";
        for (int j=0; j<10; j++) {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << "]" << "\n";
    }
    std::cout << "\n";
}
// rotate matrix by 90 degrees in place
void rotateMatrix(int matrix[10][10], int degrees) {
    // Convert angle in degrees to radians for trig functions.
    float radian = degrees * 3.14159 / 180;
    float cosD = std::cos(radian);
    float sinD = std::sin(radian);

    // Temp variables to hold values when iteratively swapping values
    int tempV;
    int tempX;
    int tempY;
    int newV;

    int yMin = 0;
    int yMax = 9;
    int xMin = 0;
    int xMax = 9;
    
    // iterate half columns 
    for (int y=yMin; y<yMax / 2 + 1; y++) {
        // iterate through row
        for (int x=xMin; x<xMax; x++) {
            tempX = x;
            tempY = y;
            tempV = matrix[y][x];
            // iterate through corners and swap variables -- spiral pattern
            for (int i=0; i<4; i++){
                // Calculate the new coordinate for a value
                int newX = 9 + std::round(((tempX * cosD) - (tempY * sinD)));
                int newY = std::round((tempX * sinD) + (tempY * cosD));
                //std:: cout << "Value " << tempV << " at " << tempX << ","  << tempY << " written to location " << newX << "," << newY << "\n"; 
                
                // Save value to variable before swapping with temp value
                newV = matrix[newY][newX];
                matrix[newY][newX] = tempV;
                
                // Reassign temp variables for new coordinate/value pair
                tempX = newX;
                tempY = newY;
                tempV = newV;
            }
        }
        // shrink next iteration of x 
        xMin++; 
        xMax--;
    }
    printMatrix(matrix);
}

int main() {
    // Generate 10x10 byte array of ints (4bytes)
    int byteArray[10][10];
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            byteArray[i][j] = i * 10 + j;
        }
    }
    std::cout << "Original matrix: " << "\n";
    printMatrix(byteArray);

    std::cout << "Matrix rotated by 90 degrees: " << "\n";
    rotateMatrix(byteArray, 90);
}