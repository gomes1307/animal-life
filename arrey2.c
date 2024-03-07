#include<stdio.h>
#include<math.h>
main()
{
    int a[5],i,sum=0;


        for(i=0;i<5;i++){
        scanf("%d",&a[i]);
    }


    for(i=0;i<5;i++){
       sum = sum + a[i];
    }
    printf("The value of Arrey = %d\n",sum);
}
