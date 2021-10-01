/*
 * Funcs_Heads.h
 *
 *  Created on: Sep 30, 2021
 *      Author: Sence79
 */

#ifndef FUNCS_HEADS_H_
#define FUNCS_HEADS_H_
#include "stdio.h"

#define DPRINTF(...) {fflush(stdin);fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);fflush(stdout);}

struct Sdata{
	int id;
	char name[100];
	float height;
};

typedef struct Sstudent{
	struct Sdata student;
	struct Sstudent* pnext;
}sstudent_t;

extern void addStudent();
extern int delete_Student();
extern void view_all();
extern void DeleteAll();
extern int GetNth();
extern int Count();
extern void printMiddle();
extern void reverse_list();
#endif /* FUNCS_HEADS_H_ */
