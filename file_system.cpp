#include "io.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char s[L][B];
void init() {
    FILE *fp = fopen("ldisk.txt", "w+");
    memset(s, 0, sizeof(s));
    for (int i = 0; i < 8; i++) s[0][i] = 0xff;
    for (int i = 1; i < L; i++)
        for (int j = 0; j < B; j++)
            if (!(i == 1 && j < 4))
                s[i][j] = 0xff;
    for (int i = 0; i < L; i++)
        fwrite(s[i], sizeof(char), B, fp);
    fclose(fp);
}

char str[MAXN];
int main() {
    init();
    read_file();
    char name[28];
    int m, len, res;
    while (1) {
        printf("功能列表：\n");
        printf("    1.  创建文件        \n");
        printf("    2.  删除文件        \n");
        printf("    3.  打开文件        \n");
        printf("    4.  关闭文件        \n");
        printf("    5.  读文件          \n");
        printf("    6.  写文件          \n");
        printf("    7.  移动读写指针    \n");
        printf("    8.  显示所有文件    \n");
        printf("    9.  显示打开文件    \n");
        printf("    0.  退出            \n");
        printf("\n");
        printf("请选择操作：");
        int n;
        scanf("%d", &n);
        switch (n) {
            case 0:
                write_file();
                return 0;
            case 1:     //创建文件
                printf("请输入文件名：");
                scanf("%s", name);
                res = create(name);
                if (res >= 0) printf("文件描述符序号：%d\n", res);
                else printf("创建文件失败！\n");
                break;
            case 2:     //删除文件
                printf("请输入文件名：");
                scanf("%s", name);
                res = destory(name);
                if (res == 1) printf("删除成功！\n");
                else printf("不存在此文件\n");
                break;
            case 3:     //打开文件
                printf("请输入文件名：");
                scanf("%s", name);
                res = open(name);
                if (res >= 0) printf("文件描述符序号：%d\n", res);
                else printf("不存在此文件！\n");
                break;
            case 4:     //关闭文件
                printf("请输入文件索引号：");
                scanf("%d", &m);
                res = close(m);
                if (res >= 0) printf("文件已关闭！\n");
                else printf("不存在此文件或文件未打开！\n");
                break;
            case 5:     //读文件
                printf("请输入文件索引号：");
                scanf("%d", &m);
                printf("请输入长度：");
                scanf("%d", &len);
                str[0] = '\0';
                res = read(m, str, len);
                if (res == 1) printf("文件内容：%s\n", str);
                else printf("不存在此文件或文件未打开！\n");
                break;
            case 6:     //写文件
                printf("请输入文件索引号：");
                scanf("%d", &m);
                printf("请输入写入内容：");
                scanf("%s", str);
                printf("请输入长度：");
                scanf("%d", &len);
                res = write(m, str, len);
                if (res == 1) printf("写入成功！\n");
                else if (res == -2) printf("超出文件最大内存！\n");
                else printf("不存在此文件或文件未打开！\n");
                break;
            case 7:     //移动文件指针
                printf("请输入文件索引号：");
                scanf("%d", &m);
                printf("请输入移动位置：");
                scanf("%d", &len);
                res = lseek(m, len);
                if (res == 1) printf("设置成功！\n");
                else if (res == 0) printf("不存在此文件或文件未打开！\n");
                else printf("移动位置非法！\n");
                break;
            case 8:     //显示所有文件
                res = directory();
                break;
            case 9:     //显示打开文件
                res = directory_open();
                break;
        }
    }
    return 0;
}
