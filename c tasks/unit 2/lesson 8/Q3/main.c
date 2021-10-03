/*
 * main.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Sence79
 */

#include <stdio.h>
#include <stdlib.h>
#define DPRINTF(...) {fflush(stdin);fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);fflush(stdout);}
int main(){

    char* string=(char*)malloc(100);
	DPRINTF("Input a string :");
	gets(string);
	DPRINTF("Reverse of the string is : ");

	while(1){
	    string++;
		if(*string == '\0'){
			string--;
			for(int j=0;1;j++){
				if(*string == '\0' && j!=0)
					break;
					printf("%c",*(string--));

			}
		}
		if(*string == '\0')
			break;
	}
	return 0;
}
