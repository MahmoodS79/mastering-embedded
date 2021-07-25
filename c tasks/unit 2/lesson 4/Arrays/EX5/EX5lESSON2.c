#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float a[20];
int main()
{
   int x;float nums;
    printf("Enter no of elements: ");
   fflush(stdin);fflush(stdout);
   scanf("%d",&x);
   for(int i=0;i<x;i++)
    scanf("%f",&a[i]);

   printf("Enter the elements to be searched: ");
   fflush(stdin);fflush(stdout);
   scanf("%f",&nums);

   for(int i=0;i<x;i++)
    if(a[i]==nums)
    printf("Number found at the location = %d",i+1);



    return 0;
}

