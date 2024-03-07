
 #include<stdio.h>
#include<conio.h>
void main()
{
 int a,b,c,d,m,n,Dr;

 float x1,x2;

 printf("Enter the value of a, b, c, d, m, n: ");
 scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&m,&n);

 Dr=(a*d-c*b);
 if(Dr!=0)
 {
 x1=(m*d-b*n)/Dr;
 x2=(n*a-m*c)/Dr;
 printf("\n The value of x1= %f \n The value of x2= %f",x1,x2);
 }
 else
printf("The division is not possible and result is an abrupt value ");
}
