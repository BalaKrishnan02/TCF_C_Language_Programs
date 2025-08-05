#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5



Q1.

struct Student {
    int id;
    char name[50];
    int marks[SUBJECTS];
    float average;
};

void inputStudents(struct Student s[], int n);
void calculateAverage(struct Student *s);
void displayTopper(struct Student s[], int n);

int main() {
    int n = 5;
    struct Student students[MAX_STUDENTS];

    inputStudents(students, n);

    for (int i = 0; i < n; i++) {
        calculateAverage(&students[i]);
    }

    displayTopper(students, n);

    return 0;
}

void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name); // reads full name with spaces
        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }
}

void calculateAverage(struct Student *s) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += s->marks[i];
    }
    s->average = sum / (float)SUBJECTS;
}

void displayTopper(struct Student s[], int n) {
    int topperIndex = 0;
    float highestAvg = s[0].average;

    for (int i = 1; i < n; i++) {
        if (s[i].average > highestAvg) {
            highestAvg = s[i].average;
            topperIndex = i;
        }
    }

    printf("\nTopper Student Details:\n");
    printf("ID: %d\n", s[topperIndex].id);
    printf("Name: %s\n", s[topperIndex].name);
    printf("Marks: ");
    for (int j = 0; j < SUBJECTS; j++) {
        printf("%d ", s[topperIndex].marks[j]);
    }
    printf("\nAverage: %.2f\n", s[topperIndex].average);
}





Q2.

#include <stdio.h>
#include <stdlib.h>


int** createMatrix(int rows, int cols);
void inputMatrix(int **matrix, int rows, int cols);
int** multiplyMatrices(int **A, int **B, int r1, int c1, int c2);
void displayMatrix(int **matrix, int rows, int cols);
void freeMatrix(int **matrix, int rows);

int main() {
    int r1, c1, r2, c2;

    
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

   
    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        return 1;
    }

    int **A = createMatrix(r1, c1);
    int **B = createMatrix(r2, c2);

   
    printf("\nEnter elements for Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("\nEnter elements for Matrix B:\n");
    inputMatrix(B, r2, c2);

  
    int **C = multiplyMatrices(A, B, r1, c1, c2);

 
    printf("\nResultant Matrix C (A x B):\n");
    displayMatrix(C, r1, c2);

   
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(C, r1);

    return 0;
}

int** createMatrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int** multiplyMatrices(int **A, int **B, int r1, int c1, int c2) {
    int **result = createMatrix(r1, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
