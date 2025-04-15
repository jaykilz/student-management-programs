#include "students.h"
#include "Searching.h"
#include "update.h"
#include <stdio.h>
#include <string.h>

void input_string(char *str, int size);
void input_float(float *value);
void printNewData(profile *s,long ID);

void update(profile *s)
{
    char targetMSSV[20], targetNAME[100];

    // nhap mssv va ten de chinh sua
    fgets(targetMSSV, 20, stdin);
    targetMSSV[strcspn(targetMSSV, "\n")] = '\0';

    fgets(targetNAME, 100, stdin);
    targetNAME[strcspn(targetNAME, "\n")] = '\0';

    //tim kiem sinh vien
    searching(s, targetMSSV, targetNAME);
    int found = 0;

    for (int i = 0; i < 500000; i++) 
    {
        if (strcmp(s[i].MSSV, targetMSSV) == 0)
        {
            found = 1;
            // nhap thong tin moi 
            printf("\nNhập MSSV: ");
            input_string(s[i].MSSV, sizeof(s[i].MSSV));

            printf("\nNhập tên sinh viên: ");
            input_string(s[i].NAME, sizeof(s[i].NAME));

            printf("\nNhập ngày sinh: ");
            input_string(s[i].DATE, sizeof(s[i].DATE));

            printf("\nNhập số điện thoại: ");
            input_string(s[i].NUM, sizeof(s[i].NUM));

            printf("\nNhập địa chỉ: ");
            input_string(s[i].ADD, sizeof(s[i].ADD));

            printf("\nNhập lớp học: ");
            input_string(s[i].CLASS, sizeof(s[i].CLASS));

            // nhap diem so moi
            printf("\nNhập điểm môn toán: ");
            input_float(&s[i].math);

            printf("\nNhập điểm môn văn: ");
            input_float(&s[i].lit);

            printf("\nNhập điểm môn tiếng Anh: ");
            input_float(&s[i].eng);

            // tinh diem trung binh
            s[i].aver = (s[i].math + s[i].lit + s[i].eng) / 3.0;
            break;
        }
    }
    if (found = 0)
    {
        printf("\nKhông tìm thấy sinh viên");
    }

    saveNewData(s);
}

void input_string(char *str, int size) 
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void input_float(float *value) 
{
    scanf("%f", value);
    getchar();
}

void saveNewData(profile *s)
{
    FILE *f = fopen("temp.txt", "w");  // Ghi de du lieu moi 
    if (f == NULL) {
        printf("ERROR!\n");
        return;
    }

    for (int i = 0; i < 500000; i++) {
        fprintf(f, "%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                s[i].MSSV, s[i].NAME, s[i].DATE, s[i].NUM, s[i].ADD,
                s[i].CLASS, s[i].math, s[i].lit, s[i].eng, s[i].aver);
    }

    fclose(f);

    if (remove("students.txt") != 0) {
        printf("\nKhông thể xóa students.txt");
        return;
    }

    if (rename("temp.txt", "students.txt") != 0) {
        printf("\nKhông thể đổi tên temp.txt thành students.txt\n");
        return;
    }

    printf("\nDữ liệu đã được cập nhật vào students.txt thành công.\n");
}




