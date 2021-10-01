/*
 * main.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Sence79
 */


#include "Funcs_Heads.h"
extern sstudent_t* first;
int main() {
	int number;
	while(1){
		DPRINTF("\n******choose one of the following options or 0 to terminate******");
		DPRINTF("\n1: Add student ");
		DPRINTF("\n2: Delete student ");
		DPRINTF("\n3: View all students ");
		DPRINTF("\n4: Delete all ");
		DPRINTF("\n5: printing a student's data ");
		DPRINTF("\n6: counting students in a list ");
		DPRINTF("\n7: printing middle students\n");
		DPRINTF("8: print reversed list\n");
		scanf("%d",&number);
		printf("\n");
		switch(number){
		case 1:
			addStudent();
			printf("\n*************************** ");
			break;
		case 2:
			delete_Student();
			printf("\n*************************** ");
			break;
		case 3:
			view_all();
			printf("\n*************************** ");
			break;
		case 4:
			DeleteAll();
			printf("\n*************************** ");
			break;
		case 5:
			GetNth();
			printf("\n*************************** ");
			break;
		case 6:
			printf("\nthere is %d students in the list",Count(first));
			printf("\n*************************** ");
			break;
		case 7:
			printMiddle();
			printf("\n*************************** ");
			break;
		case 8:
			reverse_list();
			view_all();
			printf("\n*************************** ");
			break;
		case 0:
			printf("\n*************************** ");
			break;
		default:
			printf("\n*** ReEnter *** ");
			break ;
		}
		if(number==0)
			break;
	}
	return 0;
}
