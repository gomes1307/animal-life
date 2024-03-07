#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    printf("Enter the Integer x : ");
    scanf("%d",&x);

    if(x % 2 == 0){
        printf("The number is Even");
    }else{
        printf("The number is Odd");

    }
    return 0;
}
