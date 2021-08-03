#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int count=0;
int power(int base,int pow){


    if(count+1==pow)
	   return base;

	    count++;
        return base*power(base,pow);


}

int main()
{
int base,pow;
printf("Enter base number: ");
fflush(stdin);fflush(stdout);
scanf("%d",&base);

printf("Enter power number(positive integer): ");
fflush(stdin);fflush(stdout);
scanf("%d",&pow);

printf("%d^%d = %d",base,pow,power(base,pow));
    return 0;
}



