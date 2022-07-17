/*
   小明从糖果盒中随意抓一把糖果
   每次小明会取出一半的糖果分给同学们
   当糖果不能平均分配时
   小明可以从糖果盒中(假设盒中糖果足够)取出一个或放回一个糖果
   小明至少需要多少次(取出放回和平均分配均记一次)能将手中糖果分至只剩一颗

   输入描述：
     抓取糖果数(小于1000000)：15
   输出描述：
     最少分至一颗糖果的次数：5

    示例1：
      输入
        15
      输出
        5
      备注
         解释：(1) 15+1=16;
              (2) 16/2=8;
              (3) 8/2=4;
              (4) 4/2=2;
              (5) 2/2=1;

*/


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


int main()
{
    int i, count;
    int kid;
    scanf("%d", &kid);

    for (i = kid, count = 0; i != 1; i /= 2, count++) {
        if (i == 3) {
            count += 2;
            break;
        }
        if (i % 2 != 0) {
            if (((i + 1) / 2 % 2) == 0) {
                i++;
            } else {
                i--;
            }
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

