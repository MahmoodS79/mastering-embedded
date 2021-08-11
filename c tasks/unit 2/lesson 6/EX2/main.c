#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Distance {
   int feet;
   float inch;
} d1, d2, result;

int main() {
   printf("Enter information for 1st distance\n");
   printf("Enter feet: ");
   fflush(stdin);fflush(stdout);
   scanf("%d", &d1.feet);
   printf("Enter inch: ");
   fflush(stdin);fflush(stdout);
   scanf("%f", &d1.inch);


   printf("Enter information for 2nd distance\n");
   printf("Enter feet: ");
   fflush(stdin);fflush(stdout);
   scanf("%d", &d2.feet);
   printf("Enter inch: ");
   fflush(stdin);fflush(stdout);
   scanf("%f", &d2.inch);


   result.feet = d1.feet + d2.feet;
   result.inch = d1.inch + d2.inch;


   while (result.inch >= 12.0) {
      result.inch = result.inch - 12.0;
      ++result.feet;
   }
   printf("Sum of distances = %d\'-%.1f\"", result.feet, result.inch);
   return 0;
}
