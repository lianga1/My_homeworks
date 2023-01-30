#include <stdio.h>
#define N 8

int queen[N];
int count=0;
void Queen(int i);
int isOK(int a[],int n,int c);

int main()
{
    Queen(0);
    printf("%d",count);
    return 0;
}

void Queen (int row){
    if(row==N)
    {
        count++;
        for(int x=0;x<N;x++)
            printf("%d ",queen[x]);
        printf("\n");
        return ;
    }
    for(int column=0;column<N;column++){
        if(isOK(queen,row,column)){
            queen[row]=column;
            Queen(row+1);
        }

    }
}
int isOK(int current[],int row,int column)
{
    for(int i=0;i<row;i++)
    {
        if(current[i]==column||current[i]-i==column-row||current[i]+i==column+row)
            return 0;
    }
    return 1;
}