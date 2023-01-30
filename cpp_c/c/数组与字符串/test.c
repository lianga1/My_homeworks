#include <stdio.h>
#include<string.h>


int fibonacci (int a);

int main() {




printf("%d",fibonacci(6));



return 0;
}


int fibonacci (int a)
{
    if(a==1||a==2)
        return 1;
    else if(a>1)
        return fibonacci(a-1)+fibonacci(a-2);
            

}
