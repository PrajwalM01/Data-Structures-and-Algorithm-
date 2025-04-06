#include<stdio.h>
#include<stdio.h>
#define max 10

int dcount = 0;

void dijkstras(int n, int cost[max][max],int s,int dist[max])
{

    int cur, count=0, min, visited[max];

     ///reset the array to 0
     for(int i=0;i<n+1;i++)
      {
         visited[i]=0;
         dist[i]=cost[s][i];
      }
   
    visited[s]=1;
    dist[s]=0;

    while(count<n)
    {
           min=999;
           for(int i=0;i<n+1;i++)
           {
             if(!visited[i]&& dist[i]<min)
               {
                min=dist[i];
                 cur=i;
               }
               visited[cur]=1;
           }

           count++;

           for(int i=0;i<n+1;i++)
             {
                if( !visited[i] && dist[i] > dist[cur] + cost[cur][i])
                {   
                    
                    dist[i] = (dist[cur] + cost[cur][i]); 
                    dcount++;

                }
    }

    }
 
}
int main()
{
    int n, cost[max][max],dist[max],s;

     printf("Enter the number of nodes of a gragh\n");
     scanf("%d",&n);

     printf("Enter the cost matrix\n");
      for(int i=0;i<n+1;i++)
       {
          for(int j=0;j<n+1;j++)
            {
                 scanf("%d",&cost[i][j]);

                 if(cost[i][j]==0)
                  cost[i][j]=999;

            }
       }

       //read source vertex

    printf("Enter the source vertex u want to find\n");
    scanf("%d",&s);

    dijkstras(n,cost,s,dist);

    printf("Shortes path is \n");
     for(int i=0;i<n+1;i++)
         {
            if(s!=i)
            {
                printf("%d --> %d = %d",s,i,dist[i]);
            }
         }

           printf(" Basic count %d\n", dcount);

         return 0;

}