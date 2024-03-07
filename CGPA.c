#include <stdio.h>

int main() {
   int numSubjects, i;
   float marks, total = 0, cgpa;

   printf("Enter the number of subjects: ");
   scanf("%d", &numSubjects);

   for (i = 1; i <= numSubjects; i++) {
       printf("Enter marks for subject %d (out of 100): ", i);
       scanf("%f", &marks);

       while (marks < 0 || marks > 100) {
           printf("Invalid marks. Please enter marks between 0 and 100: ");
           scanf("%f", &marks);
       }

       total += marks;
   }

   cgpa = total / (numSubjects * 10);

   printf("Your CGPA is: %.2f\n", cgpa);

   return 0;
}

