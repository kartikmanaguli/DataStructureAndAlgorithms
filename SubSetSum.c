#include<stdio.h>
#include<stdlib.h>
void main()
{
  int sum =0 ;
  int *set;
  int **cost;
  int number=0;
  int i,j;
 printf("Enter the number to find out subset :");
 scanf("%d",&sum);

 printf("Enter the number of elements in set :");
 scanf("%d",&number);
 set=(int *)malloc(number*sizeof(int));

 printf("Enter %d Numbers :\n",number);
 for(i=0;i<number;i++)
 scanf("%d",&set[i]);
 number++,sum++;
 cost = (int **) malloc(number*sizeof(int*));
 cost[0]=(int *) malloc(number*sum*sizeof(int));

 for(i=0;i<number;i++)
 cost[i]=cost[0]+i*sum;

 for(i=0;i<number;i++)
  cost[i][0]=1; 

 for(i=1;i<number;i++) 
 for(j=1;j<sum;j++)
   
   if(sum<set[i]) cost[i][j] = cost[i-1][j];
   else if(sum>=set[i])
    cost[i][j] = cost[i-1][j-set[i]] || cost[i-1][j];

 if(cost[number-1][sum-1]==1)
  printf("The Subset Is possible:");
 else
printf("Not Possible");

}
