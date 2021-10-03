
#include <stdio.h>
#include <stdlib.h>
#define DPRINTF(...) {fflush(stdin);fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);fflush(stdout);}
int main(){


	int i,n,arr[15],*p=arr;
    DPRINTF("Input the number of elements to store in arrays: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        DPRINTF("element - %d:",i+1);
        scanf("%d",&arr[i]);
    }
    p=p+n-1;
    DPRINTF("The elements in reverse order: \n");
       for(i=n-1;i>=0;i--)
       {
    	   DPRINTF("element - %d:",i+1);
    	   DPRINTF("%d \n",*(p));
            p--;
       }
}
