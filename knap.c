#include<stdio.h>
#include<stdlib.h>
#define max 100
int n,m,p[max],w[max],t[max][max],count=0;
int maximum(int a,int b)
{
    return (a>b)?a:b;
}

int knapsack(int n,int m)
{
    for(int i=0;i<n+1;i++)
    {
         for(int j=0;j<m+1;j++)
         {
            if(j==0 || i==0)
             t[i][j]=0;

             else
             {
                count++;
                if(j< w[i] )
                t[i][j]=t[i-1][j];

                else
                t[i][j]= maximum( t[i-1][j], p[i]+t[i-1][j- w[i]]);
             }
         }
    }
    return t[n][m];

}
  int  main()
  {
    printf("Enter the number of item to knapsack\n");
    scanf("%d",&n);
    printf("Enter the sack capacity\n");
    scanf("%d",&m);
   FILE *fp= fopen("knap.txt","a");

    printf("Weigth of the item\t Price fo the item\n");
    for(int i=1;i<n+1;i++)
     scanf("%d\t%d",&w[i],&p[i]);
 int res=knapsack(n,m);
    printf("The maximum Price of the knapscak is %d\n",res);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
          printf("%d ",t[i][j]);

        printf("\n");  
    } 
    printf("Composition is \n");

    for(int i=n;i>0;i--)
    {
        if(t[i][m]!=t[i-1][m])
          {
            printf("%dth element\t",i);
            m = m- w[i];
          }
    }
  printf("\nOperation count is %d\n",count);
  fprintf(fp,"%d\t%d\n",n,count);
  return 0;
  }