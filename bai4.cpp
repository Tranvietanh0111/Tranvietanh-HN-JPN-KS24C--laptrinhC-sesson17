#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void nhapMang(int **arr, int *n);
void inSoChan(int *arr, int n);
bool laSoNguyenTo(int num);
void inSoNguyenTo(int *arr, int n);
void daoNguocMang(int *arr, int n);
void sapXepMang(int *arr, int n, bool tangDan);
void timKiemPhanTu(int *arr, int n);

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        printf("\n         MENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                daoNguocMang(arr, n);
                break;
            case 5: {
                int subChoice;
                printf("\n   Sap xep mang\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Nhap lua chon cua ban: ");
                scanf("%d", &subChoice);
                sapXepMang(arr, n, subChoice == 1);
                break;
            }
            case 6:
                timKiemPhanTu(arr, n);
                break;
            case 7:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
}

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}

void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int *arr, int n) {
    printf("Mang sau khi dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepMang(int *arr, int n, bool tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void timKiemPhanTu(int *arr, int n) {
    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, i + 1);
            found = true;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", x);
    }
}



