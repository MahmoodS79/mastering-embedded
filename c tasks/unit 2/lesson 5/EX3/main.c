#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int count=0;
int bound;
void stringreverse(char * str){

	if (strlen(str)==1)
		printf( "%c",*str);


	else {
        stringreverse(str+1);
        printf( "%c",*str);
}

}

int main()
{
	char string[20];
printf("Enter a sentence: ");
fflush(stdin);fflush(stdout);
gets(string);
stringreverse(string);
    return 0;
}


