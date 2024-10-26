/*Adira Mongar
ID 3108424
Lab 6
we're doing matrix math in this lab, i didn't actually know matrix math :(
i printed everything to an output file because i assume thats what you want?? im a bit unclear tho i hope you don't count me off
this code is only kinda tested because i can't test multi file code in an online compiler same with the last part but this one probably doesn't actually have to be multifile */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Function prototypes
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE], int rows1, int rows2, int cols1, int cols2);
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE],int rows1, int rows2, int cols1, int cols2);
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE],int rows, int cols);
void printMatrixToFile(int matrix[SIZE][SIZE], int rows, int cols);

int main() {
    // Open the output file

    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE];

    // Add matrices
    printf( "Matrix Addition:\n");
    if(addMatrices(m1, m2, result, SIZE, SIZE, SIZE, SIZE)){
		printMatrixToFile( result, SIZE, SIZE);
	}else{
		printf( "Error: Incompatible dimensions for matrix addition.\n");
	}
    // Multiply matrices
    printf( "\nMatrix Multiplication:\n");
    if (multiplyMatrices(m1, m2, result, SIZE, SIZE, SIZE, SIZE)) {
        printMatrixToFile( result, SIZE, SIZE);
    } else {
        printf( "Error: Incompatible dimensions for matrix multiplication.\n");
    }

    // Transpose of matrix m1
    printf( "\nTranspose of Matrix 1:\n");
    transposeMatrix(m1, result, SIZE, SIZE);
    printMatrixToFile( result, SIZE, SIZE);

    // Transpose of matrix m2
    printf( "\nTranspose of Matrix 2:\n");
    transposeMatrix(m2, result, SIZE, SIZE);
    printMatrixToFile( result, SIZE, SIZE);

    return 0;
}

// function to add two matrices
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE],int rows1,int cols1,int rows2,int cols2) {

	//check if matricies can be added
	if ((rows1 != rows2) || (cols1 != cols2)){
		return 0; // incompatable
	}
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			result[i][j] = m1[i][j] + m2[i][j];
		}	
	}
	return 1;

}

// multiply two matrices 
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE],int rows1,int cols1,int rows2,int cols2) {
    // Check if the matrices can be multiplied 

	if (cols1 != rows2) {
        return 0;  // Return 0 if incompatible
    }


    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return 1;  // Return 1 if successful
}

//  transpose a matrix
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE],int rows,int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = m[i][j];
        }
    }
}


void printMatrixToFile(int matrix[SIZE][SIZE],int rows,int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf( "%5d ", matrix[i][j]);
        }
        printf( "\n");
    }
}


