/* --------------------------------------------------------------------------------------------------------------------------
    THE LONGEST COMMON SUBSEQUENT ALGORITM (MEMORY EFFICIENT) USING DYNAMIC PROGRAMMING APPROACH (BOTTOM-UP APPROACH)
    AUTHOR : KARTIK MANGULI, SOFTWARE DEVELOPER WIPRO LTD.
    -------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
int max(int variable1, int variable2) {  return (variable1<variable2?variable2:variable1);}
void main()
{
   char *x,*y;
   int **c;
   int n,m,i,j;
   printf("Enter The Size Of String A\n");
   scanf("%d",&n);
   x=(char*) malloc(n*sizeof(char));
   printf("Enter The String A:\n");
   scanf("%s",x);
  printf("Enter The Size Of String B\n");
   scanf("%d",&m);
   y=(char*) malloc(m*sizeof(char));
   printf("Enter The String B\n");
   scanf("%s",y);
   m++,n++;
   c = (int **)malloc(m*sizeof(int*));
   c[0] = (int *) malloc(m*n*sizeof(int)) ;
  for(i=0;i<=m;i++)
  c[i]=c[0]+i*n;

  for(i=1;i<m;i++)
  {
   for(j=1;j<n;j++)
    {
      if(y[i-1]==x[j-1])
       c[i][j] = 1+c[i-1][j-1];
      else
       c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
  }

  printf("The Longest Common Sub Sequence is :%d",c[m-1][n-1]);
}
