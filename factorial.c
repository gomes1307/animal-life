#include <stdio.h>

int main() {
   int m, i, t1 = 0, t2 = 1, nextTerm;

   printf("Enter the number of terms: ");
   scanf("%d", &m);

   printf("First %d terms of Fibonacci series are: ", m);

   i = 1;

   do {
       printf("%d, ", t1);
       nextTerm = t1 + t2;
       t1 = t2;
       t2 = nextTerm;
       i++;
   } while (i <= m);

   return 0;
}

