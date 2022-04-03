#include"matrix.h"

void read_Matrix(int array[10][10], int rows, int columns);
void print_Matrix(int array[10][10], int rows, int columns);
void matrix_AddSub(int array1[10][10], int array2[10][10], int rows, int columns, int multiply);
void matrix_Multiply(int array1[10][10], int array2[10][10], int rowA, int columnA, int columnB);

int main(void)
{
    int i, j, k; 

    int matrixA[10][10]; 
    int matrixB[10][10];
    int row_A, column_A;
    int row_B, column_B;
    int operation;
    char again = 'Y';
    int add = 1;
    int subtract = -1;

    while (again == 'Y')
{
        printf("\nOperation Menu\n");
        printf("\t1. To Add \n");
        printf("\t2. To Subtract \n");
        printf("\t3. To Multiply two matrices \n");
        printf("Enter your operation: ");
        scanf(" %d", &operation);

        switch (operation)
{
        case 1:
            printf("\nEnter the rows and columns for matrix A: ");
            scanf("%d%d", &row_A, &column_A);

            printf("Enter the rows and columns for matrix B: ");
            scanf("%d%d", &row_B, &column_B);

            while ((row_A != row_B) && (column_A != column_B))
{
                printf("\nMatrices must be same size\n");
                printf("\nEnter the rows and columns for matrix A: ");
                scanf("%d%d", &row_A, &column_A);

                printf("Enter the rows and columns for matrix B: ");
                scanf("%d%d", &row_B, &column_B);

            }

            printf("\n\tEnter elements of Matrix A  %d x %d matrix\n", row_A, column_A); 
            read_Matrix(matrixA, row_A, column_A);
            printf("\n\t\tMatrix A\n\n");
            print_Matrix(matrixA, row_A, column_A);

            printf("\n\tEnter elements of Matrix B  %d x %d matrix\n", row_B, column_B);
            read_Matrix(matrixB, row_B, column_B);
            printf("\n\t\tMatrix B\n\n");
            print_Matrix(matrixB, row_B, column_B);

            printf("\nThe Sum of matrixA + matrixB is : \n");
            matrix_AddSub(matrixA, matrixB, row_A, column_A, add);

            break;

        case 2:

            printf("\nEnter the rows and columns for matrix A: ");
            scanf("%d%d", &row_A, &column_A);

            printf("Enter the rows and colmns for matrix B: ");
            scanf("%d%d", &row_B, &column_B);

            while ((row_A != row_B) && (column_A != column_B)){
                printf("\nMatrices must be same size\n");
                printf("\nEnter the rows and columns for matrix A: ");
                scanf("%d%d", &row_A, &column_A);

                printf("Enter the rows and columns for matrix B: ");
                scanf("%d%d", &row_B, &column_B);
            }

            printf("\n\tEnter elements of Matrix A  %d x %d matrix\n", row_A, column_A);
            read_Matrix(matrixA, row_A, column_A);
            printf("\n\t\tMatrix A\n\n");
            print_Matrix(matrixA, row_A, column_A);

            printf("\n\tEnter elements of Matrix B  %d x %d matrix\n", row_B, column_B);
            read_Matrix(matrixB, row_B, column_B);
            printf("\n\t\tMatrix B\n\n");
            print_Matrix(matrixB, row_B, column_B);

            printf("\nThe difference between matrixA - matrixB is : \n");
            matrix_AddSub(matrixA, matrixB, row_A, column_A, subtract);
            break;

    
        case 3:
            printf("\nEnter the rows and columns for matrix A: ");
            scanf("%d%d", &row_A, &column_A);

            printf("Enter the rows and columns for matrix B: ");
            scanf("%d%d", &row_B, &column_B);

                       while (column_A != row_B)
            {
                printf("\n\nError! column of first matrix is not equal to row of second.\n\n");
                printf("\nEnter the rows and columns for matrix A: ");
                scanf("%d%d", &row_A, &column_A);

                printf("Enter the rows and columns for matrix B: ");
                scanf("%d%d", &row_B, &column_B);
            }

                        printf("\n\t Enter elements of Matrix A  %d x %d matrix\n", row_A, column_A);
            read_Matrix(matrixA, row_A, column_A);
            printf("\n\t\tMatrix A\n\n");
            print_Matrix(matrixA, row_A, column_A);
           
            printf("\n\t Enter elements of Matrix B a %d x %d matrix\n", row_B, column_B);
            read_Matrix(matrixB, row_B, column_B);
            printf("\n\t\tMatrix A\n\n");
            print_Matrix(matrixB, row_B, column_B);

            matrix_Multiply(matrixA, matrixB, row_A, column_A, column_B);

            break;

        default:
            printf("\nIncorrect option! Please choose a number 1-3.");
            break;
        }

        printf("\n\nDo you want to calculate again? Y/N\n");
        scanf(" %c", &again);
        again = toupper(again);
    }
    printf("\n\nEnd\n\n");

    return 0;
}

void read_Matrix(int array[10][10], int rows, int columns){
    int i, j;
    for (i = 0; i < rows; i++){
        printf("\t%d Entries for row %d: ", columns, i + 1);
        for (j = 0; j < columns; j++){
            scanf("%d", &array[i][j]);
        }
    }

    return;
}

void print_Matrix(int array[10][10], int rows, int columns){
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++){
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }
}

void matrix_AddSub(int array1[10][10], int array2[10][10], int rows, int columns, int multiply){
    int i, j;
    int sumM[10][10];
    int scaM[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            scaM[i][j] = multiply * array2[i][j];
            }
        }

    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            sumM[i][j] = array1[i][j] + scaM[i][j];
            printf("\t%d", sumM[i][j]);
        }
        printf("\n");
    }
}

void matrix_Multiply(int array1[10][10], int array2[10][10], int rowA, int columnA,int columnB){
    int i, j, k;
    int mulM[10][10];
    
    for (i = 0; i<rowA; ++i)
        for (j = 0; j<columnB; ++j)
        {
            mulM[i][j] = 0;
        }
    
    for (i = 0; i<rowA; ++i)
        for (j = 0; j<columnB; ++j)
            for (k = 0; k<columnA; ++k)
            {
                mulM[i][j] += array1[i][k] * array2[k][j];
            }
    printf("\nOutput Matrix:\n");
    for (i = 0; i<rowA; ++i)
        for (j = 0; j<columnB; ++j)
        {
            printf("\t%d ", mulM[i][j]);
            if (j == columnB - 1)
                printf("\n\n");
        }
}


