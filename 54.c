/*
    输入一个英文文章片段
    翻转指定区间的单词顺序，标点符号和普通字母一样处理
    例如输入字符串 "I am a developer."
     区间[0,3]则输出 "developer. a am I"

     输入描述：
     使用换行隔开三个参数
     第一个参数为英文文章内容即英文字符串
     第二个参数为反转起始单词下标，下标从0开始
     第三个参数为结束单词下标，

     输出描述
     反转后的英文文章片段，所有单词之间以一个半角空格分割进行输出

     示例一：
     输入
         I am a developer.
         1
         2
     输出
         I a am developer.

     示例二：
     输入
         Hello world!
         0
         1
     输出
         world! Hello

       说明：
       输入字符串可以在前面或者后面包含多余的空格，
       但是反转后的不能包含多余空格

     示例三：
     输入：
         I am a developer.
         0
         3
     输出
         developer. a am I

       说明：
       如果两个单词见有多余的空格
       将反转后单词间的空格减少到只含一个

      示例四：
      输入
       Hello!
       0
       3
      输出
       EMPTY

       说明：
       指定反转区间只有一个单词，或无有效单词则统一输出EMPTY
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


#define WORDS_MAX 100

char **split(char *text, char *delim, int *size)
{
    char **res = NULL;
    
    *size = 0;
    res = malloc(sizeof(char *) * WORDS_MAX);
    res[*size] = strtok(text, delim);
    while (res[*size] != NULL && ++(*size)) {
        res[*size] = strtok(NULL, delim);
    }
    return res;
}

int main()
{
    char **words = NULL;
    char *tmp = NULL;
    int wordSize;
    int i, start, end;
    char text[10000];
    scanf("%[^\n]", text);
    scanf("%d", &start);
    scanf("%d", &end);
    if (end <= start) {
        printf("EMPTY\n");
        return 0;
    }

    words = split(text, " ", &wordSize);
//    for (i = 0; i < wordSize; i++) {
//        printf("%s ", words[i]);
//    }
    printf("\n");
    if (wordSize - start <= 1) {
        printf("EMPTY\n");
        return 0;
    }
    if (end >= wordSize) {
        end = wordSize - 1;
    }

    while (start < end) {
        tmp = words[start];
        words[start] = words[end];
        words[end] = tmp;
        start++;
        end--;
    }
    for (i = 0; i < wordSize; i++) {
        printf("%s", words[i]);
        if (i < wordSize - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

