#include<stdio.h>
int main(){
	int number[100];
	int n,m;
	printf("nhap so phan tu muon them vao mang: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("nhap phan tu thu %d cua mang: ",i+1);
		scanf("%d",&number[i]);
	}
	printf("nhap vi tri can xoa: ");
	scanf("%d",&m);
	while(m>n){
		printf("nhap lai vi tri can xoa: ");
		scanf("%d",&m);
	}
	for (int i = m - 1; i < n - 1; i++) {
        number[i] = number[i + 1];
    }
    n--;
    printf("mang sau khi xoa phan tu %d:\n", m);
    for (int i = 0; i < n; i++) {
        printf("%d ", number[i]);
    }
    printf("\n");
	return 0;
}
