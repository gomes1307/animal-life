#include <stdio.h>
#include <math.h>

int main() {
    double D, S, H, EOQ;


    printf("Enter the annual demand (D): ");
    scanf("%lf", &D);

    printf("Enter the ordering cost per order (S): ");
    scanf("%lf", &S);

    printf("Enter the holding cost per unit per year (H): ");
    scanf("%lf", &H);

    EOQ = sqrt((2 * D * S) / H);

    printf("The Economic Order Quantity (EOQ) is: %.2lf\n", EOQ);

    return 0;
}
