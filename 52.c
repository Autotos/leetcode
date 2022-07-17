/*
   磁盘的容量单位有M,G,T这三个等级
   他们之间的换算关系为
   1T=1024G
   1G=1024M
   现在给定N块磁盘的容量
     请对他们按从小到大的顺序进行稳定排序
     例如给定5块盘容量
     1T,20M,3G,10G6T,3M12G9M
   排序后的结果为20M,3G,3M12G9M,1T,10G6T

   注意单位可以重复出现
   上述3M12G9M为 3M+12G+9M和 12M12G相等

   输入描述:
   输入第一行包含一个整数N
   2<=N<=100 ,表示磁盘的个数
   接下来的N行每行一个字符串 长度 (2<l<30)
   表示磁盘的容量
   有一个或多个格式为 mv的子串组成
   其中m表示容量大小 v表示容量单位
   例如

   磁盘容量m的范围 1~1024正整数
   容量单位v的范围包含题目中提到的M,G,T

   输出描述:
    输出N行
    表示N块磁盘容量排序后的结果

    示例1:
    输入
        3
        1G
        2G
        1024M

    输出
       1G
       1024M
       2G

   说明 1G和1024M容量相等,稳定排序要求保留他们原来的相对位置
   故1G在1024M前

    示例二:
    输入
         3
         2G4M
         3M2G
         1T

     输出
       3M2G
       2G4M
       1T
       说明1T大于2G4M大于3M2G

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


struct disk_s {
    int size_m;
    int index;
    char *str;
};


int change2m(char *str)
{
    int i = 0, j = 0;
    int res = 0;
    char m[5] = {'\0'};
    char v;
    for(;str[i] != '\0'; i++) {
        switch (str[i]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            m[j++] = str[i];
            break;
        case 'M':
            m[j] = '\0';
            j = 0;
            if (strlen(m) <= 0) {
                return -1;
            }
            res += atoi(m);
            break;
        case 'G':
            m[j] = '\0';
            j = 0;
            if (strlen(m) <= 0) {
                return -1;
            }
            res += atoi(m) * 1024;
            break;
        case 'T':
            m[j] = '\0';
            j = 0;
            if (strlen(m) <= 0) {
                return -1;
            }
            res += atoi(m) * 1024 * 1024;
            break;
        default:
            return -1;
        }
    }
    return res;
}

void insert(struct disk_s *head, char *str, int index)
{
    head[index].size_m = change2m(str);
    head[index].index = index;
    head[index].str = str;
}

int cmp(const void *a, const void *b)
{
    struct disk_s v1 = *((struct disk_s *)(a));
    struct disk_s v2 = *((struct disk_s *)(b));
    //printf("%x%s\n", v1, v1.str);
    //printf("%x%s\n", v2, v2.str);
    return (v1.size_m + v1.index) - (v2.size_m + v2.index);
}

int main()
{
    int i;
    int n;
    int headSize;
    char disk[100][30];
    struct disk_s *head = NULL;
    
    scanf("%d", &n);
    headSize = sizeof(struct disk_s) * n;
    head = malloc(headSize);
    i = 0;
    while (i < n) {
        scanf("%s", &disk[i++]);
    }

    for (i = 0; i < n; i++) {
        //printf("%s\n", disk[i]);
        insert(head, disk[i], i);
    }
    qsort(head, n, sizeof(head[0]), cmp);
    for (i = 0; i < n; i++) {
        printf("%s\n", head[i].str);
    }
    
    return 0;
}

