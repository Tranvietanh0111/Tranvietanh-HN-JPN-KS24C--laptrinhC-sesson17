#include<stdio.h>
#include<stdlib.h>
void nhapmang(int **arr,int *n);
void hienmang(int *arr,int n);
int tinhdodai(int n);
int tinhtong(int *arr, int n);
int timmax(int *arr, int n);
int main(){
	int n=0;
	int *arr;
	int choice;
	do{
		printf("\n         MENU\n");
		printf("1. Nh?p vào s? ph?n t? và t?ng ph?n t?\n");
		printf("2.Hi?n th? các ph?n t? trong m?ng\n");
		printf("3.Tính d? dài m?ng\n");
		printf("4.Tính t?ng các ph?n t? trong m?ng\n");
		printf("5.Hi?n th? ph?n t? l?n nh?t\n");
		printf("6.thoat\n");
		printf("nhap lua chon cua ban:");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				nhapmang(&arr,&n);
				break;
			}
			case 2:{
				hienmang(arr,n);
			
				break;
			}
			case 3:{
				printf("do dai cua mang la %d",tinhdodai(n));
				break;
			}
			case 4:{
				printf("tong la %d",tinhtong(arr,n));
				break;
			}
			case 5:{
				printf("max la %d",timmax(arr,n));
				break;
			}
			case 6:{
				printf("thoat");
				break;
			}
		}
		
	}while ( choice !=6);
    free(arr);
	return 0;
}
void nhapmang(int **arr,int *n){
	printf("\nnhap so phan tu:");
	scanf("%d",n);
	*arr=(int*)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		printf("\nnhap phan tu thu %d:",i+1);
		scanf("%d", &(*arr)[i]);
	}
}
void hienmang(int *arr,int n){
	printf("\ncac phan tu trong mang la:\n ");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}
int tinhdodai(int n) {
    return n;
}
int tinhtong(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int timmax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


