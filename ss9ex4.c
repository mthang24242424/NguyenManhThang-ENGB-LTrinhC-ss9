#include <stdio.h>
#include <stdlib.h>

int main() {
    int choose, a = 0;
    int value, index;
    int check = 0; // kiem tra xem mang dc nhap chua  
    int number[100]; 
    int m, n;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap vao so phan tu trong mang: ");
                scanf("%d", &a);
                while (a <= 0 || a > 100) {
                    printf("So phan tu khong hop le. Nhap lai (1-100): ");
                    scanf("%d", &a);
                }
                check = 1; 
                for (int i = 0; i < a; i++) {
                    printf("Nhap vao phan tu thu %d cua mang: ", i + 1);
                    scanf("%d", &number[i]);
                }
                break;

            case 2:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    for (int i = 0; i < a; i++) {
                        printf("number[%d] = %d\n", i, number[i]);
                    }
                }
                break;

            case 3:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    printf("Nhap vao vi tri muon them vao (1-%d): ", a + 1);
                    scanf("%d", &index);
                    while (index < 1 || index > a + 1) {
                        printf("Vi tri khong hop le. Nhap lai (1-%d): ", a + 1);
                        scanf("%d", &index);
                    }
                    // Chen vao vi tri da nhap
                    for (int i = a; i >= index; i--) {
                        number[i] = number[i - 1];
                    }
                    number[index - 1] = value; // gan gia tri ms 
                    a++; // tang kich thuoc mang 
                }
                break;

            case 4:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    printf("Nhap vao vi tri ban muon sua (0-%d): ", a - 1);
                    scanf("%d", &n);
                    if (n >= 0 && n < a) {
                        printf("Nhap vao gia tri moi: ");
                        scanf("%d", &number[n]);
                    } else {
                        printf("Vi tri khong hop le.\n");
                    }
                }
                break;

            case 5:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    printf("Nhap vi tri can xoa (1-%d): ", a);
                    scanf("%d", &m);
                    while (m < 1 || m > a) {
                        printf("Vi tri khong hop le. Nhap lai (1-%d): ", a);
                        scanf("%d", &m);
                    }
                    for (int i = m - 1; i < a - 1; i++) {
                        number[i] = number[i + 1];
                    }
                    a--; // giam kich thuoc mang 
                    printf("Da xoa phan tu o vi tri %d.\n", m);
                }
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choose != 6);

    return 0;
}
