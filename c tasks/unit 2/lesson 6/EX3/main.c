#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <stdio.h>

struct complex
{
   float real, img;
};

int main()
{
   struct complex a, b, c;

   printf("Enter real and imaginary respectively: ");
   fflush(stdin);fflush(stdout);
   scanf("%f\n%f", &a.real, &a.img);
   printf("Enter real and imaginary respectively: ");
   fflush(stdin);fflush(stdout);
   scanf("%f\n%f", &b.real, &b.img);

   c.real = a.real + b.real;
   c.img = a.img + b.img;

   printf("Sum = %.1f + (%.1fi)\n", c.real, c.img);

   return 0;
}
