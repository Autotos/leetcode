/*
            输入一个字符串仅包含大小写字母和数字
            求字符串中包含的最长的非严格递增连续数字序列长度
            比如：
                12234属于非严格递增数字序列
            示例：
            输入
                abc2234019A334bc
            输出
                4
            说明：
                2234为最长的非严格递增连续数字序列，所以长度为4

                aaaaaa44ko543j123j7345677781
                aaaaa34567778a44ko543j123j71
                345678a44ko543j123j7134567778aa
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


int isSort(char *arr, char ch, int *flag)
{
    int i;
    for (i = 0; arr[i] != '\0'; i++) {
        if (arr[i] > ch) {
            return -1;
        }
        if (arr[i] == ch) {
            *flag = 1; // 0: 严格递增，1: 非严格递增
        }
    }
    return 0;
}

int main()
{   char ch;
    int i, j, maxLen, flag;
    char tmp[1000] = {'\0'};
    char str[1000] = {'\0'};
    scanf("%s", str);

    i = 0;
    j = 0;
    maxLen = 0;
    while ((ch = str[i]) != '\0') {
        i++;
        if ('0' > ch || ch > '9') {
            continue;
        }
        printf("tmp:%s\n", tmp);
        if (isSort(tmp, ch, &flag) == 0) {
            tmp[j] = ch;
            j++;
        } else {
            i--;
            tmp[j] = '\0';
            if (flag == 1) {
                flag = 0;
                maxLen = maxLen < strlen(tmp) ? strlen(tmp) : maxLen;
            }
            j = 0;
            memset(tmp, '\0', 1000);
        }
    }
    printf("%d\n", maxLen);
    return 0;
}

