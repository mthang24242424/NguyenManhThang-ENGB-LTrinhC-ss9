#include <stdio.h>
#include <stdlib.h>

// ham tinh tong  
int sumRow(int matrix[][100], int row, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += matrix[row][j];
    }
    return sum;
}

int main() {
    int matrix[100][100];
    int rows = 0, cols = 0;
    int choose, check = 0;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua ma tran\n");
        printf("2. In gia tri cac phan tu cua ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In cac phan tu nam tren duong cheo chinh\n");
        printf("6. In cac phan tu nam tren duong cheo phu\n");
        printf("7. In dong co tong gia tri cac phan tu lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap so dong: ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);

                while (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
                    printf("Kich co khong hop le. Nhap lai (1-100):\n");
                    printf("So dong: ");
                    scanf("%d", &rows);
                    printf("So cot: ");
                    scanf("%d", &cols);
                }

                printf("Nhap cac phan tu cua ma tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Phan tu [%d][%d]: ", i + 1, j + 1);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                check = 1;
                break;

            case 2:
                if (!check) {
                    printf("Ma tran chua duoc nhap.\n");
                } else {
                    printf("Ma tran la:\n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            printf("%d ", matrix[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 3:
                if (!check) {
                    printf("Ma tran chua duoc nhap.\n");
                } else {
                    int sumOdd = 0;
                    printf("Cac phan tu le trong ma tran: ");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            if (matrix[i][j] % 2 != 0) {
                                printf("%d ", matrix[i][j]);
                                sumOdd += matrix[i][j];
                            }
                        }
                    }
                    printf("\nTong cac phan tu le: %d\n", sumOdd);
                }
                break;

            case 4:
                if (!check) {
                    printf("Ma tran chua duoc nhap.\n");
                } else {
                    long long product = 1;
                    printf("Cac phan tu nam tren duong bien: ");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                                printf("%d ", matrix[i][j]);
                                product *= matrix[i][j];
                            }
                        }
                    }
                    printf("\nTich cac phan tu tren duong bien: %lld\n", product);
                }
                break;

            case 5:
                if (!check) {
                    printf("Ma tran chua duoc nhap.\n");
                } else {
                    printf("Cac phan tu tren duong cheo chinh: ");
                    for (int i = 0; i < rows && i < cols; i++) {
                        printf("%d ", matrix[i][i]);
                    }
                    printf("\n");
                }
                break;

            case 6:
                if (!check) {
                    printf("Ma tran chua duoc nhap.\n");
                } else {
                    printf("Cac phan tu tren duong cheo phu: ");
                    for (int i = 0; i < rows && i < cols; i++) {
                        printf("%d ", matrix[i][cols - 1 - i]);
                    }
                    printf("\n");
                }
                break;

            case 7:
                if (!check) {
                    printf("Ma tran chua duoc nhap.\n");
                } else {
                    int maxSum = sumRow(matrix, 0, cols);
                    int maxRow = 0;
                    for (int i = 1; i < rows; i++) {
                        int currentSum = sumRow(matrix, i, cols);
                        if (currentSum > maxSum) {
                            maxSum = currentSum;
                            maxRow = i;
                        }
                    }
                    printf("Dong co tong gia tri lon nhat la dong %d (tong = %d):\n", maxRow + 1, maxSum);
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", matrix[maxRow][j]);
                    }
                    printf("\n");
                }
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Hay nhap lai.\n");
        }
    } while (choose != 8);

    return 0;
}
