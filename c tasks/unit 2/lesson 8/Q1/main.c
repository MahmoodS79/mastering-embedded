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

int main()
{
	int m=29;
	int*ab=NULL;
	DPRINTF("Address of m=%p\n",&m);
	DPRINTF("Value of m=%d\n",m);
	ab=&m;
	DPRINTF("Now ab is assigned with the address of m\n");
	DPRINTF("Address of pointer ab :%p\n",ab);
	DPRINTF("Content of pointer ab :%d\n",*ab);
	m=34;
	DPRINTF("The value of m assigned to 34 now\n");
	DPRINTF("Address of pointer ab :%p\n",ab);
	DPRINTF("Content of pointer ab :%d\n",*ab);
	*ab=7;
	DPRINTF("The pointer variable ab is assigned with the value 7 now\n");
	DPRINTF("Address of m=%p\n",&m);
	DPRINTF("Value of m=%d\n",m);
	return 0;
}
