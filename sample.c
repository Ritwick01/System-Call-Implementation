#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#define SYS_kernel_2d_memcpy 448

int main(int argc, char **argv) {
    int row = 4;
    int column = 4;
    float matrix1[4][4] = {{9.7,.63,.78,98.0},{3.21,7.65,12.3,5.46},{8.97,65.1,65.7,1.231},{.565,.675,7.68,9.00}};
    float matrix2[4][4] = {{1.21,98.1,77.7,34},{3.44,12.34,4.51,66.6},{25.3, 4.298, 5.413, 6.56}, {6.54, 3.290, 44.31, 1.2}};

    printf("Initial matrices A and B\n");

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%lf ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%lf ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int result = syscall(SYS_kernel_2d_memcpy, matrix2, matrix1, row, column);
    if(result < 0){
        perror("ERROR Reporting.");
        exit(0);
    }

    printf("Copied Matrices A on B\n");

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%lf ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%lf ", matrix2[i][j]);
        }
        printf("\n");
    }

    return 0;
}