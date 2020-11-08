#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int n;//自然数的个数
int r;
int* com;//存放一个生成的组合用于输出

void backtrack(int k);
void output();

int main(int argc, char** argv)
{
    printf("请输入自然数的个数n和组合个数r\n");
    scanf("%d%d", &n, &r);
    if (r > n)
    {
        printf("输入数据错误!");
        return 0;
    }
    com = (int*)malloc(r * sizeof(int));
    com[0] = 1;//组合数是从1开始的 
    backtrack(0);
    return 1;
}

void backtrack(int k)
{
    int i = 0;
    int j = 0;
    if (k >= r)
    {
        output();//到达叶节点输出结果
        return;
    }
    else {
        for (j = 1; j < n - com[k] + 2; j++)//遍历一个节点下的所有节点
        {
            com[k + 1] = com[k] + j;
            backtrack(k + 1);//前进 ，递归
            com[k]++;
            backtrack(k);//回溯
        }

    }
}

void output()
{
    int i = 0;
    for (i = 0; i < r; i++)
    {
        printf("%d  ", com[i]);
    }
    printf("\n");
}