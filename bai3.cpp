#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void nhapChuoi(char **str);
void inChuoiDaoNguoc(char *str);
int demSoTu(char *str);
void soSanhChuoi(char *str);
void inHoaChuCai(char *str);
void themChuoi(char **str);

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\n         MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoiDaoNguoc(str);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", demSoTu(str));
                break;
            case 4:
                soSanhChuoi(str);
                break;
            case 5:
                inHoaChuCai(str);
                break;
            case 6:
                themChuoi(&str);
                break;
            case 7:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    free(str);
    return 0;
}

void nhapChuoi(char **str) {
    char temp[1000];
    printf("Nhap chuoi: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    *str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
}

void inChuoiDaoNguoc(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return;
    }
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int demSoTu(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return 0;
    }
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void soSanhChuoi(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return;
    }
    char temp[1000];
    printf("Nhap chuoi khac: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    int len1 = strlen(str);
    int len2 = strlen(temp);

    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaChuCai(char *str) {
    if (str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return;
    }
    printf("Chuoi in hoa: ");
    while (*str) {
        printf("%c", toupper(*str));
        str++;
    }
    printf("\n");
}

void themChuoi(char **str) {
    if (*str == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return;
    }
    char temp[1000];
    printf("Nhap chuoi khac: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    *str = (char *)realloc(*str, (strlen(*str) + strlen(temp) + 1) * sizeof(char));
    strcat(*str, temp);
}




