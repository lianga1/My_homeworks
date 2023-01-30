#include <stdio.h>

void Hanoi(int n, char X,char Y,char Z);

int main()
{
    Hanoi(5,'X','Y','Z');
    return 0;
}

void Hanoi(int n, char X,char Y,char Z)
{
    if(n==1)
        printf("\t把第%d个盘子从%c移动到%c\n",n,X,Z);
    else
    {
        Hanoi(n-1,X,Z,Y);
        printf("\t把第%d个盘子从%c移动到%c\n",n,X,Z);
        Hanoi(n-1,Y,X,Z);
    }
}