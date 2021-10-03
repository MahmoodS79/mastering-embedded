
#include <stdio.h>
#include <stdlib.h>
#define DPRINTF(...) {fflush(stdin);fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);fflush(stdout);}

int main()
{
	DPRINTF("The alphabets are:\n");


    int i=65;
    int *p=(&i);

    for  (i=65;i<=91;i++)
    {
    	if (i==65){
    		DPRINTF("%c ",(*p));}
    	else{
    		DPRINTF("%c ",--(*p));
    	}
    	*p=*p+1;  //after enter for loop p increments by one 

    }

    return 0;
}
