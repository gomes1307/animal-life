#include<stdio.h>
#include<math.h>
main()
{
    int a[4]= {80,-88,400,44};
    int max = a[0],i;

        for(i=0;i<4;i++){
                if(a[i]>max)
                max = a[i];

    }
    printf("Max value is = %d\n",max);
}
