#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ktra so nguyen to  
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int choose, a = 0;
    int number[100]; 
    int check = 0;   // kiem tra xem mang dc nhap chua 
    int value, index, count = 0, total = 0;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat\n");
        printf("5. In ra cac phan tu la so nguyen to va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke so phan tu do trong mang\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap so phan tu trong mang (toi da 100): ");
                scanf("%d", &a);
                while (a <= 0 || a > 100) {
                    printf("So phan tu khong hop le. Nhap lai (1-100): ");
                    scanf("%d", &a);
                }
                check = 1;
                for (int i = 0; i < a; i++) {
                    printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
                    scanf("%d", &number[i]);
                }
                break;

            case 2:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    printf("Cac phan tu trong mang la: ");
                    for (int i = 0; i < a; i++) {
                        printf("%d ", number[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    total = 0;
                    printf("Cac phan tu chan trong mang: ");
                    for (int i = 0; i < a; i++) {
                        if (number[i] % 2 == 0) {
                            printf("%d ", number[i]);
                            total += number[i];
                        }
                    }
                    printf("\nTong cac phan tu chan: %d\n", total);
                }
                break;

            case 4:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    int max = number[0], min = number[0];
                    for (int i = 1; i < a; i++) {
                        if (number[i] > max) max = number[i];
                        if (number[i] < min) min = number[i];
                    }
                    printf("Gia tri lon nhat: %d\n", max);
                    printf("Gia tri nho nhat: %d\n", min);
                }
                break;

            case 5:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    total = 0;
                    printf("Cac phan tu la so nguyen to: ");
                    for (int i = 0; i < a; i++) {
                        if (isPrime(number[i])) {
                            printf("%d ", number[i]);
                            total += number[i];
                        }
                    }
                    printf("\nTong cac so nguyen to: %d\n", total);
                }
                break;

            case 6:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    printf("Nhap mot so can thong ke: ");
                    scanf("%d", &value);
                    count = 0;
                    for (int i = 0; i < a; i++) {
                        if (number[i] == value) {
                            count++;
                        }
                    }
                    printf("So phan tu co gia tri %d trong mang: %d\n", value, count);
                }
                break;

            case 7:
                if (check == 0) {
                    printf("Mang chua duoc nhap.\n");
                } else {
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri muon them vao (1-%d): ", a + 1);
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
                    a++; // tang kich thuoc mang len 1 
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
