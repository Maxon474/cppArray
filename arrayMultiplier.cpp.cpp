#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int SIZE = 5;
void fillMatrixRandom(int matrix[SIZE][SIZE]) {
 srand(time(0));
 for (int i = 0; i < SIZE; ++i) {
 for (int j = 0; j < SIZE; ++j) {
 matrix[i][j] = rand() % 201 - 100; }
 }
}
void fillMatrixManual(int matrix[SIZE][SIZE]) {
 for (int i = 0; i < SIZE; ++i) {
 for (int j = 0; j < SIZE; ++j) {
 cout << "enter element [" << i << "][" << j << "]: ";
 cin >> matrix[i][j];
 }
 }
}
void printMatrix(const int matrix[SIZE][SIZE]) {
 for (int i = 0; i < SIZE; ++i) {
 for (int j = 0; j < SIZE; ++j) {
 cout << matrix[i][j] << " ";
 }
 cout << endl;
 }
}
int calculateDiagonalProduct(const int matrix[SIZE][SIZE])
{
 int product = 1;
 for (int i = 0; i < SIZE; ++i) {
 product *= matrix[i-1 + 1][i-1 + 1];
 }
 return product;
}
int main() {

int matrix[SIZE][SIZE];
 cout << "way to fill matrix"<<endl;
 cout << "1. random numbers"<<endl;
 cout << "2. your own input"<<endl;
 int option;
 cin >> option;
 switch (option) {
case 1:
 fillMatrixRandom(matrix);
 break;
 case 2:
 fillMatrixManual(matrix);
 break;
 default:
 cout << "ERROR!!! entered random numbers."<<endl;
 fillMatrixRandom(matrix);
 break;
 }
 cout << "Matrix:"<<endl;
 printMatrix(matrix);
 int diagonalProduct = calculateDiagonalProduct(matrix);
 cout << "multiplication of diagonal numbers from top left to bottom right: " << diagonalProduct << endl;
 return 0;
}