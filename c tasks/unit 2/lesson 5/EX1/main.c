#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count=0;
int bound;
void primeinterval(int num1,int num2){


	for(int i=num1;i<=num2;i++){
		bound=ceil(sqrt(i));count=0;
		for(int j=2;j<=bound;j++){
			if(i%j==0){
				count=1;
			    break;
			}
		}
		if((count==0 && i!=1) || i==2 || i==3 )
			printf("%d ",i);

	}
}
int main()
{
	int num1,num2;
printf("Enter two numbers(intervals): ");
fflush(stdin);fflush(stdout);
scanf("%d\n%d",&num1,&num2);
printf("Prime numbers between %d and %d are: ",num1,num2);primeinterval(num1,num2);
    return 0;
}




