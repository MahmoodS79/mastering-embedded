#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



#define Area(r) 3.14*r*r

int main()
{
        float r;

        printf("Enter the radius: ");
        scanf("%f", &r);



        printf("Area = %.2f\n", Area(r));

        return 0;
    }
