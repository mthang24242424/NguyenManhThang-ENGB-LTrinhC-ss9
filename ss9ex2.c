#include<stdio.h>
int main(){
int a,b;
	int number[3] [3] = {{1,2,3},{4,5,6},{7,8,9}};
printf("nhap vao vi tri hang ban muon sua: ");
scanf("%d",&a);
printf("nhap vao vi tri cot ban muon sua: ");
scanf("%d",&b);
printf("nhap vao gia tri ban sua: ");
scanf("%d",&number[a][b]);
	for(int i=0; i<3; i++){ // in phan tu  
	for(int j=0; j<3; j++){
		printf(" number[%d][%d] = %d \n",i,j,number[i][j]);
		} 
	}
	return 0; 
}
