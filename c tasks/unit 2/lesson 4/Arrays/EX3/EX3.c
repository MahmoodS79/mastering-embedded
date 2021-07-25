

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float a[20][20];
int main()
{
   int ro,co;float temp;
   printf("Enter rows and column of matrix: ");
   fflush(stdin);fflush(stdout);
   scanf("%d\n%d",&ro,&co);

   printf("Enter elements of matrix:\n");

   for(int i=0;i<ro;i++){
    for(int j=0;j<co;j++){
        printf("Enter elements a%d%d: ",i+1,j+1);
        fflush(stdin);fflush(stdout);
        scanf("%f",&a[i][j]);
    }
   }
   printf("Entered Matrix:\n");
   for(int i=0;i<ro;i++){
      for(int j=0;j<co;j++){
        printf("%f ",a[i][j]);
        }
        printf("\n");
   }
   for(int i=0;i<co-1;i++){
    for(int j=0;j<ro+abs(co-ro);j++)
{
    if(i>0 && j==0)
    j=j+i;
    temp=a[j][i];
    a[j][i]=a[i][j];
    a[i][j]=temp;

}
   }

   printf("Transpose of Matrix: \n");
   for(int i=0;i<co;i++){
      for(int j=0;j<ro;j++){
        printf("%f ",a[i][j]);
        }
        printf("\n");
   }
    return 0;
}

