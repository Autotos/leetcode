


/*
       停车场有一横排车位0代表没有停车,1代表有车.
       至少停了一辆车在车位上,也至少有一个空位没有停车.
       为防止刮蹭,需为停车人找到一个车位
       使得停车人的车最近的车辆的距离是最大的
       返回此时的最大距离

       输入描述:
       1. 一个用半角逗号分割的停车标识字符串,停车标识为0或1,
        0为空位,1为已停车
       2. 停车位最多有100个

       输出描述
       1. 输出一个整数记录最大距离

       示例一:
       输入
       1,0,0,0,0,1,0,0,1,0,1

        0,0,1,1,0,0
       输出
       2

       说明
       当车停在第三个位置上时,离其最近的车距离为2(1~3)
       当车停在第四个位置上时,离其最近的车距离为2(4~6)
       其他位置距离为1
       因此最大距离为2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


int find(char *stop, int index)
{
    int pos = 0;
    int stopLen = strlen(stop);
    while (1) {
        if ((stopLen - 1 > index + pos && stop[index + pos] == '1') ||
            (0 <= index - pos && stop[index - pos] == '1')) {
            break;
        } else if (stopLen - 1 < index + pos && 0 > index - pos) {
            return -1;
        }
        pos++;
    }
    //printf("index:%d pos:%d\n", index, pos);
    return pos;
}

int main()
{
    char ch;
    char stop[100];
    int size = 0;
    int pos, max = 0;
    int i;
    while ((ch = getchar()) != '\n') {
        if (ch == '1' || ch == '0') {
            stop[size++] = ch;
        }
    }
    stop[size] = '\0';
    for (i = 0; i < size; i++) {
        if (stop[i] == '0') {
            pos = find(stop, i);
            if (pos > max) {
                max = pos;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}

