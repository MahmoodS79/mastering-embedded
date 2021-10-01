#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "Funcs_Heads.h"

sstudent_t* first = NULL;

void addStudent(){
	sstudent_t* last=first;
	sstudent_t* new=(sstudent_t*)malloc(sizeof(sstudent_t));;
	if(first== NULL)
		first=new;
	else{
		while(last->pnext)
			last=last->pnext;
		last->pnext=new;
	}

	DPRINTF("Enter student ID:");
	scanf("%d",&new->student.id);
	DPRINTF("\nEnter student name:");
	gets(new->student.name);
	DPRINTF("\nEnter student height:");
	scanf("%f",&new->student.height);
	new->pnext=NULL;

}
int delete_Student(){
	sstudent_t* current=first;
	sstudent_t* prev=NULL;
	int id;
	if(first==NULL){
		DPRINTF("This list is empty\n");
	     return 0;
	}
	DPRINTF("Enter ID to be deleted: ");
	scanf("%d",&id);


	while(current){
		if(current->student.id==id){
			if(prev==NULL) { //at the start
				prev=current->pnext;
				first=prev;
			}
			else
				first=current->pnext;
			free(current);
			DPRINTF("student deleted\n");
			return 1;
		}
		else{
			prev=current;
			current=current->pnext;
		}

	}
	printf("such ID deosn't exist");
	return 0;
}


void view_all(){
	sstudent_t* current=first;
	int count=1;
	if(current){
		while(current){
			DPRINTF("record number %d\n",count++);
			DPRINTF("Student name: %s\n",current->student.name);
			DPRINTF("Student ID: %d\n",current->student.id);
			DPRINTF("Student height: %f\n",current->student.height);
			DPRINTF("---------------------\n");
			current=current->pnext;
		} }
	else
		DPRINTF("This list is empty");
}

void DeleteAll(){
	sstudent_t* current=first;
	sstudent_t* temp=current;
	while(current){
		free(temp);
		current=current->pnext;
	}
	first=NULL;
}

int GetNth()
{   sstudent_t* current = first;
int count = 1;
if(current == NULL){
	printf("Empty List");
	return 0;
}

int index=0;
DPRINTF("\nEnter student's record\n");
scanf("%d",&index);


while (current != NULL) {
	if (count == index){
		DPRINTF("record number %d\n",count++);
		DPRINTF("Student name: %s\n",current->student.name);
		DPRINTF("Student ID: %d\n",current->student.id);
		DPRINTF("Student height: %f\n",current->student.height);
		DPRINTF("---------------------\n");
		return 1;
	}
	count++;
	current = current->pnext;
}
printf("No such index");
return 0;

}
int Count(sstudent_t* first_)
{
	if(first_ ==NULL){
		printf("Empty List");
		return 0;
	}
	if (first_->pnext == NULL)
		return 1;

	else
		return 1 + Count(first->pnext);

}

void printMiddle()
{
	sstudent_t *slow_ptr = first;
	sstudent_t *fast_ptr = first;

	if (first!=NULL)
	{
		while (fast_ptr != NULL && fast_ptr->pnext != NULL)
		{
			fast_ptr = (fast_ptr->pnext);
			slow_ptr = slow_ptr->pnext;
			fast_ptr = (fast_ptr->pnext);
		}
		printf("The middle student is %s \n", slow_ptr->student.name);
	}
	else
		printf("Empty List");
}

void reverse_list(){

	sstudent_t *current=first;
	sstudent_t *dynamic_p=first;
	sstudent_t *prev=first;

	prev=first->pnext;
	while(first->pnext){
		current=prev->pnext;
        if(prev!=NULL){
		prev->pnext=dynamic_p;
		dynamic_p=prev;
        }

		if(current==(sstudent_t *)NULL){
			if(first->pnext!=NULL)
				first->pnext=NULL;
			first=prev;
			break;
		}
		prev=current;
	}
}
