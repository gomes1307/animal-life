#include <stdio.h>
int main()
{
    float celsius,fehrenheit;

    printf("enter the temperature in celsius: ");
    scanf("%f", &celsius);

    fehrenheit = (celsius * 9/5) + 32;

    printf("%.2f celsius is equal to %.2f fehrenheit",celsius,fehrenheit);
    return 0;
}
