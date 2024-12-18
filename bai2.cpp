#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void nhapChuoi(char **str);
void inChuoi(char *str);
int demChuCai(char *str);
int demChuSo(char *str);
int demKyTuDacBiet(char *str);

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\n         MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", demChuCai(str));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", demChuSo(str));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(str));
                break;
            case 6:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);

    free(str);
    return 0;
}

void nhapChuoi(char **str) {
    char temp[1000];
    printf("Nhap chuoi: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    *str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(*str, temp);
}

void inChuoi(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
    } else {
        printf("Chuoi vua nhap: %s\n", str);
    }
}

int demChuCai(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return 0;
    }
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int demChuSo(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return 0;
    }
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int demKyTuDacBiet(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return 0;
    }
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}




