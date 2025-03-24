#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>  


// Function to perform basic arithmetic operations
void performOperation(char operation, int a, int b) {
    int result = 0;
    switch(operation) {
        case '+':
            result = a + b; // Corrected syntax for assignment
            printf("result: %d\n", result);
            exit(result);
        case '-':
            result = a - b; // Corrected syntax for assignment
            printf("result: %d\n", result);
            exit(result);
        case '*':
            result = a * b; // Corrected syntax for assignment
            printf("result: %d\n", result);
            exit(result);
        case '/':
            if(b != 0) {
                result = a / b; // Corrected syntax for assignment
                printf("result: %d\n", result);
                exit(result);
            } else {
                printf("error division by zero\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("invalid operation\n");
            exit(EXIT_FAILURE); // Added exit for invalid operation
    }
}

// Function to perform matrix multiplication
void matrixMultiplication(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Enter your choice:\n1. Basic Arithmetic Operations\n2. Matrix Multiplication\n");
    scanf("%d", &choice);

    if (choice == 1) {
        char operation;
        int operand1, operand2, status;
        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation); // Added space before %c to consume newline
        printf("Enter the first number: ");
        scanf("%d", &operand1);
        printf("Enter the second number: ");
        scanf("%d", &operand2);

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return EXIT_FAILURE;
        } else if (pid == 0) {
            performOperation(operation, operand1, operand2);
        } else {
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child process exited with result = %d\n", WEXITSTATUS(status));
            } else {
                printf("Child process did not terminate successfully.\n");
            }
        }
    } else if (choice == 2) {
        int matrix1[2][2] = {{1, 2}, {3, 4}};
        int matrix2[2][2] = {{5, 6}, {7, 8}};
        int result[2][2];

        printf("Matrix 1:\n");
        printMatrix(matrix1);

        printf("Matrix 2:\n");
        printMatrix(matrix2);

        matrixMultiplication(matrix1, matrix2, result);

        printf("Matrix Multiplication Result:\n");
        printMatrix(result);
    } else {
        printf("Invalid choice.\n");
    }

    return EXIT_SUCCESS;
}
