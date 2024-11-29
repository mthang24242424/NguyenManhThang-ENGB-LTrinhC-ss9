#include<stdio.h>
int main(){
	int number[100];
	int n,value,index;
	printf("nhap so phan tu muon them vao mang: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("nhap phan tu thu %d cua mang: ",i+1);
		scanf("%d",&number[i]);
	}
	printf("nhap gia tri can them: ");
    scanf("%d", &value);
    printf("nhap vao vi tri muon them vao (1-%d): ", n + 1);
    scanf("%d", &index);
    while (index < 1 || index > n + 1) {
        printf("ko co vi tri nay trong mang hay nhap trong khoang (1-%d): ", n + 1);
        scanf("%d", &index);
    }
// chen vao vi tri da nhap
    for (int i = n; i >= index; i--) {
        number[i] = number[i - 1];
    }
    number[index - 1] = value; // gan gia tri ms nhap vao vi tri can chen
    n++; // Tang kich thuoc mang
    // in mang sau khi chen
    printf("mang sau khi them gia tri:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", number[i]);
    }
    printf("\n");
return 0;
}
