#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct student {

	char name[20];
	int roll;
	float marks;


};

int main()
{
	struct student a;
	printf("Enter information of students:\n");
    printf("Enter name: ");
    fflush(stdin);fflush(stdout);
    gets(a.name);
    printf("Enter roll number: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&a.roll);
    printf("Enter marks: ");
    fflush(stdin);fflush(stdout);
    scanf("%f",&a.marks);

    printf("Displaying Information\nname: %s\nRoll: %d\nMarks: %f",a.name,a.roll,a.marks);

    return 0;
}
