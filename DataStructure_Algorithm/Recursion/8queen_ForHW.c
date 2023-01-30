#include <stdio.h>
#define N 8

int queen[N];
int count=0;
int tree; 
void Queen(int i);
int isOK(int a[],int n,int c);

int main()
{

    scanf("%d",&tree);
    Queen(0);
    printf("%d",count);
    return 0;
}

void Queen (int row){
    if(row==N)
    {
        count++;
        // for(int x=0;x<N;x++)
        //     printf("%d ",queen[x]);
        // printf("\n");
        return ;
    }
    for(int column=0;column<N;column++){
        if(isOK(queen,row,column)){
            queen[row]=column;
            Queen(row+1);
        }

    }
}
int isOK(int current[],int row,int column)//current for a storage for position of each row;row for the current row;columnfor current column
{
    if(row==tree && column==0)
        return 0;
    for(int i=0;i<row;i++)
    {
        if((column!=0 && current[i]==column)||current[i]-i==column-row||current[i]+i==column+row||(column==0 && !(tree>i && tree <row)&&(current[i]==column))||(row==tree && column==0))
            return 0;
    }
    return 1;
}